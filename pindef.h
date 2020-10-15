#ifndef _PINDEF
#define _PINDEF

#define OUTPUT_PIN        1
#define INPUT_PIN         0
#define INTERNAL_PULLUP   0
#define NO_PULL           2
#define INTERNAL_PULLDOWN 3

#define B_0	1
#define B_1	2
#define B_2	4
#define B_3	8
#define B_4	16
#define B_5	32
#define B_6	64
#define B_7	128
#define B_8	256
#define B_9	512
#define B_10	1024
#define B_11	2048
#define B_12	4096
#define B_13	8192
#define B_14	16384
#define B_15	32768
#define B_16	65536
#define B_17	131072
#define B_18	262144
#define B_19	524288
#define B_20	1048576
#define B_21	2097152
#define B_22	4194304
#define B_23	8388608
#define B_24	16777216
#define B_25	33554432
#define B_26	67108864
#define B_27	134217728
#define B_28	268435456
#define B_29	536870912
#define B_30	1073741824
#define B_31	2147483648

#define MY_FIO0SET(value)	*((unsigned long*)0x3FFFC018) = value
#define MY_FIO0CLR(value)	*((unsigned long*)0x3FFFC01C) = value
#define MY_FIO1SET(value)	*((unsigned long*)0x3FFFC038) = value
#define MY_FIO1CLR(value)	*((unsigned long*)0x3FFFC03C) = value
#define MY_IO2SET(value)	*((unsigned long*)0xE0028024) = value
#define MY_IO2CLR(value)	*((unsigned long*)0xE002802C) = value
#define MY_IO3SET(value)	*((unsigned long*)0xE0028034) = value
#define MY_IO3CLR(value)	*((unsigned long*)0xE002803C) = value

//------ PORT 0 ----------------------

#define DIR_TX FIO0DIR_bit.P0_0
#define SET_TX MY_FIO0SET(B_0)
#define CLR_TX MY_FIO1CLR(B_0)
#define PIN_TX FIO0PIN_bit.P0_0

#define DIR_RX FIO0DIR_bit.P0_1
#define SET_RX MY_FIO0SET(B_1)
#define CLR_RX MY_FIO1CLR(B_1)
#define PIN_RX FIO0PIN_bit.P0_1

#define DIR_CLK FIO0DIR_bit.P0_2
#define SET_CLK MY_FIO0SET(B_2)
#define CLR_CLK MY_FIO1CLR(B_2)
#define PIN_CLK FIO0PIN_bit.P0_2

#define DIR_DI_O FIO0DIR_bit.P0_3
#define SET_DI_O MY_FIO0SET(B_3)
#define CLR_DI_O MY_FIO1CLR(B_3)
#define PIN_DI_O FIO0PIN_bit.P0_3

//------ PORT 2 ----------------------

#define DIR_CS6 IO2DIR_bit.P2_26
#define SET_CS6 MY_IO2SET(B_26)
#define CLR_CS6 MY_IO2CLR(B_26)
#define PIN_CS6 IO2PIN_bit.P2_26

#endif /* _PINDEF */