/*
  File: Serial.h
*/



#define RXBUFF_SIZE 20    /* Size of receive buffer */
#define TXBUFF_SIZE 20    /* Size of transmit buffer */

#include <NXP/iolpc2294.h>
#include <stdio.h>

void byteReceived(unsigned char);
void txBufEmpty(void);
void scanline(char *);
void UART0TxByte(unsigned char byte);


