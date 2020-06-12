#include <intrinsics.h>
#include <NXP/iolpc2294.h>

#define VIC_UART0_bit  (1 << VIC_UART0)

static void UART0Interrupt(void);
void UART0TxByte(unsigned char byte);
void InitUART0Interrupt(void(*uart0rx_func)(unsigned char),void(*uart0tx_func)());