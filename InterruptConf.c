

#include "InterruptConf.h"

extern  volatile int ms_ctr;
extern unsigned int pulMemory;

//
// Interrupt handlers.
//

//Dummy interrupt handler, called as default in irqHandler() if no other
//vectored interrupt is called.
static void DefDummyInterrupt(void)
{}

//
// Interrupt controller initalization.
//

// Reset all interrupts
void InitVIC(void)
{
  // Setup interrupt controller.
  VICProtection = 0;
  // Disable all interrupts
  VICIntEnClear = 0xffffffff;
  VICDefVectAddr = (unsigned int)&DefDummyInterrupt;
}


// IRQ exception handler. Calls the interrupt handlers.
__irq __arm void IRQ_Handler(void)
{
  void (*interrupt_function)();
  unsigned int vector;

  vector = VICVectAddr;   // Get interrupt vector.
  interrupt_function = (void(*)())vector;
  (*interrupt_function)();  // Call vectored interrupt function.

  VICVectAddr = 0;        // Clear interrupt in VIC.
}

// IRQ exception handler. Calls the interrupt handlers.
__fiq __arm void FIQ_Handler(void)
{
//  PLLCON =  0x00000003;
//  PLLFEED = 0x000000AA;
//  PLLFEED = 0x00000055;
  pulMemory = *(unsigned int*) EMCACP;
  IO2SET_bit.P2_17 = 1;
  IO2CLR_bit.P2_17 = 1;
//  PLLCON =  0x00000003;
//  PLLFEED = 0x000000AA;
//  PLLFEED = 0x00000055;
  IO2SET_bit.P2_17 = 1;
  IO2CLR_bit.P2_17 = 1;
//  PLLCON =  0x00000001;
//  PLLFEED = 0x000000AA;
//  PLLFEED = 0x00000055;
  EXTINT = 0x1;             //сброс прерывания
}





// Setup Timer interrupt
void InitTimer0Interrupt(void)
{
 

  VICIntSelect &= ~VIC_TIMER0_bit; // IRQ on timer 0 line.
  VICVectAddr1 = (unsigned int)&Timer0Interrupt;
  VICVectCntl1 = 0x20 | VIC_TIMER0; // Enable vector interrupt for timer 0.
  VICIntEnable = VIC_TIMER0_bit;    // Enable timer 0 interrupt.
}

/*****************************************************
* Initialise EINT0
*****************************************************/
void InitEINT0(void)
{
  PINSEL1_bit.P0_16 = 0x1;               /* select P0:16 as EINT0 */
  EXTPOLAR_bit.EXTPOLAR0 = 0;
  EXTMODE_bit.EXTMODE0 = 1;
  
  EXTINT = 0x1;                /* clear EINT0 interrupt status */
  VICIntSelect  |= VIC_EINT0_bit;   /* FIQ  */
  VICIntEnable_bit.INT14 = 1;
}
