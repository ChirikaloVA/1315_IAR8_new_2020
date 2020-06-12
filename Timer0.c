
#include "Timer0.h"

volatile int ms_ctr;

// Timer interrupt handler
void Timer0Interrupt(void)
{
  
  ms_ctr++;
  T0IR = 0xff; // Clear timer 0 interrupt line.
}


void Sleep(int milliseconds)
{
  ms_ctr = 0;
  while (ms_ctr < milliseconds) 
  {
    if(PCON_bit.IDL == 0)
    {
      //PCON_bit.IDL = 1;
    }
  }
  PCON_bit.IDL = 0;
}