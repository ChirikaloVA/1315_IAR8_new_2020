
#include "main.h"
#include <stdio.h>

int main()
{
  // First disable interrupts.
  __disable_interrupt();
  MemConfSet();
  PLLandClockConfSet();
  GPIO2ConfSet();
  InitTimer0();
  VarConfSet();
  InitVIC();
  InitTimer0Interrupt();
  InitEINT0();
  InitUART0();
  InitUART0Interrupt(byteReceived, txBufEmpty);
  // Enable interrupts.
  __enable_interrupt();
  StartTimer0();
  while(1)
  {
    Sleep(10);
    inv_temp = ~inv_temp;
    if(IO2PIN_bit.P2_16 == 1)
    {
      IO2CLR_bit.P2_16 = 1;
    }
    else
    {
      IO2SET_bit.P2_16 = 1;
    }
    
    printf("Enter value:\n\r>");
    scanline((char*)&name);
    printf("\nHello %s.  Welcome to IAR Systems.\n\n\n\r", name);
  }

}
