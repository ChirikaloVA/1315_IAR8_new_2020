
#include <intrinsics.h>
#include <NXP/iolpc2294.h>
#include "Timer0.h"

#define VIC_TIMER0_bit (1 << VIC_TIMER0)
#define VIC_UART0_bit  (1 << VIC_UART0)
#define VIC_EINT0_bit  (1 << VIC_EINT0)
//#define INTERENT0     0x4000   /* bit 14h int*/
#define EMCACP  0x82000000;



void InitVIC(void);
void InitTimer0Interrupt(void);
void InitEINT0(void);

