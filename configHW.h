#include <intrinsics.h>
#include <NXP/iolpc2294.h>
#include "pindef.h"

#define XTALFREQ 18432000
#define APBDIV_ 2
#define PLL_M 1
#define PLL_P 2
#define PCLKFREQ (XTALFREQ/APBDIV_)
#define PCLKFREQ_PLL ((XTALFREQ*(PLL_M+1))/APBDIV_)

#define TMR0_1ms (0.001*PCLKFREQ_PLL)

#define BAUDRATE    115200
#define BAUDRATEDIVISOR (PCLKFREQ/(BAUDRATE*16))

void MemConfSet(void);
void PLLandClockConfSet(void);
void GPIO2ConfSet(void);
void VarConfSet(void);
void InitTimer0(void);
void StartTimer0(void);
void InitUART0(void);

