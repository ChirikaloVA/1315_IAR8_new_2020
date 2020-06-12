#include "UART0.h"

// Pointers to interrupt callback functions.
static void (*uart0rx_function)(unsigned char);
static void (*uart0tx_function)(void);


//UART0 interrupt handler
static void UART0Interrupt(void)
{
  switch(U0IIR_bit.IID)
  {
  case 0x1:  //THRE interrupt
    (*uart0tx_function)(); //Call tx buffer empty callback function
    break;
  case 0x2:  //Receive data available
    (*uart0rx_function)(U0RBR);    //Call received byte callback function
    break;
  case 0x0:  //Modem interrupt
  case 0x3:  //Receive line status interrupt (RDA)
  case 0x6:  //Character time out indicator interrupt (CTI)
  default:
    break;
  }
}

// Setup UART interrupt
void InitUART0Interrupt(void(*uart0rx_func)(unsigned char),
                               void(*uart0tx_func)())
{
  // Setup uart1 callback functions.
  uart0rx_function = uart0rx_func;
  uart0tx_function = uart0tx_func;

  VICIntSelect &= ~VIC_UART0_bit;  // IRQ on UART0.
  VICVectAddr5 = (unsigned int)&UART0Interrupt;
  VICVectCntl5 = 0x20 | VIC_UART0; // Enable vector interrupt for UART0.
  VICIntEnable = VIC_UART0_bit;    // Enable UART 0 interrupt.
}

//Transmits one byte via UART0
void UART0TxByte(unsigned char byte)
{
  while(U0LSR_bit.THRE != 1);
    U0THR = byte;
}
