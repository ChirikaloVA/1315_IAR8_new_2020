

#include "configHW.h"

extern unsigned char inv_temp;
extern unsigned int TestTemp;


void MemConfSet(void)
{
  MEMMAP = 1;  //1-to ROM-flash, 2-to ram-ozy;
  MAMCR_bit.MODECTRL = 0;  //разрешим полное использование MAM
  MAMTIM_bit.CYCLES = 3; //3 цикла ожидания при выборке из флеш
  MAMCR_bit.MODECTRL = 2;  //разрешим полное использование MAM
  
}

void PLLandClockConfSet(void)
{
  //---------20.04.2012-------------------------------------
  PLLCFG =  0x00000003;   //ускорение в 4 раза М=3+1, Р= 0+1 f=73,728 MHz
  //PLLCFG =  0x00000021;     //ускорение в 2 раза (18.432*2) время установки ~57uS
  //---------20.04.2012-------------------------------------
  PLLCON =  0x00000001;
  PLLFEED = 0x000000AA;
  PLLFEED = 0x00000055;
  while (!(PLLSTAT & 0x00000400));
  //PLLCON =  0x00000003;
  PLLFEED = 0x000000AA;
  PLLFEED = 0x00000055;
  //---------20.04.2012-------------------------------------
  
  
  APBDIV_bit.APBDIV   = 0;    //VPB - Pclk=Cclk - 01
  APBDIV_bit.XCLKDIV = 1;
  
}

void GPIO2ConfSet(void)
{
  PINSEL0 = 0;
  PINSEL2 = 0x2004; //Включение P3.23 на вывод cclk
  //PINSEL2 = 0x0004;
  IO2DIR_bit.P2_16 = 1;
  IO2CLR_bit.P2_16 = 1;
  IO2DIR_bit.P2_17 = 1;
  IO2CLR_bit.P2_17 = 1;
}


// Setup Timer
void InitTimer0(void)
{
  T0TCR = 0; // Disable timer 0.
  T0TCR = 2; // Reset timer 0.
  T0TCR = 0;
  T0IR = 0xff; // Clear timer 0 interrupt line.
  T0PR = 0; // Prescaler is set to no division.
  TestTemp = TMR0_1ms;
  //T0MR0 = (int)(TMR0_1ms); // Count up to this value. To generate 1ms.
  T0MR0 = TestTemp;
  T0MCR = 3; // Reset and interrupt on MR0 (match register 0).
  T0CCR = 0; // Capture is disabled.
  T0EMR = 0; // No external match output.
}

// Start Timer
void StartTimer0(void)
{
  T0TCR = 1; // Enable timer 0.
}

//
// UART functions
//

void InitUART0(void)
{
  //Set pins for use with UART
  PINSEL0_bit.P0_0 = 0x01;                  /* Enable RxD0 and TxD0              */
  PINSEL0_bit.P0_1 = 0x01;                  /* Enable RxD0 and TxD0              */

  //Set the FIFO enable bit in the FCR register. This bit must be set for
  //proper UART operation.
  U0FCR = 1;

  //Set baudrate
  U0LCR_bit.DLAB = 1;
  U0DLL = BAUDRATEDIVISOR & 0x00ff;
  U0DLM = (BAUDRATEDIVISOR >> 8) & 0x00ff;
  U0LCR_bit.DLAB = 0;

  //Set mode
  U0LCR_bit.WLS = 0x3;   //8 bit word length
  U0LCR_bit.SBS = 0x0;   //1 stop bit
  U0LCR_bit.PE  = 0x0;   //No parity

  //Enable UART0 interrupts
  U0IER_bit.RDAIE  = 1;  //Enable byte received interrupt
  U0IER_bit.THREIE = 1;  //Enable tx buf empty interrupt
}


//---Инициализация переменных------------------------
void VarConfSet(void)
{
  inv_temp = 0x01;
  
}
