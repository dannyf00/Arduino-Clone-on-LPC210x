#include "lpc21duino.h"				//lpc21duino for lpc2101/2/3 chips

//global defines

//global variables
//declare pins
//ALL PINS ARE MAPPED, WHETHER THEY EXIST OR NOT
//SO MAKE SURE THAT THE PINS YOU PICKED ACTUALLY EXIST FOR YOUR PACKAGE
//Pin  0.. 7 -> GPIOA
//Pin  8..15 -> GPIOB
const PIN2GPIO GPIO_PinDef[]={
#if defined(LPC_GPIO0)
	{LPC_GPIO0, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO0, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO0, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO0, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO0, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO0, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO0, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO0, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO0, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO0, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO0, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO0, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO0, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO0, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO0, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO0, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{LPC_GPIO0, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO0, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO0, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO0, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO0, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO0, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO0, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO0, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO0, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO0, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO0, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO0, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO0, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO0, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO0, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO0, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//LPC_GPIO0
#if defined(LPC_GPIO1)
	{LPC_GPIO1, 1ul<<0},						//STM32duino Pin 16 = RP0/PB0/CHIP PIN4
	{LPC_GPIO1, 1ul<<1},						//STM32duino Pin 17 = RP1/PB1/CHIP PIN5
	{LPC_GPIO1, 1ul<<2},						//STM32duino Pin 18 = RP2/PB2/CHIP PIN6
	{LPC_GPIO1, 1ul<<3},						//STM32duino Pin 19 = RP3/PB3/CHIP PIN7
	{LPC_GPIO1, 1ul<<4},						//STM32duino Pin 20 = RP4/PB4/CHIP PIN11
	{LPC_GPIO1, 1ul<<5},						//STM32duino Pin 21 = RP5/PB5/CHIP PIN14
	{LPC_GPIO1, 1ul<<6},						//STM32duino Pin 22 = RP6/PB6/CHIP PIN15
	{LPC_GPIO1, 1ul<<7},						//STM32duino Pin 23 = RP7/PB7/CHIP PIN16
	{LPC_GPIO1, 1ul<<8},						//STM32duino Pin 24 = RP8/PB8/CHIP PIN17
	{LPC_GPIO1, 1ul<<9},						//STM32duino Pin 25 = RP9/PB9/CHIP PIN18
	{LPC_GPIO1, 1ul<<10},						//STM32duino Pin 26 = RP10/PB10/CHIP PIN21
	{LPC_GPIO1, 1ul<<11},						//STM32duino Pin 27 = RP11/PB11/CHIP PIN22
	{LPC_GPIO1, 1ul<<12},						//STM32duino Pin 28 = RP12/PB12/CHIP PIN23
	{LPC_GPIO1, 1ul<<13},						//STM32duino Pin 29 = RP13/PB13/CHIP PIN24
	{LPC_GPIO1, 1ul<<14},						//STM32duino Pin 30 = RP14/PB14/CHIP PIN25
	{LPC_GPIO1, 1ul<<15},						//STM32duino Pin 31 = RP15/PB15/CHIP PIN26
	{LPC_GPIO1, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO1, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO1, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO1, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO1, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO1, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO1, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO1, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO1, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO1, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO1, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO1, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO1, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO1, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO1, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO1, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//LPC_GPIO1
#if defined(LPC_GPIO2)
	{LPC_GPIO2, 1ul<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{LPC_GPIO2, 1ul<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{LPC_GPIO2, 1ul<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{LPC_GPIO2, 1ul<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{LPC_GPIO2, 1ul<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{LPC_GPIO2, 1ul<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{LPC_GPIO2, 1ul<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{LPC_GPIO2, 1ul<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{LPC_GPIO2, 1ul<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{LPC_GPIO2, 1ul<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{LPC_GPIO2, 1ul<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{LPC_GPIO2, 1ul<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{LPC_GPIO2, 1ul<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{LPC_GPIO2, 1ul<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{LPC_GPIO2, 1ul<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{LPC_GPIO2, 1ul<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
	{LPC_GPIO2, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO2, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO2, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO2, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO2, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO2, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO2, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO2, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO2, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO2, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO2, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO2, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO2, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO2, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO2, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO2, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//LPC_GPIO2

#if defined(LPC_GPIO3)						//pins 48..63
	{LPC_GPIO3, 1ul<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{LPC_GPIO3, 1ul<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{LPC_GPIO3, 1ul<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{LPC_GPIO3, 1ul<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{LPC_GPIO3, 1ul<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{LPC_GPIO3, 1ul<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{LPC_GPIO3, 1ul<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{LPC_GPIO3, 1ul<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{LPC_GPIO3, 1ul<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{LPC_GPIO3, 1ul<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{LPC_GPIO3, 1ul<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{LPC_GPIO3, 1ul<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{LPC_GPIO3, 1ul<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{LPC_GPIO3, 1ul<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{LPC_GPIO3, 1ul<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{LPC_GPIO3, 1ul<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
	{LPC_GPIO3, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO3, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO3, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO3, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO3, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO3, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO3, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO3, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO3, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO3, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO3, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO3, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO3, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO3, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO3, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO3, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//LPC_GPIO3

#if defined(LPC_GPIO4)						//pins 64..79
	{LPC_GPIO4, 1ul<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{LPC_GPIO4, 1ul<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{LPC_GPIO4, 1ul<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{LPC_GPIO4, 1ul<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{LPC_GPIO4, 1ul<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{LPC_GPIO4, 1ul<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{LPC_GPIO4, 1ul<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{LPC_GPIO4, 1ul<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{LPC_GPIO4, 1ul<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{LPC_GPIO4, 1ul<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{LPC_GPIO4, 1ul<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{LPC_GPIO4, 1ul<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{LPC_GPIO4, 1ul<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{LPC_GPIO4, 1ul<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{LPC_GPIO4, 1ul<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{LPC_GPIO4, 1ul<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
	{LPC_GPIO4, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO4, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO4, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO4, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO4, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO4, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO4, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO4, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO4, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO4, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO4, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO4, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO4, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO4, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO4, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO4, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//LPC_GPIO4

#if defined(LPC_GPIO5)						//pins 80..96
	{LPC_GPIO5, 1ul<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{LPC_GPIO5, 1ul<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{LPC_GPIO5, 1ul<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{LPC_GPIO5, 1ul<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{LPC_GPIO5, 1ul<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{LPC_GPIO5, 1ul<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{LPC_GPIO5, 1ul<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{LPC_GPIO5, 1ul<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{LPC_GPIO5, 1ul<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{LPC_GPIO5, 1ul<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{LPC_GPIO5, 1ul<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{LPC_GPIO5, 1ul<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{LPC_GPIO5, 1ul<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{LPC_GPIO5, 1ul<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{LPC_GPIO5, 1ul<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{LPC_GPIO5, 1ul<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
	{LPC_GPIO5, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{LPC_GPIO5, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{LPC_GPIO5, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{LPC_GPIO5, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{LPC_GPIO5, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{LPC_GPIO5, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{LPC_GPIO5, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{LPC_GPIO5, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{LPC_GPIO5, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{LPC_GPIO5, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{LPC_GPIO5, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{LPC_GPIO5, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{LPC_GPIO5, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{LPC_GPIO5, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{LPC_GPIO5, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{LPC_GPIO5, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//LPC_GPIO5
};

//global variables

volatile uint32_t SystemCoreClock;;				//system coreclock - needs to be updated
volatile uint32_t AHBClock;						//ahb clock rate
volatile uint32_t APBClock;						//=Pclk

//update systemcoreclock - for comptability with cmsis
uint32_t SystemCoreClockUpdate(void) {
	uint32_t tmp = F_XTAL;						//temp var holding the clock frequency
	
	//calculate the clock value
	//bit 8: PLLE (enable bit), bit 9: PLLC (connection bit)
	if (PLLSTAT & (0x03<<8)) {					//pll is enabled and connected
			tmp *= 1+(PLLSTAT & 0x1f);			//pll multiplier
			//tmp>>= 1+((PLLSTAT >> 5) & 0x03);	//pll divider
	}
	SystemCoreClock = tmp;

	//calculate ahb clock
	AHBClock = SystemCoreClock;

	//calclate apb clock (=PCLK)
	tmp = F_CPU;
	switch (APBDIV & 0x03) {
		case 0x00: tmp /= 4; break;					//this is the default
		case 0x01: tmp /= 1; break;					//fastest
		case 0x02: tmp /= 2; break;					//alternative
	}
	APBClock = tmp;
	//return with the clock value
	return SystemCoreClock;
}

//get AHB speed (=CCLK)?
//on this chip, ahb peripheral clock = cpu clock / 1 - needs verification
//AHB only feeds Vectored Interrupt Controller, per the datasheet

//get APB speed (=PCLK)
//on this chip, apb peripheral clock = cpu clock / apbdiv
void __irq DefISR(void);

//reset the mcu
void mcuInit(void) {
	PCONP  = 0;						//0->disable all periopherals by default
#if defined(USE_FGPIO)
	SCS   |= (1<<0);				//1->fast gpio, 0->legacy gpio
#else
	SCS   &=~(1<<0);				//1->fast gpio, 0->legacy gpio
#endif
	APBDIV = 	(APBDIV &~(0x03<<0)) |
				(0x00<<0);			//0->PCLK=CCLK/4, 1->PCLK = CCLK / 1, 2->PCLK = CCLK/2
	
	//select the clock source
	//clock configuration doen via Startup.s

	//update SystemCoreClock
	SystemCoreClockUpdate();
	
	//start timer0 as systick / coretick
	tmr0Init();

	VICDefVectAddr = (uint32_t )DefISR; // set interrupt vector in DefISR

	//enable global interrupts
	ei();							//testing
}

//empty interrupt handler
void empty_handler(void) {
	//do nothing here
}

//C main loop
int main(void) {

	mcuInit();						//reset the mcu
	setup();						//run the setup code
	while (1) {
		loop();						//run the default loop
	}
}


//Arduino Functions: GPIO
//set a pin mode to INPUT or OUTPUT
//no error checking on PIN
void pinMode(PIN_TypeDef pin, uint8_t mode) {
	if (mode==OUTPUT) IO_OUT(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
	else IO_IN(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
}

//set / clear a pin
void digitalWrite(PIN_TypeDef pin, uint8_t val) {
	if (val==LOW) IO_CLR(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
	else IO_SET(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
}

//read a pin
int digitalRead(PIN_TypeDef pin) {
	return (IO_GET(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask))?HIGH:LOW;
}
//end GPIO

//ticks()
//Arduino Functions: Time
//return timer ticks
	
//delay millisseconds
//void delay(uint32_t ms) {
//	uint32_t start_time = ticks();
//	ms *= cyclesPerMillisecond();
//	while (ticks() - start_time < ms) continue;
//}

//delay micros seconds
//void delayMicroseconds(uint32_t us) {
//	uint32_t start_time = ticks();
//	us *= cyclesPerMicrosecond();
//	while (ticks() - start_time < us) continue;
//}
//delay ticks
void delayTks(uint32_t tks) {
	uint32_t start_time = ticks();
	while (ticks() - start_time < tks) continue;
}
//end Time

//non vectored interrupt
//uart0/1 isr pointers
volatile char *_U0TX_ptr;
volatile char *_U1TX_ptr;

//non-vectored isr
void u0tx_isr(void);
void u1tx_isr(void);
void __irq DefISR(void) {
	uint32_t tmp;
#if defined(USE_U0TXISR)
	tmp=U0IIR;								//read the flag and clears it by reading it
	switch (tmp & (0x07<<1)) {
		case (0x01<<1): u0tx_isr(); break;	//0x01->THRE interrupt
	}
#endif

#if defined(USE_U1TXISR)
	tmp=U1IIR;								//read the flag and clears it by reading it
	switch (tmp & (0x07<<1)) {
		case (0x01<<1): u1tx_isr(); break;	//0x01->THRE interrupt
	}
#endif

	VICVectAddr = 0x00000000; 				//Dummy write to signal end of interrupt
}

//set up timer0
//systick handler - to provide time base for millis()/micros()
//pointer to user handler
static void (* _t0mr0_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0mr1_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0mr2_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0mr3_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0ic0_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0ic1_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0ic2_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t0ic3_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler

//shadow period registers - 32-bit timer
static uint32_t _t0pr0=0x0000;				//mr0 fixed at 0xfffffffful/0x00000000ul
static uint32_t _t0pr1=0x0000;
static uint32_t _t0pr2=0x0000;
static uint32_t _t0pr3=0x0000;

//timer0 isr
void __irq T0ISR(void) {
	//match channel 0
	if (T0IR & (1<<0)) {
		T0IR = 1<<0;						//clear the flag by writing 1 to it, writing 0 has no effect
		T0MR0+= _t0pr0;						//update match register
		_t0mr0_ptr();						//execute user handler
	}

	//match channel 1
	if (T0IR & (1<<1)) {
		T0IR = 1<<1;						//clear the flag by writing 1 to it
		T0MR1+= _t0pr1;						//update match register
		_t0mr1_ptr();						//execute user handler
	}

	//match channel 2
	if (T0IR & (1<<2)) {
		T0IR = 1<<2;						//clear the flag by writing 1 to it
		T0MR2+= _t0pr2;						//update match register
		_t0mr2_ptr();						//execute user handler
	}

	//match channel 3
	if (T0IR & (1<<3)) {
		T0IR = 1<<3;						//clear the flag by writing 1 to it
		T0MR3+= _t0pr3;						//update match register
		_t0mr3_ptr();						//execute user handler
	}

	//input capture 0
	if (T0IR & (1<<4)) {
		T0IR = 1<<4;						//clear the flag by writing 1 to it
		_t0ic0_ptr();						//execute user handler
	}

	//input capture 1
	if (T0IR & (1<<5)) {
		T0IR = 1<<5;						//clear the flag by writing 1 to it
		_t0ic1_ptr();						//execute user handler
	}

	//input capture 2
	if (T0IR & (1<<6)) {
		T0IR = 1<<6;						//clear the flag by writing 1 to it
		_t0ic2_ptr();						//execute user handler
	}

	//input capture 3
	if (T0IR & (1<<7)) {
		T0IR = 1<<7;						//clear the flag by writing 1 to it
		_t0ic3_ptr();						//execute user handler
	}

	VICVectAddr = 0x00000000; 				//Dummy write to signal end of interrupt
}

//initialize timer0
void tmr0Init(void) {
	PCONP |= 1<<1;				//enable clock: 1: timer0, 2: timer1, 22: timer2, 23: timer3

	//configure timer0 mr0 channel as systick generator
	//stop the timer
	T0TCR = 1<<1;				//1=reset and disable the timer

	T0CTCR = 0;					//0->timer mode
	T0TCR&=~0x03;				//reset bit 1..0->count on rising edge of pclk
	T0TC = 0;					//reset counter - optional
	T0PC = 0;					//reset prescaler counter to 0
	T0PR = 0;					//set prescaler to 1:1
	T0MCR= 0;	//(T0MCR & ~(0x07 << (3*0))) |
				//(0x00 << (3*0));	//set up the match register. no interrupt yet
	T0TCR = 1;					//start the timer
}

//install user handler for IC0
void tmr0IC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0ic0_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<4;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T0CTCR = (T0CTCR & ~(0x03 << 2)) | (0 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T0CCR= 	(T0CCR & ~(0x07 << (3*0))) |
			(0x01 << (3*0)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*0));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC00_PIN)
	IC00_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC1
void tmr0IC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0ic1_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<5;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T0CTCR = (T0CTCR & ~(0x03 << 2)) | (1 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T0CCR= 	(T0CCR & ~(0x07 << (3*1))) |
			(0x01 << (3*1)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*1));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC01_PIN)
	IC01_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC2
void tmr0IC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0ic2_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<6;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T0CTCR = (T0CTCR & ~(0x03 << 2)) | (2 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T0CCR= 	(T0CCR & ~(0x07 << (3*2))) |
			(0x01 << (3*2)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*2));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC02_PIN)
	IC02_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC3
void tmr0IC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0ic3_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<7;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T0CTCR = (T0CTCR & ~(0x03 << 2)) | (3 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T0CCR= 	(T0CCR & ~(0x07 << (3*3))) |
			(0x01 << (3*3)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*3));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC03_PIN)
	IC03_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match channels
void tmr0OC0SetPR(uint32_t pr) {
	//clear the flag
	T0IR = 1<<0;							//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));			//set up the match register. no interrupt yet
	T0MR0= _t0pr0 = pr - 0;

}

//read timer period
uint32_t tmr0OC0GetPR(void) {
	return _t0pr0;
}

//install user handler
void tmr0OC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0mr0_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<0;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*0))) |
				(0x01 << (3*0));	//set up the match register. interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4

}

//set up the match
void tmr0OC1SetPR(uint32_t pr) {
	//clear the flag
	T0IR = 1<<1;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));	//set up the match register. no interrupt yet
	T0MR1= _t0pr1 = pr - 0;

}

//read timer period
uint32_t tmr0OC1GetPR(void) {
	return _t0pr1;
}

//install user handler
void tmr0OC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0mr1_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<1;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*1))) |
				(0x01 << (3*1));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match
void tmr0OC2SetPR(uint32_t pr) {
	//clear the flag
	T0IR = 1<<2;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));	//set up the match register. no interrupt yet
	T0MR2= _t0pr2 = pr - 0;

}

//read timer period
uint32_t tmr0OC2GetPR(void) {
	return _t0pr2;
}

//install user handler
void tmr0OC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0mr2_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<2;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*2))) |
				(0x01 << (3*2));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match
void tmr0OC3SetPR(uint32_t pr) {
	//clear the flag
	T0IR = 1<<3;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*3))) |
				(0x00 << (3*3));	//set up the match register. no interrupt yet
	T0MR3= _t0pr3 = pr - 0;

}

//read timer period
uint32_t tmr0OC3GetPR(void) {
	return _t0pr3;
}

//install user handler
void tmr0OC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t0mr3_ptr = isr_ptr;

	//clear the flag
	T0IR = 1<<3;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*3))) |
				(0x01 << (3*3));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 4 used for tmr0
	VICVectAddr4 = (uint32_t )T0ISR;      		// set interrupt vector in 0
  	VICVectCntl4 = (1<<5) | 4;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<4);						// Enable Timer0 Interrupt. turn on irq4
}

//generate pwm output
void tmr0PWM0Init(void) {
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));				//set up the match register. no interrupt yet
	T0EMR=	(T0EMR & ~(0x03 << 4)) |
			(0x02 << 4);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T0PWMCON=(T0PWMCON &~(1<<0)) | (1<<0);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM00_PIN)
	PWM00_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr0PWM1Init(void) {
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));				//set up the match register. no interrupt yet
	T0EMR=	(T0EMR & ~(0x03 << 6)) |
			(0x02 << 6);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T0PWMCON=(T0PWMCON &~(1<<1)) | (1<<1);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM01_PIN)
	PWM01_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr0PWM2Init(void) {
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));				//set up the match register. no interrupt yet
	T0EMR=	(T0EMR & ~(0x03 << 8)) |
			(0x02 << 8);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T0PWMCON=(T0PWMCON &~(1<<2)) | (1<<2);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM02_PIN)
	PWM02_PIN();								//enable the output pin
#endif
}

//generate pwm output - this resets the pwm period
void tmr0PWM3Init(void) {
	//don't enable interrupt
	T0MCR= 	(T0MCR & ~(0x07 << (3*3))) |
				(0x02 << (3*3));				//set up the match register. 2: reset on match, no interrupt yet
	T0EMR=	(T0EMR & ~(0x03 <<10)) |
			(0x00 <<10);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T0PWMCON=(T0PWMCON &~(1<<3)) | (1<<3);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM03_PIN)
	PWM03_PIN();								//enable the output pin
#endif
}

//end timer0

//set up timer1
//systick handler - to provide time base for millis()/micros()
//pointer to user handler
static void (* _t1mr0_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1mr1_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1mr2_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1mr3_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1ic0_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1ic1_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1ic2_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler
static void (* _t1ic3_ptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler

//shadow period registers - 32-bit timer
static uint32_t _t1pr0=0x0000;				//mr0 fixed at 0xfffffffful/0x00000000ul
static uint32_t _t1pr1=0x0000;
static uint32_t _t1pr2=0x0000;
static uint32_t _t1pr3=0x0000;

//timer1 isr
void __irq T1ISR(void) {
	//match channel 0
	if (T1IR & (1<<0)) {
		T1IR = 1<<0;						//clear the flag by writing 1 to it
		T1MR0+= _t1pr0;						//update match register
		_t1mr0_ptr();						//execute user handler
	}

	//match channel 1
	if (T1IR & (1<<1)) {
		T1IR = 1<<1;						//clear the flag by writing 1 to it
		T1MR1+= _t1pr1;						//update match register
		_t1mr1_ptr();						//execute user handler
	}

	//match channel 2
	if (T1IR & (1<<2)) {
		T1IR = 1<<2;						//clear the flag by writing 1 to it
		T1MR2+= _t1pr2;						//update match register
		_t1mr2_ptr();						//execute user handler
	}

	//match channel 3
	if (T1IR & (1<<3)) {
		T1IR = 1<<3;						//clear the flag by writing 1 to it
		T1MR3+= _t1pr3;						//update match register
		_t1mr3_ptr();						//execute user handler
	}
	
	//input capture 0
	if (T1IR & (1<<4)) {
		T1IR = 1<<4;
		_t1ic0_ptr();
	}

	//input capture 1
	if (T1IR & (1<<5)) {
		T1IR = 1<<5;
		_t1ic1_ptr();
	}

	//input capture 2
	if (T1IR & (1<<5)) {
		T1IR = 1<<5;
		_t1ic2_ptr();
	}

	//input capture 3
	if (T1IR & (1<<6)) {
		T1IR = 1<<6;
		_t1ic3_ptr();
	}

	VICVectAddr = 0x00000000; 				//Dummy write to signal end of interrupt
}

//initialize timer0
void tmr1Init(void) {
	PCONP |= 1<<2;				//enable clock: 1: timer0, 2: timer1, 22: timer2, 23: timer3

	//configure timer0 mr0 channel as systick generator
	//stop the timer
	T1TCR = 1<<1;				//1=reset and disable the timer

	T1CTCR = 0;					//0->timer mode
	T1TCR&=~0x03;				//reset bit 1..0->count on rising edge of pclk
	T1TC = 0;					//reset counter - optional
	T1PC = 0;					//reset prescaler counter to 0
	T1PR = 0;					//set prescaler to 1:1
	T1MCR= 0;	//(T1MCR & ~(0x07 << (3*0))) |
				//(0x00 << (3*0));	//set up the match register. no interrupt yet
	T1TCR = 1;					//start the timer
}

//install user handler for IC0
void tmr1IC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1ic0_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<4;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T1CTCR = (T1CTCR & ~(0x03 << 2)) | (0 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T1CCR= 	(T1CCR & ~(0x07 << (3*0))) |
			(0x01 << (3*0)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*0));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC10_PIN)
	IC10_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC1
void tmr1IC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1ic1_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<5;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T1CTCR = (T1CTCR & ~(0x03 << 2)) | (1 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T1CCR= 	(T1CCR & ~(0x07 << (3*1))) |
			(0x01 << (3*1)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*1));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC11_PIN)
	IC11_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer0 Interrupt. turn on irq4
}


//install user handler for IC2
void tmr1IC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1ic2_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<6;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T1CTCR = (T1CTCR & ~(0x03 << 2)) | (2 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T1CCR= 	(T1CCR & ~(0x07 << (3*2))) |
			(0x01 << (3*2)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*2));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC12_PIN)
	IC12_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer0 Interrupt. turn on irq4
}


//install user handler for IC0
void tmr1IC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1ic3_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<6;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T1CTCR = (T1CTCR & ~(0x03 << 2)) | (3 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T1CCR= 	(T1CCR & ~(0x07 << (3*3))) |
			(0x01 << (3*3)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*3));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC13_PIN)
	IC13_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match channels
void tmr1OC0SetPR(uint32_t pr) {
	//clear the flag
	T1IR = 1<<0;							//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));			//set up the match register. no interrupt yet
	T1MR0= _t1pr0 = pr - 0;

}

//read timer period
uint32_t tmr1OC0GetPR(void) {
	return _t1pr0;
}

//install user handler
void tmr1OC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1mr0_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<0;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*0))) |
				(0x01 << (3*0));	//set up the match register. interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer0 Interrupt. turn on irq4

}

//set up the match
void tmr1OC1SetPR(uint32_t pr) {
	//clear the flag
	T1IR = 1<<1;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));	//set up the match register. no interrupt yet
	T1MR1= _t1pr1 = pr - 0;

}

//read timer period
uint32_t tmr1OC1GetPR(void) {
	return _t1pr1;
}

//install user handler
void tmr1OC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1mr1_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<1;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*1))) |
				(0x01 << (3*1));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match
void tmr1OC2SetPR(uint32_t pr) {
	//clear the flag
	T1IR = 1<<2;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));	//set up the match register. no interrupt yet
	T1MR2= _t1pr2 = pr - 0;

}

//read timer period
uint32_t tmr1OC2GetPR(void) {
	return _t1pr2;
}

//install user handler
void tmr1OC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1mr2_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<2;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*2))) |
				(0x01 << (3*2));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer1 Interrupt. turn on irq5
}

//set up the match
void tmr1OC3SetPR(uint32_t pr) {
	//clear the flag
	T1IR = 1<<3;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*3))) |
				(0x00 << (3*3));	//set up the match register. no interrupt yet
	T1MR3= _t1pr3 = pr - 0;

}

//read timer period
uint32_t tmr1OC3GetPR(void) {
	return _t1pr3;
}

//install user handler
void tmr1OC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t1mr3_ptr = isr_ptr;

	//clear the flag
	T1IR = 1<<3;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*3))) |
				(0x01 << (3*3));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 5 used for tmr1
	VICVectAddr5 = (uint32_t )T1ISR;      		// set interrupt vector in 0
  	VICVectCntl5 = (1<<5) | 5;					// use it for Timer 1 Interrupt. irq5 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<5);						// Enable Timer1 Interrupt. turn on irq5
}

//generate pwm output
void tmr1PWM0Init(void) {
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));				//set up the match register. no interrupt yet
	T1EMR=	(T1EMR & ~(0x03 << 4)) |
			(0x02 << 4);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T1PWMCON=(T1PWMCON &~(1<<0)) | (1<<0);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM10_PIN)
	PWM10_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr1PWM1Init(void) {
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));				//set up the match register. no interrupt yet
	T1EMR=	(T1EMR & ~(0x03 << 6)) |
			(0x02 << 6);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T1PWMCON=(T1PWMCON &~(1<<1)) | (1<<1);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM11_PIN)
	PWM11_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr1PWM2Init(void) {
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));				//set up the match register. no interrupt yet
	T1EMR=	(T1EMR & ~(0x03 << 8)) |
			(0x02 << 8);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T1PWMCON=(T1PWMCON &~(1<<2)) | (1<<2);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM12_PIN)
	PWM12_PIN();								//enable the output pin
#endif
}

//generate pwm output - this resets the pwm period
void tmr1PWM3Init(void) {
	//don't enable interrupt
	T1MCR= 	(T1MCR & ~(0x07 << (3*3))) |
				(0x02 << (3*3));				//set up the match register. 2: reset on match, no interrupt yet
	T1EMR=	(T1EMR & ~(0x03 <<10)) |
			(0x00 <<10);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T1PWMCON=(T1PWMCON &~(1<<3)) | (1<<3);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM13_PIN)
	PWM13_PIN();								//enable the output pin
#endif
}

//end timer1

#if defined(__LPC2103_H)
//set up timer2 - only on LPC2101/2/3, not LPC2104/5/6
//systick handler - to provide time base for millis()/micros()
//pointer to user handler
static void (* _t2mr0_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2mr1_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2mr2_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2mr3_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2ic0_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2ic1_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2ic2_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler
static void (* _t2ic3_ptr)(void)=empty_handler;				//tmr2_ptr pointing to empty_handler

//shadow period registers - 16-bit timer
static uint32_t _t2pr0=0x0000;				//mr0 fixed at 0xfffffffful/0x00000000ul
static uint32_t _t2pr1=0x0000;
static uint32_t _t2pr2=0x0000;
static uint32_t _t2pr3=0x0000;

//timer1 isr
void __irq T2ISR(void) {
	//match channel 0
	if (T2IR & (1<<0)) {
		T2IR = 1<<0;						//clear the flag by writing 1 to it
		T2MR0+= _t2pr0;						//update match register
		_t2mr0_ptr();						//execute user handler
	}

	//match channel 1
	if (T2IR & (1<<1)) {
		T2IR = 1<<1;						//clear the flag by writing 1 to it
		T2MR1+= _t2pr1;						//update match register
		_t2mr1_ptr();						//execute user handler
	}

	//match channel 2
	if (T2IR & (1<<2)) {
		T2IR = 1<<2;						//clear the flag by writing 1 to it
		T2MR2+= _t2pr2;						//update match register
		_t2mr2_ptr();						//execute user handler
	}

	//match channel 3
	if (T2IR & (1<<3)) {
		T2IR = 1<<3;						//clear the flag by writing 1 to it
		T2MR3+= _t2pr3;						//update match register
		_t2mr3_ptr();						//execute user handler
	}
	
	//input capture 0
	if (T2IR & (1<<4)) {
		T2IR = 1<<4;						//clear the flag by writing 1 to it
		_t2ic0_ptr();						//execute user handler
	}

	//input capture 1
	if (T2IR & (1<<5)) {
		T2IR = 1<<5;						//clear the flag by writing 1 to it
		_t2ic1_ptr();						//execute user handler
	}

	//input capture 2
	if (T2IR & (1<<6)) {
		T2IR = 1<<6;						//clear the flag by writing 1 to it
		_t2ic2_ptr();						//execute user handler
	}

	//input capture 3
	if (T2IR & (1<<7)) {
		T2IR = 1<<7;						//clear the flag by writing 1 to it
		_t2ic3_ptr();						//execute user handler
	}

	VICVectAddr = 0x00000000; 				//Dummy write to signal end of interrupt
}

//initialize timer0
void tmr2Init(void) {
	PCONP |= 1<<22;				//enable clock: 1: timer0, 2: timer1, 22: timer2, 23: timer3

	//configure timer0 mr0 channel as systick generator
	//stop the timer
	T2TCR = 1<<1;				//1=reset and disable the timer

	T2CTCR = 0;					//0->timer mode
	T2TCR&=~0x03;				//reset bit 1..0->count on rising edge of pclk
	T2TC = 0;					//reset counter - optional
	T2PC = 0;					//reset prescaler counter to 0
	T2PR = 0;					//set prescaler to 1:1
	T2MCR= 0;	//(T2MCR & ~(0x07 << (3*0))) |
				//(0x00 << (3*0));	//set up the match register. no interrupt yet
	T2TCR = 1;					//start the timer
}

//set up the match channels
void tmr2OC0SetPR(uint32_t pr) {
	//clear the flag
	T2IR = 1<<0;							//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));			//set up the match register. no interrupt yet
	T2MR0= _t2pr0 = pr - 0;

}

//install user handler for IC0
void tmr2IC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2ic0_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<4;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T2CTCR = (T2CTCR & ~(0x03 << 2)) | (0 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T2CCR= 	(T2CCR & ~(0x07 << (3*0))) |
			(0x01 << (3*0)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*0));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC20_PIN)
	IC20_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC1
void tmr2IC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2ic1_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<5;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T2CTCR = (T2CTCR & ~(0x03 << 2)) | (1 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T2CCR= 	(T2CCR & ~(0x07 << (3*1))) |
			(0x01 << (3*1)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*1));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC21_PIN)
	IC21_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC2
void tmr2IC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2ic2_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<6;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T2CTCR = (T2CTCR & ~(0x03 << 2)) | (2 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T2CCR= 	(T2CCR & ~(0x07 << (3*2))) |
			(0x01 << (3*2)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*2));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC22_PIN)
	IC22_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer0 Interrupt. turn on irq4
}


//install user handler for IC3
void tmr2IC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2ic3_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<7;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T2CTCR = (T2CTCR & ~(0x03 << 2)) | (3 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T2CCR= 	(T2CCR & ~(0x07 << (3*3))) |
			(0x01 << (3*3)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*3));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC23_PIN)
	IC23_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer0 Interrupt. turn on irq4
}

//read timer period
uint32_t tmr2OC0GetPR(void) {
	return _t2pr0;
}

//install user handler
void tmr2OC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2mr0_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<0;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*0))) |
				(0x01 << (3*0));	//set up the match register. interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer0 Interrupt. turn on irq4

}

//set up the match
void tmr2OC1SetPR(uint32_t pr) {
	//clear the flag
	T2IR = 1<<1;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));	//set up the match register. no interrupt yet
	T2MR1= _t2pr1 = pr - 0;

}

//read timer period
uint32_t tmr2OC1GetPR(void) {
	return _t2pr1;
}

//install user handler
void tmr2OC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2mr1_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<1;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*1))) |
				(0x01 << (3*1));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match
void tmr2OC2SetPR(uint32_t pr) {
	//clear the flag
	T2IR = 1<<2;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));	//set up the match register. no interrupt yet
	T2MR2= _t2pr2 = pr - 0;

}

//read timer period
uint32_t tmr2OC2GetPR(void) {
	return _t2pr2;
}

//install user handler
void tmr2OC2AttachISR2(void (*isr_ptr)(void)) {
	//install user handler
	_t2mr2_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<2;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*2))) |
				(0x01 << (3*2));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer1 Interrupt. turn on irq5
}

//set up the match
void tmr2OC3SetPR(uint32_t pr) {
	//clear the flag
	T2IR = 1<<3;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*3))) |
				(0x00 << (3*3));	//set up the match register. no interrupt yet
	T2MR3= _t2pr3 = pr - 0;

}

//read timer period
uint32_t tmr2OC3GetPR(void) {
	return _t2pr3;
}

//install user handler
void tmr2OC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t2mr3_ptr = isr_ptr;

	//clear the flag
	T2IR = 1<<3;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*3))) |
				(0x01 << (3*3));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 14 used for tmr2
	VICVectAddr14 = (uint32_t )T2ISR;      		// set interrupt vector in 0
  	VICVectCntl14 = (1<<5) | 26;				// use it for Timer 1 Interrupt. irq5 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<26);						// Enable Timer1 Interrupt. turn on irq5
}

//generate pwm output
void tmr2PWM0Init(void) {
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));				//set up the match register. no interrupt yet
	T2EMR=	(T2EMR & ~(0x03 << 4)) |
			(0x02 << 4);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T2PWMCON=(T2PWMCON &~(1<<0)) | (1<<0);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM20_PIN)
	PWM20_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr2PWM1Init(void) {
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));				//set up the match register. no interrupt yet
	T2EMR=	(T2EMR & ~(0x03 << 6)) |
			(0x02 << 6);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T2PWMCON=(T2PWMCON &~(1<<1)) | (1<<1);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM21_PIN)
	PWM21_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr2PWM2Init(void) {
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));				//set up the match register. no interrupt yet
	T2EMR=	(T2EMR & ~(0x03 << 8)) |
			(0x02 << 8);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T2PWMCON=(T2PWMCON &~(1<<2)) | (1<<2);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM22_PIN)
	PWM22_PIN();								//enable the output pin
#endif
}

//generate pwm output - this resets the pwm period
void tmr2PWM3Init(void) {
	//don't enable interrupt
	T2MCR= 	(T2MCR & ~(0x07 << (3*3))) |
				(0x02 << (3*3));				//set up the match register. 2: reset on match, no interrupt yet
	T2EMR=	(T2EMR & ~(0x03 <<10)) |
			(0x00 <<10);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T2PWMCON=(T2PWMCON &~(1<<3)) | (1<<3);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM23_PIN)
	PWM23_PIN();								//enable the output pin
#endif
}

//end timer2

//set up timer3
//systick handler - to provide time base for millis()/micros()
//pointer to user handler
static void (* _t3mr0_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3mr1_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3mr2_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3mr3_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3ic0_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3ic1_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3ic2_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler
static void (* _t3ic3_ptr)(void)=empty_handler;				//tmr3_ptr pointing to empty_handler

//shadow period registers - 16-bit timer
static uint32_t _t3pr0=0x0000;				//mr0 fixed at 0xfffffffful/0x00000000ul
static uint32_t _t3pr1=0x0000;
static uint32_t _t3pr2=0x0000;
static uint32_t _t3pr3=0x0000;

//timer1 isr
void __irq T3ISR(void) {
	//match channel 0
	if (T3IR & (1<<0)) {
		T3IR = 1<<0;						//clear the flag by writing 1 to it
		T3MR0+= _t3pr0;						//update match register
		_t3mr0_ptr();						//execute user handler
	}

	//match channel 1
	if (T3IR & (1<<1)) {
		T3IR = 1<<1;						//clear the flag by writing 1 to it
		T3MR1+= _t3pr1;						//update match register
		_t3mr1_ptr();						//execute user handler
	}

	//match channel 2
	if (T3IR & (1<<2)) {
		T3IR = 1<<2;						//clear the flag by writing 1 to it
		T3MR2+= _t3pr2;						//update match register
		_t3mr2_ptr();						//execute user handler
	}

	//match channel 3
	if (T3IR & (1<<3)) {
		T3IR = 1<<3;						//clear the flag by writing 1 to it
		T3MR3+= _t3pr3;						//update match register
		_t3mr3_ptr();						//execute user handler
	}

	//input capture 0
	if (T3IR & (1<<4)) {
		T3IR = 1<<4;						//clear the flag by writing 1 to it
		_t3ic0_ptr();						//execute user handler
	}

	//input capture 1
	if (T3IR & (1<<5)) {
		T3IR = 1<<5;						//clear the flag by writing 1 to it
		_t3ic1_ptr();						//execute user handler
	}

	//input capture 2
	if (T3IR & (1<<6)) {
		T3IR = 1<<6;						//clear the flag by writing 1 to it
		_t3ic2_ptr();						//execute user handler
	}

	//input capture 3
	if (T3IR & (1<<7)) {
		T3IR = 1<<7;						//clear the flag by writing 1 to it
		_t3ic3_ptr();						//execute user handler
	}
	
	VICVectAddr = 0x00000000; 				//Dummy write to signal end of interrupt
}

//initialize timer0
void tmr3Init(void) {
	PCONP |= 1<<23;				//enable clock: 1: timer0, 2: timer1, 22: timer2, 23: timer3

	//configure timer0 mr0 channel as systick generator
	//stop the timer
	T3TCR = 1<<1;				//1=reset and disable the timer

	T3CTCR = 0;					//0->timer mode
	T3TCR&=~0x03;				//reset bit 1..0->count on rising edge of pclk
	T3TC = 0;					//reset counter - optional
	T3PC = 0;					//reset prescaler counter to 0
	T3PR = 0;					//set prescaler to 1:1
	T3MCR= 0;	//(T3MCR & ~(0x07 << (3*0))) |
				//(0x00 << (3*0));	//set up the match register. no interrupt yet
	T3TCR = 1;					//start the timer
}

//input capture
//install user handler for IC0
void tmr3IC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3ic0_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<4;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T3CTCR = (T3CTCR & ~(0x03 << 2)) | (0 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T3CCR= 	(T3CCR & ~(0x07 << (3*0))) |
			(0x01 << (3*0)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*0));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC30_PIN)
	IC30_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC1
void tmr3IC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3ic1_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<5;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T3CTCR = (T3CTCR & ~(0x03 << 2)) | (1 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T3CCR= 	(T3CCR & ~(0x07 << (3*1))) |
			(0x01 << (3*1)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*1));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC31_PIN)
	IC31_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC2
void tmr3IC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3ic2_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<6;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T3CTCR = (T3CTCR & ~(0x03 << 2)) | (2 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T3CCR= 	(T3CCR & ~(0x07 << (3*2))) |
			(0x01 << (3*2)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*2));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC32_PIN)
	IC32_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer0 Interrupt. turn on irq4
}

//install user handler for IC3
void tmr3IC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3ic3_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<7;								//4=IC0, 5=IC1, 6=IC2, 7=IC3
	//timer in timer mode
	//T3CTCR = (T3CTCR & ~(0x03 << 2)) | (3 << 2);//0->use CAPn.0, 1->use CAPn.1, 2->use CAPn.2, 3->use CAPn.3
	//configure capture mode
	//set up the match register. enable interrupt on match
	T3CCR= 	(T3CCR & ~(0x07 << (3*3))) |
			(0x01 << (3*3)) |					//0->disabled, 1->rising edge, 2->falling edge
			(0x04 << (3*0));					//0->disable interrput, 4->enable interrupt

	//configure the capture pin
#if defined(IC33_PIN)
	IC33_PIN();									//route pin to this block
#endif

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer0 Interrupt. turn on irq4
}

//output compare
//set up the match channels
void tmr3OC0SetPR(uint32_t pr) {
	//clear the flag
	T3IR = 1<<0;							//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));			//set up the match register. no interrupt yet
	T3MR0= _t3pr0 = pr - 0;

}

//read timer period
uint32_t tmr3OC0GetPR(void) {
	return _t3pr0;
}

//install user handler
void tmr3OC0AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3mr0_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<0;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*0))) |
				(0x01 << (3*0));	//set up the match register. interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer0 Interrupt. turn on irq4

}

//set up the match
void tmr3OC1SetPR(uint32_t pr) {
	//clear the flag
	T3IR = 1<<1;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));	//set up the match register. no interrupt yet
	T3MR1= _t3pr1 = pr - 0;

}

//read timer period
uint32_t tmr3OC1GetPR(void) {
	return _t3pr1;
}

//install user handler
void tmr3OC1AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3mr1_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<1;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*1))) |
				(0x01 << (3*1));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer0 Interrupt. turn on irq4
}

//set up the match
void tmr3OC2SetPR(uint32_t pr) {
	//clear the flag
	T3IR = 1<<2;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));	//set up the match register. no interrupt yet
	T3MR2= _t3pr2 = pr - 0;

}

//read timer period
uint32_t tmr3OC2GetPR(void) {
	return _t3pr2;
}

//install user handler
void tmr3OC2AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3mr2_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<2;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*2))) |
				(0x01 << (3*2));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer1 Interrupt. turn on irq5
}

//set up the match
void tmr3OC3SetPR(uint32_t pr) {
	//clear the flag
	T3IR = 1<<3;					//0=mr0, 1=mr1, 2=mr2, 3=mr3
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*3))) |
				(0x00 << (3*3));	//set up the match register. no interrupt yet
	T3MR3= _t3pr3 = pr - 0;

}

//read timer period
uint32_t tmr3OC3GetPR(void) {
	return _t3pr3;
}

//install user handler
void tmr3OC3AttachISR(void (*isr_ptr)(void)) {
	//install user handler
	_t3mr3_ptr = isr_ptr;

	//clear the flag
	T3IR = 1<<3;					//0=MR0, 1=MR1, 2=MR2, 3=MR3
	//enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*3))) |
				(0x01 << (3*3));	//set up the match register. enable interrupt on match

	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 27 used for tmr3
	VICVectAddr15 = (uint32_t )T3ISR;      		// set interrupt vector in 0
  	VICVectCntl15 = (1<<5) | 27;				// use it for Timer 1 Interrupt. irq5 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<27);						// Enable Timer1 Interrupt. turn on irq5
}

//generate pwm output
void tmr3PWM0Init(void) {
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*0))) |
				(0x00 << (3*0));				//set up the match register. no interrupt yet
	T3EMR=	(T3EMR & ~(0x03 << 4)) |
			(0x02 << 4);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T3PWMCON=(T3PWMCON &~(1<<0)) | (1<<0);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM30_PIN)
	PWM30_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr3PWM1Init(void) {
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*1))) |
				(0x00 << (3*1));				//set up the match register. no interrupt yet
	T3EMR=	(T3EMR & ~(0x03 << 6)) |
			(0x02 << 6);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T3PWMCON=(T3PWMCON &~(1<<1)) | (1<<1);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM31_PIN)
	PWM31_PIN();								//enable the output pin
#endif
}

//generate pwm output
void tmr3PWM2Init(void) {
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*2))) |
				(0x00 << (3*2));				//set up the match register. no interrupt yet
	T3EMR=	(T3EMR & ~(0x03 << 8)) |
			(0x02 << 8);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T3PWMCON=(T3PWMCON &~(1<<2)) | (1<<2);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM32_PIN)
	PWM32_PIN();								//enable the output pin
#endif
}

//generate pwm output - this resets the pwm period
void tmr3PWM3Init(void) {
	//don't enable interrupt
	T3MCR= 	(T3MCR & ~(0x07 << (3*3))) |
				(0x02 << (3*3));				//set up the match register. 2: reset on match, no interrupt yet
	T3EMR=	(T3EMR & ~(0x03 <<10)) |
			(0x00 <<10);						//0->do nothing, 1->clear on match, 2->set on match, 3->toggle
	T3PWMCON=(T3PWMCON &~(1<<3)) | (1<<3);		//1->enable pwm, 0->disable pwm

	//enable the output pin
#if defined(PWM33_PIN)
	PWM33_PIN();								//enable the output pin
#endif
}
//end timer3
#endif 	//__LPC2103_H

//initialize analog write output
void analogWriteInit(PIN_TypeDef pin) {
	switch (pin) {
		case  P03: tmr0PWMInit(); tmr0PWM0Init(); break;	//mat0.0 on P0.3
		case  P05: tmr0PWMInit(); tmr0PWM1Init(); break;	//mat0.1 on P0.5
		case P016: tmr0PWMInit(); tmr0PWM2Init(); break;	//mat0.2 on P0.16
		//mat0.3 not pinned out
		case P012: tmr1PWMInit(); tmr1PWM0Init(); break;	//mat1.0 on P0.12
		case P013: tmr1PWMInit(); tmr1PWM1Init(); break;	//mat1.1 on P0.13
		case P019: tmr1PWMInit(); tmr1PWM2Init(); break;	//mat1.2 on P0.19
		case P020: tmr1PWMInit(); tmr1PWM3Init(); break;	//mat1.3 on P0.20
		case  P07: tmr2PWMInit(); tmr2PWM0Init(); break;	//mat2.0 on P0.7
		case  P08: tmr2PWMInit(); tmr2PWM1Init(); break;	//mat2.1 on P0.8
		case  P09: tmr2PWMInit(); tmr2PWM2Init(); break;	//mat2.2 on P0.9
		//mat2.3 not pinned out
		case P021: tmr3PWMInit(); tmr3PWM0Init(); break;	//mat3.0 on P0.21
		case  P00: tmr3PWMInit(); tmr3PWM1Init(); break;	//mat3.1 on P0.0
		case  P01: tmr3PWMInit(); tmr3PWM2Init(); break;	//mat3.2 on P0.1
		case P030: tmr3PWMInit(); tmr3PWM3Init(); break;	//mat3.3 on P0.30
	}
}

//arduino style analog output
void analogWrite(PIN_TypeDef pin, uint32_t dc) {
	switch (pin) {
		case  P03: tmr0PWM0SetDC(dc); break;	//mat0.0 on P0.3
		case  P05: tmr0PWM1SetDC(dc); break;	//mat0.1 on P0.5
		case P016: tmr0PWM2SetDC(dc); break;	//mat0.2 on P0.16
		//mat0.3 not pinned out
		case P012: tmr1PWM0SetDC(dc); break;	//mat1.0 on P0.12
		case P013: tmr1PWM1SetDC(dc); break;	//mat1.1 on P0.13
		case P019: tmr1PWM2SetDC(dc); break;	//mat1.2 on P0.19
		case P020: tmr1PWM3SetDC(dc); break;	//mat1.3 on P0.20
		case  P07: tmr2PWM0SetDC(dc); break;	//mat2.0 on P0.7
		case  P08: tmr2PWM1SetDC(dc); break;	//mat2.1 on P0.8
		case  P09: tmr2PWM2SetDC(dc); break;	//mat2.2 on P0.9
		//mat2.3 not pinned out
		case P021: tmr3PWM0SetDC(dc); break;	//mat3.0 on P0.21
		case  P00: tmr3PWM1SetDC(dc); break;	//mat3.1 on P0.0
		case  P01: tmr3PWM2SetDC(dc); break;	//mat3.2 on P0.1
		case P030: tmr3PWM3SetDC(dc); break;	//mat3.3 on P0.30
	}
}

//uart0
//uart0 tx isr
void u0tx_isr(void) {
	
	//ux transmit isr
	//'\0' is now transmitted
	//void _ISR _U1TXInterrupt(void) {
	//char tmp;
	//TX only, RX not implemented
	//IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
	if (*_U0TX_ptr) {					//0 indicates the end of the string
		//_UxTX_ptr;					//increment to the next char
		//tmp = *_UxTX_ptr++; UxTXREG = tmp;
		U0THR = *_U0TX_ptr++;			//load up a char to be transmitted
		//NOP();
		//IFS1bits.U1TXIF = 0;			//UxTXIF = 0;						//clear the flag
	} else {
		//UxSTA.UTXEN = 0;				//turn off the transmission
		//VICIntEnClr = 1<<6;			//IEC1bits.U1TXIE = 0;			//UxTXIE = 0;						//disable the interrupt
		U0IER &=~(1<<1);				//disable the thre interrupt
		//_U1TX_BUSY = 0;				//transmission done
	}
}

//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart0Init(uint32_t bps) {
	uint32_t DLL, DIV, MUL, baudrate; int32_t error;						//uart parameters + error rate, x 100, for integer dividers
	uint32_t DLL_f, DIV_f, MUL_f, baudrate_f; int32_t error_f;				//uart parameters + error rate, x 100, for fractional dividers
	uint32_t /*DLL_f1, */DIV_f1, MUL_f1, baudrate_f1; int32_t error_f1;			//uart parameters + error rate, x 100, for fractional dividers

	PCONP |= 1<<3;				//enable clock: 3: uart0, 4: uart1

	//configure the pins
    // Change P0.2/TXD0 and P0.3/RXD0 mode '0b01'
	//LPC_PINCON->PINSEL0 = (LPC_PINCON->PINSEL0 &~(0b11 << 4)) | (0b01 << 4);	//'0b01'->P0.2 to TXD0
	//LPC_PINCON->PINSEL0 = (LPC_PINCON->PINSEL0 &~(0b11 << 6)) | (0b01 << 6);	//'0b01'->P0.3 to RXD0
#if defined(U0TX_PIN)
	U0TX_PIN();					//enable TX pin output
#endif

#if defined(U0RX_PIN)
	U0RX_PIN();				  	//enable RX pin input
#endif

	//enable power to uart
	//LPC_SC->PCONP |= (1<<3);							//3=uart0, 4=uart1, 24=uart2, 25=uart3
	//LPC_SC->PCLKSEL0 = (LPC_SC->PCLKSEL0 &~(0b11<<6)) | (0b00 << 6);	//PCLKSEL0: 6=uart0, 8=uart1. 0b00=4:1,0b01=1:1, 0b10=2:1, 0b11=8:1
	//LPC_SC->PCLKSEL1 = (LPC_SC->PCLKSEL1 &~(0b11<<16)) | (0b00 << 16);	//PCLKSEL1: 16=uart2, 18=uart3. 0b00=4:1,0b01=1:1, 0b10=2:1, 0b11=8:1

	//find out F_UART
	//switch ((LPC_SC->PCLKSEL0 >> 6) & 0b11) {
	//case 0b00: F_UART = F_CPU / 4; break;
	//case 0b01: F_UART = F_CPU / 1; break;
	//case 0b10: F_UART = F_CPU / 2; break;
	//case 0b11: F_UART = F_CPU / 8; break;
	//}

    //calculate error rate for integer dividers
	DLL = F_UART / 16 / bps;						//divider, 16-bits
	DIV = 0; MUL = 1;								//set div/mul
	baudrate = F_UART / 16 * 100 / DLL / (MUL +  DIV) * MUL;	//baud rate, x100
	error = bps * 100 - baudrate;					//error, x100
	if (error < 0) error = - error;					//only compare positive numbers

	//calculate error rate for fractional dividers
	DLL_f = F_UART / 16 / bps * 10 / 15;			//estimate divider to 1.5x
	DIV_f = 0; MUL_f = 1;							//set div/mul
	baudrate_f = F_UART / 16 * 100 / DLL_f / (MUL_f + DIV_f) * MUL_f;	//baud rate, x100
	error_f = bps * 100 - baudrate_f;				//error, x100
	if (error_f < 0) error_f = -error_f;			//only compare positive numbers

	for (MUL_f1 = 2; MUL_f1 < 16; MUL_f1 ++ ) {		//MUL_f = [1..15]
		for (DIV_f1 = 0; DIV_f1 < MUL_f1; DIV_f1++) {		//DIV_f = [0..MUL_f-1]
			baudrate_f1 = F_UART / 16 * 100 / DLL_f / (MUL_f1 + DIV_f1) * MUL_f1;	//baud rate, x100
			error_f1 = bps * 100 - baudrate_f1;		//error, x100
			if (error_f1 < 0) error_f1 = -error_f1;	//only compare positive numbers
			//save the optimal dividers for fractional dividers
			if (error_f1 < error_f) {DIV_f = DIV_f1; MUL_f = MUL_f1; error_f = error_f1;}
		}
	}

	//now compare integer dividers vs. the optimal fractional dividers and find the best settings
	if (error_f < error) {DLL = DLL_f; DIV = DIV_f; MUL = MUL_f;}

	//now, DLL, DIV and MUL contain the best settings

	//now set up the uart: 8 data bits, 1 stop bit, no parity
	U0IER = 0;									//disable all interrupts
	U0TER = 0;									//0->disable transmission
	U0ACR = 0;									//disable auto baud rate
	U0LCR = (0x03<<0) |						//'0b11'->8-bit data
			(0<<2) |						//'0'->1stop bit, '1'->2 stop bits
			(0<<3) |						//'0'->disable parity
			(0x00<<4) |						//'0b00'->odd parity
			(0<<6) |						//'0'->disable break transmission
			(1<<7) |						//'1'->enable access to divisor latch, 0->disable access
			0x00;
	U0FDR = (DIV & 0x0f) |					//divider
			((MUL & 0x0f) << 4) |			//multiplier
			0x00;
	U0DLL = 	(DLL & 0xff);					//DLL's lsb
	U0DLM = 	(DLL >> 8) & 0xff;				//DLL's msb
	U0LCR&=~(1<<7);							//disable divisor latch by clearing bit 7
	U0FCR = 	(1<<0) |						//'1'->enable fifo
				(1<<1) |						//'1'->reset rx fifo - self-clearing
				(1<<2) |						//'1'->reset tx fifo - self-clearing
				(0<<3) |						//'0'->disable DMA
				(0x00<<6) |						//'0b00'->dma trigger level 0
				0x00;
	U0TER = (1<<7);								//enable transmission

#if defined(USE_U0TXISR)
	U0IIR;								//clear the flag by reading it
	U0IER &=~(1<<1);					//1->enable tx interrupt, 0->disable tx interrupt
	//enable non-vectored irq -> no priority etc.
	//VICDefVectAddr = (uint32_t )DefISR; // set interrupt vector in DefISR
	//VICVectCntl5 = (1<<5) | 5;		// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
	VICIntEnable = (1<<6);				// Enable uart0 Interrupt. 6 for uart0, 7 for uart1
	//IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
#endif

}

void uart0Putch(char ch) {
	while (uart0Busy()) continue;				//wait for transmission to free up
	U0THR = ch;									//start transmission
}

//put a string
void uart0Puts(char *str) {
#if defined(USE_U0TXISR)
	//interrupt transmission
	if (*str) {								//if the string isn't empty to begin with
		uart0Wait();						//for compatability with polling transmission
		//U1TXREG = 0;						//clear the buffer
		//_U1TX_BUSY  = 1;					//transmission in progress
		_U0TX_ptr=str;						//point to the string to be transmitted
		U0IIR;								//read U0IIR to clear the flag	IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
		//U1STAbits.UTXEN = 1;				//enable transmission - always enabled
		//tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
		U0THR = *_U0TX_ptr++;				//send the first char
		//enable non-vectored irq -> no priority etc.
		//VICDefVectAddr = (uint32_t )DefISR; // set interrupt vector in DefISR
	  	//VICVectCntl5 = (1<<5) | 5;		// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
	  	//VICIntEnable = (1<<6);			// Enable uart0 Interrupt.
		//IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
		U0IER |= 1<<1;						//1->enable tx interrupt, 0->disable tx interrupt
	}
	
#else
	while (*str) uart0Putch(*str++);
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
void uart0Putline(char *ln) {
	//USARTWriteString(ln);
	uart0Puts(ln);
	//USARTWriteString("\r\n");
	uart0Puts((char *)"\r\n");
}

//get the received char
//uint8_t uartGetch(void) {
//	    return LPC_UART0->RBR;                       	//save the transmission buffer
//}

//test if data rx is available
//uint16_t uartAvailable(void) {
//	return LPC_UART0->LSR & (1<<0);						//'1'->the receiver has an unread char
//}

//test if uart tx is busy
//uint16_t uartBusy(void) {
//	return ~LPC_UART0->LSR & (1<<5);					//'1'@5 -> transmission buffer empty. '1'@6->transmission complete
//}

//print to uart1
void u0Print(char *str, int32_t dat) {
	static char uRAM[uRAM_SIZE];						//transmission buffer, 40-1 char max

	uart0Wait();										//wait for prior transmission to end
	strcpy(uRAM, str);					//copy to uarm
	if (dat < 0) {uRAM[6]='-'; dat = -dat;}
	uRAM[19]='0'+(dat % 10); dat /= 10;
	uRAM[18]='0'+(dat % 10); dat /= 10;
	uRAM[17]='0'+(dat % 10); dat /= 10;
	uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[15]='0'+(dat % 10); dat /= 10;
	uRAM[14]='0'+(dat % 10); dat /= 10;
	uRAM[13]='0'+(dat % 10); dat /= 10;
	uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[11]='0'+(dat % 10); dat /= 10;
	uRAM[10]='0'+(dat % 10); dat /= 10;
	uRAM[ 9]='0'+(dat % 10); dat /= 10;
	uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[ 7]='0'+(dat % 10); dat /= 10;
	uart0Puts(uRAM);	//send a message on uart1
}

//uart1
//uart1 tx isr
void u1tx_isr(void) {
	
	//ux transmit isr
	//'\0' is now transmitted
	//void _ISR _U1TXInterrupt(void) {
	//char tmp;
	//TX only, RX not implemented
	//IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
	if (*_U1TX_ptr) {					//0 indicates the end of the string
		//_UxTX_ptr;					//increment to the next char
		//tmp = *_UxTX_ptr++; UxTXREG = tmp;
		U1THR = *_U1TX_ptr++;			//load up a char to be transmitted
		//NOP();
		//IFS1bits.U1TXIF = 0;			//UxTXIF = 0;						//clear the flag
	} else {
		//UxSTA.UTXEN = 0;				//turn off the transmission
		//VICIntEnClr = 1<<6;			//IEC1bits.U1TXIE = 0;			//UxTXIE = 0;						//disable the interrupt
		U1IER &=~(1<<1);				//disable the thre interrupt
		//_U1TX_BUSY = 0;				//transmission done
	}
}

//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart1Init(uint32_t bps) {
	uint32_t DLL, DIV, MUL, baudrate; int32_t error;						//uart parameters + error rate, x 100, for integer dividers
	uint32_t DLL_f, DIV_f, MUL_f, baudrate_f; int32_t error_f;				//uart parameters + error rate, x 100, for fractional dividers
	uint32_t /*DLL_f1, */DIV_f1, MUL_f1, baudrate_f1; int32_t error_f1;			//uart parameters + error rate, x 100, for fractional dividers

	PCONP |= 1<<4;				//enable clock: 3: uart0, 4: uart1

	//configure the pins
    // Change P0.2/TXD0 and P0.3/RXD0 mode '0b01'
	//LPC_PINCON->PINSEL0 = (LPC_PINCON->PINSEL0 &~(0b11 << 4)) | (0b01 << 4);	//'0b01'->P0.2 to TXD0
	//LPC_PINCON->PINSEL0 = (LPC_PINCON->PINSEL0 &~(0b11 << 6)) | (0b01 << 6);	//'0b01'->P0.3 to RXD0
#if defined(U1TX_PIN)
	U1TX_PIN();					//enable TX pin output
#endif

#if defined(U1RX_PIN)
	U1RX_PIN();				  	//enable RX pin input
#endif

	//enable power to uart
	//LPC_SC->PCONP |= (1<<3);							//3=uart0, 4=uart1, 24=uart2, 25=uart3
	//LPC_SC->PCLKSEL0 = (LPC_SC->PCLKSEL0 &~(0b11<<6)) | (0b00 << 6);	//PCLKSEL0: 6=uart0, 8=uart1. 0b00=4:1,0b01=1:1, 0b10=2:1, 0b11=8:1
	//LPC_SC->PCLKSEL1 = (LPC_SC->PCLKSEL1 &~(0b11<<16)) | (0b00 << 16);	//PCLKSEL1: 16=uart2, 18=uart3. 0b00=4:1,0b01=1:1, 0b10=2:1, 0b11=8:1

	//find out F_UART
	//switch ((LPC_SC->PCLKSEL0 >> 6) & 0b11) {
	//case 0b00: F_UART = F_CPU / 4; break;
	//case 0b01: F_UART = F_CPU / 1; break;
	//case 0b10: F_UART = F_CPU / 2; break;
	//case 0b11: F_UART = F_CPU / 8; break;
	//}

    //calculate error rate for integer dividers
	DLL = F_UART / 16 / bps;						//divider, 16-bits
	DIV = 0; MUL = 1;								//set div/mul
	baudrate = F_UART / 16 * 100 / DLL / (MUL +  DIV) * MUL;	//baud rate, x100
	error = bps * 100 - baudrate;					//error, x100
	if (error < 0) error = - error;					//only compare positive numbers

	//calculate error rate for fractional dividers
	DLL_f = F_UART / 16 / bps * 10 / 15;			//estimate divider to 1.5x
	DIV_f = 0; MUL_f = 1;							//set div/mul
	baudrate_f = F_UART / 16 * 100 / DLL_f / (MUL_f + DIV_f) * MUL_f;	//baud rate, x100
	error_f = bps * 100 - baudrate_f;				//error, x100
	if (error_f < 0) error_f = -error_f;			//only compare positive numbers

	for (MUL_f1 = 2; MUL_f1 < 16; MUL_f1 ++ ) {		//MUL_f = [1..15]
		for (DIV_f1 = 0; DIV_f1 < MUL_f1; DIV_f1++) {		//DIV_f = [0..MUL_f-1]
			baudrate_f1 = F_UART / 16 * 100 / DLL_f / (MUL_f1 + DIV_f1) * MUL_f1;	//baud rate, x100
			error_f1 = bps * 100 - baudrate_f1;		//error, x100
			if (error_f1 < 0) error_f1 = -error_f1;	//only compare positive numbers
			//save the optimal dividers for fractional dividers
			if (error_f1 < error_f) {DIV_f = DIV_f1; MUL_f = MUL_f1; error_f = error_f1;}
		}
	}

	//now compare integer dividers vs. the optimal fractional dividers and find the best settings
	if (error_f < error) {DLL = DLL_f; DIV = DIV_f; MUL = MUL_f;}

	//now, DLL, DIV and MUL contain the best settings

	//now set up the uart: 8 data bits, 1 stop bit, no parity
	U1IER = 0;									//disable all interrupts
	U1TER = 0;									//0->disable transmission
	U1ACR = 0;									//disable auto baud rate
	U1LCR = (0x03<<0) |						//'0b11'->8-bit data
			(0<<2) |						//'0'->1stop bit, '1'->2 stop bits
			(0<<3) |						//'0'->disable parity
			(0x00<<4) |						//'0b00'->odd parity
			(0<<6) |						//'0'->disable break transmission
			(1<<7) |						//'1'->enable access to divisor latch
			0x00;
	U1FDR = (DIV & 0x0f) |						//divider
			((MUL & 0x0f) << 4) |				//multiplier
			0x00;
	U1DLL = 	(DLL & 0xff);					//DLL's lsb
	U1DLM = 	(DLL >> 8) & 0xff;				//DLL's msb
	U1LCR&=~(1<<7);								//disable divisor latch by clearing bit 7
	U1FCR = 	(1<<0) |						//'1'->enable fifo
				(1<<1) |						//'1'->reset rx fifo - self-clearing
				(1<<2) |						//'1'->reset tx fifo - self-clearing
				(0<<3) |						//'0'->disable DMA
				(0x00<<6) |						//'0b00'->dma trigger level 0
				0x00;
	U1TER = (1<<7);								//enable transmission

#if defined(USE_U1TXISR)
	U1IIR;								//clear the flag by reading it
	U1IER &=~(1<<1);					//1->enable tx interrupt, 0->disable tx interrupt
	//enable non-vectored irq -> no priority etc.
	//VICDefVectAddr = (uint32_t )DefISR; // set interrupt vector in DefISR
	//VICVectCntl5 = (1<<5) | 5;		// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
	VICIntEnable = (1<<7);				// Enable uart0 Interrupt. 6 for uart0, 7 for uart1
	//IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
#endif

}

void uart1Putch(char ch) {
	while (uart1Busy()) continue;				//wait for transmission to free up
	U1THR = ch;									//start transmission
}

//put a string
void uart1Puts(char *str) {
#if defined(USE_U1TXISR)
	//interrupt transmission
	if (*str) {								//if the string isn't empty to begin with
		uart1Wait();						//for compatability with polling transmission
		//U1TXREG = 0;						//clear the buffer
		//_U1TX_BUSY  = 1;					//transmission in progress
		_U1TX_ptr=str;						//point to the string to be transmitted
		U1IIR;								//read U0IIR to clear the flag	IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
		//U1STAbits.UTXEN = 1;				//enable transmission - always enabled
		//tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
		U1THR = *_U1TX_ptr++;				//send the first char
		//enable non-vectored irq -> no priority etc.
		//VICDefVectAddr = (uint32_t )DefISR; // set interrupt vector in DefISR
	  	//VICVectCntl5 = (1<<5) | 5;		// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
	  	//VICIntEnable = (1<<6);			// Enable uart0 Interrupt.
		//IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
		U1IER |= 1<<1;						//1->enable tx interrupt, 0->disable tx interrupt
	}
	
#else
	while (*str) uart1Putch(*str++);
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
void uart1Putline(char *ln) {
	//USARTWriteString(ln);
	uart1Puts(ln);
	//USARTWriteString("\r\n");
	uart1Puts((char *)"\r\n");
}

//get the received char
//uint8_t uartGetch(void) {
//	    return LPC_UART0->RBR;                       	//save the transmission buffer
//}

//test if data rx is available
//uint16_t uartAvailable(void) {
//	return LPC_UART0->LSR & (1<<0);						//'1'->the receiver has an unread char
//}

//test if uart tx is busy
//uint16_t uartBusy(void) {
//	return ~LPC_UART0->LSR & (1<<5);					//'1'@5 -> transmission buffer empty. '1'@6->transmission complete
//}

//print to uart1
void u1Print(char *str, int32_t dat) {
	static char uRAM[uRAM_SIZE];						//transmission buffer, 40-1 char max

	uart1Wait();										//wait for prior transmission to end
	strcpy(uRAM, str);					//copy to uarm
	if (dat < 0) {uRAM[6]='-'; dat = -dat;}
	uRAM[19]='0'+(dat % 10); dat /= 10;
	uRAM[18]='0'+(dat % 10); dat /= 10;
	uRAM[17]='0'+(dat % 10); dat /= 10;
	uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[15]='0'+(dat % 10); dat /= 10;
	uRAM[14]='0'+(dat % 10); dat /= 10;
	uRAM[13]='0'+(dat % 10); dat /= 10;
	uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[11]='0'+(dat % 10); dat /= 10;
	uRAM[10]='0'+(dat % 10); dat /= 10;
	uRAM[ 9]='0'+(dat % 10); dat /= 10;
	uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[ 7]='0'+(dat % 10); dat /= 10;
	uart1Puts(uRAM);	//send a message on uart1
}

//end Serial

//exint0..2
//pointer to user handler
static void (* _eint0_ptr)(void)=empty_handler;				//eint0 pointing to empty_handler
static void (* _eint1_ptr)(void)=empty_handler;				//eint1 pointing to empty_handler
static void (* _eint2_ptr)(void)=empty_handler;				//eint2 pointing to empty_handler
//static void (* _eint3_ptr)(void)=empty_handler;				//eint3 pointing to empty_handler

//vector's isr for eint0
void __irq EINT0ISR(void) {
	EXTINT |= (1<<0);					//1->clear the flag
	_eint0_ptr();						//execute the usr isr
}

//initialize int0
//always edge sensitive
//pol = RISING -> rising edge
//pol = FALLING-> falling
void int0Init(int pol) {
	//eint0 at 14, eint1 at 15, eint2 at 16
	VICIntEnClr = 1<<14;				//disable the interrupt
	EXTMODE = 	(EXTMODE & ~(0x01 << 0)) |	//clear the bits
				(1 << 0);					//0->level sensitive, 1->edge sensitive
	EXTPOLAR=	(EXTPOLAR& ~(0x01 << 0)) |	//clear the bit
				(((pol==RISING)?1:0) << 0);	//0->falling edge, !0->rising edge
	//enable the pin
#if defined(INT0_PIN)
	INT0_PIN();								//enable INT0 pin
#endif
}

//install user isr
void int0AttachISR(void (* isr_ptr)(void)) {
	_eint0_ptr = isr_ptr;				//install the user isr
	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 11 used for eint0, 12 for eint1, 13 for eint2
	VICVectAddr11 = (uint32_t )EINT0ISR;      		// set interrupt vector in 0
  	VICVectCntl11 = (1<<5) | 14;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<14);							// Enable Timer0 Interrupt. turn on irq4

}

//vector's isr for eint1
void __irq EINT1ISR(void) {
	EXTINT |= (1<<1);					//1->clear the flag
	_eint1_ptr();						//execute the usr isr
}

//always edge sensitive
//pol = 1-> rising edge
//pol = 0-> falling
void int1Init(int pol) {
	//eint0 at 14, eint1 at 15, eint2 at 16
	VICIntEnClr = 1<<15;						//disable the interrupt
	EXTMODE = 	(EXTMODE & ~(0x01 << 1)) |		//clear the bits
				(1 << 1);					//0->level sensitive, 1->edge sensitive
	EXTPOLAR=	(EXTPOLAR& ~(0x01 << 1)) |	//clear the bit
				(((pol==RISING)?1:0) << 1);	//0->falling edge, !0->rising edge
	//enable the pin
#if defined(INT1_PIN)
	INT1_PIN();								//enable INT1 pin
#endif
}

//install user isr
void int1AttachISR(void (* isr_ptr)(void)) {
	_eint1_ptr = isr_ptr;						//install the user isr
	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 11 used for eint0, 12 for eint1, 13 for eint2
	VICVectAddr12 = (uint32_t )EINT1ISR;      		// set interrupt vector in 0
  	VICVectCntl12 = (1<<5) | 15;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<15);							// Enable Timer0 Interrupt. turn on irq4

}

//vector's isr for eint2
void __irq EINT2ISR(void) {
	EXTINT |= (1<<4);					//1->clear the flag
	_eint2_ptr();						//execute the usr isr
}

//always edge sensitive
//pol = 1-> rising edge
//pol = 0-> falling
void int2Init(int pol) {
	//eint0 at 14, eint1 at 15, eint2 at 16
	VICIntEnClr = 1<<16;						//disable the interrupt
	EXTMODE = 	(EXTMODE & ~(0x01 << 2)) |		//clear the bits
				(1 << 2);				//0->level sensitive, 1->edge sensitive
	EXTPOLAR=	(EXTPOLAR& ~(0x01 << 2)) |	//clear the bit
				(((pol==RISING)?1:0) << 2);	//0->falling edge, !0->rising edge
	//enable the pin
#if defined(INT2_PIN)
	INT2_PIN();								//enable INT2 pin
#endif
}

//install user isr
void int2AttachISR(void (* isr_ptr)(void)) {
	_eint2_ptr = isr_ptr;						//install the user isr
	//enable irq -> no priority etc.
	//NVIC_EnableIRQ(CTx_IRQn);
	//vector 11 used for eint0, 12 for eint1, 13 for eint2
	VICVectAddr13 = (uint32_t )EINT2ISR;      		// set interrupt vector in 0
  	VICVectCntl13 = (1<<5) | 16;					// use it for Timer 0 Interrupt. irq4 + enable bits (0x20, bit 5)
  	VICIntEnable = (1<<16);							// Enable Timer0 Interrupt. turn on irq4

}


//end exint0..2

//analog initialized
void adcInit(void) {
	PCONP |= 1<<12;									//1->enable clock to adc, 0->disable clock to adc

	ADCR =	(0<<0) |								//select adc channels: 1<<0->AD0, 1<<7->AD7. only one bit can be set
			//(((F_PHB/4500000ul)?(F_PHB / 4500000ul):1)<<8)| //clock divider, F_ADC < 4.5Mhz. clock divider is at least 1
			((F_PHB / 4500000ul)<<8)| 				//clock divider, F_ADC < 4.5Mhz. clock divider can be 0x00
			(0<<16) |								//1->repeat conversions, 0->burst conversion
			(0<<17) |								//0->11 clocks/10 bits, 1->10 clocks/9 bits...
			(1<<21) |								//1->adc module operational, 0->adc module powered down
			(0<<24) |								//1->start adc, 0->not start adc
			(0<<27) |								//not used unless bit 24..26 is 010-111
			0x00;
	//ADGDR -> not used
	ADINTEN = 0;									//0->interrupt disabled
}

//read an analog channel
uint16_t adcRead(uint8_t ch) {
	uint32_t tmp=0;

	switch (ch) {
		case ADC_CH0: PINSEL1 = (PINSEL1 &~(0x03 << 12)) | (0x03 << 12); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR0; break;	//ad0.0 on P0.22
		case ADC_CH1: PINSEL1 = (PINSEL1 &~(0x03 << 14)) | (0x03 << 14); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR1; break;	//ad0.1 on P0.23
		case ADC_CH2: PINSEL1 = (PINSEL1 &~(0x03 << 16)) | (0x03 << 16); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR2; break;	//ad0.2 on P0.24
		case ADC_CH3: PINSEL0 = (PINSEL0 &~(0x03 << 20)) | (0x03 << 20); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR3; break;	//ad0.3 on P0.10
		case ADC_CH4: PINSEL0 = (PINSEL0 &~(0x03 << 22)) | (0x03 << 22); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR4; break;	//ad0.4 on P0.11
		case ADC_CH5: PINSEL0 = (PINSEL0 &~(0x03 << 24)) | (0x03 << 24); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR5; break;	//ad0.5 on P0.12
		case ADC_CH6: PINSEL1 = (PINSEL1 &~(0x03 << 18)) | (0x03 << 18); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR6; break;	//ad0.6 on P0.25
		case ADC_CH7: PINSEL1 = (PINSEL1 &~(0x03 << 20)) | (0x03 << 20); ADCR = (ADCR &~(0x7f << 0)) | (ch << 0) | (1<<24); while ((ADGDR & (1ul<<31)) == 0) continue; tmp = ADDR7; break;	//ad0.7 on P0.26
	}
	return (tmp >> 6) & 0x3ff;
}

//read analog, arduino style
uint16_t analogRead(PIN_TypeDef pin) {
	uint32_t tmp=0;
	switch (pin) {
		case P022: tmp = adcRead(ADC_CH0); break;	//ad0.0 on P0.22
		case P023: tmp = adcRead(ADC_CH1); break;	//ad0.1 on P0.23
		case P024: tmp = adcRead(ADC_CH2); break;	//ad0.2 on P0.24
		case P010: tmp = adcRead(ADC_CH3); break;	//ad0.3 on P0.10
		case P011: tmp = adcRead(ADC_CH4); break;	//ad0.4 on P0.11
		case P012: tmp = adcRead(ADC_CH5); break;	//ad0.5 on P0.12
		case P025: tmp = adcRead(ADC_CH6); break;	//ad0.6 on P0.25
		case P026: tmp = adcRead(ADC_CH7); break;	//ad0.7 on P0.26
	}

	return tmp;
}

//end adc

//spi
//initialize spi
void spi0Init(void) {
	PCONP |= 1<<8;					//spi0: bit 8, spi1/ssp: bit 10

	S0SPCR =	(0<<2) |			//0->8bit mode, 1-> see bit 8..11
				(0<<3) |			//cpha: 0->sampled on 1st clock edge, 1->on 2nd clock edge
				(0<<4) |			//cpol: 0->sck active high, 1->active low
				(1<<5) |			//1->master mode, 0->slave mode)
				(0<<6) |			//0->msb first, 1->lsb first
				(0<<7) |			//0->disable interrupt, 1->enable interrupt
				(8<<8) |			//number of bits each transfer. 8=8bits, ...15=15 bits, 0=16bits
				0x00;
	S0SPSR = 0;						//clear the flag
	S0SPCCR = (F_PHB / F_SPI0 < 8)?8:(F_PHB / F_SPI0);	//must be at least 8
	S0SPCCR&=~(1<<0);				//must be en even number->last bit is 0
	if (S0SPCCR > 255) S0SPCCR = 255;	//this is an 8-bit number

//enable the pins
#if defined(SCLK0_PIN)			//serial clock
	SCLK0_PIN();
#endif

#if defined(SSEL0_PIN)	   		//slave select, active low
	SSEL0_PIN();
#endif

#if defined(MISO0_PIN)	 		//master in, slave out
	MISO0_PIN();
#endif

#if defined(MOSI0_PIN)			//mast out, slave in
	MOSI0_PIN();
#endif

}

uint8_t spi0Write(uint8_t dat) {
	S0SPDR = dat;				//load the data
	while (spi0Busy()) continue;	//wait for the transmission to end

	return S0SPDR;
}

//end spi

//ssp/spi1
//initialize ssp as spi1
void spi1Init(void) {
	PCONP |= 1<<10;					//spi0: bit 8, spi1/ssp: bit 10

	SSPCPSR= 	(F_PHB / F_SPI1 < 2)?2:(F_PHB / F_SPI1);	//cpsr is at least 2
	SSPCR0 =	(7<<0) |			//data transfer size. 3=4bit, 7=8bit, 15=16bit
				(0<<4) |			//framing: 0->spi, 1->ssp, 2->microwire, 3->don't use
				(0<<6) |			//cpol: 0->sck active high, 1->active low
				(0<<7) |			//cpha: 0->sampled on 1st clock edge, 1->on 2nd clock edge
				((F_PHB / SSPCPSR / F_SPI1) <<8) |			//serial clock rate
				0x00;
	SSPCR1 =	(0<<0) |			//0->normal opeartion, 1-> loop back
				(0<<1) |			//0->disable ssp, 1->enable ssp
				(0<<2) |			//0->master mode, 1->slave mode
				(0<<3) |			//0->doesn't block the ssp module, 1->block the ssp module - only meaningful as slave
				0x00;
	SSPSR = 0;						//clear the flag

//enable the pins
#if defined(SCLK1_PIN)			//serial clock
	SCLK1_PIN();
#endif

#if defined(SSEL1_PIN)	   		//slave select, active low
	SSEL1_PIN();
#endif

#if defined(MISO1_PIN)	 		//master in, slave out
	MISO1_PIN();
#endif

#if defined(MOSI1_PIN)			//mast out, slave in
	MOSI1_PIN();
#endif

}

uint8_t spi1Write(uint8_t dat) {
	SSPDR = dat;				//load the data
	while (spi1Busy()) continue;	//wait for the transmission to end

	return SSPDR;
}

//end ssp/spi1

//rtc on low speed crystal
void rtcInit(void) {
	PCONP |= 1<<9;					//1->enable clock to RTC

	//enable the rtc clock
	CCR =	(1<<0) |				//1->enable rtc
			(0<<1) |				//1->reset the rtc
			(1<<4) |				//0->clock from the prescaler, 1-> from low speed crystal
			0x00;
	//rtc now running
}

//configure rtc to use pclk
void rtcInit2PCLK(void) {
	PCONP |= 1<<9;					//1->enable clock to RTC

	//calculate the prescaler
	PREINT = F_PHB / 32768 - 1;
	PREFRAC= F_PHB - (PREINT + 1) * 32768;

	//enable the rtc clock
	CCR =	(1<<0) |				//1->enable rtc
			(0<<1) |				//1->reset the rtc
			(0<<4) |				//0->clock from the prescaler, 1-> from low speed crystal
			0x00;
	//rtc now running
}

//end rtc

//i2c

#define I2C_ACK					0					//0->ack, per i2c protocol
#define I2C_NOACK				1					//1->no ack, per i2c protocol

//initialize i2c0
//master mode only
void i2c0Init(void) {
	uint16_t div;

	PCONP |= 1<<7;					//1->enable clock. 7: i2c0, 19: i2c1

	I2C0CONCLR = 	(1<<2) |		//0->clear ack flag
					(1<<3) |		//0->clear the interrupt flag
					(1<<4) |		//0->send a stop condition
					(1<<6) |		//0->disable the i2c module
					0x00;
	
	//calculate the diver
#if 0								//a simple implementation
	div = F_PHB / F_I2C0 / 2;		//calculate the divider, 16-bit
	if (div < 4) div = 4;			//divider at least 4
	I2C0SCLH = I2C0SCLL = div; 		//equal value for SCLH/SCLL
#else								//a more accurate implementation (70 bytes more in flash :))
	div = (F_PHB + F_I2C0/2) / F_I2C0;	//rounding up
	I2C0SCLH = div/2; if (I2C0SCLH < 4) I2C0SCLH = 4;
	I2C0SCLL = div - I2C0SCLH; if (I2C0SCLL < 4) I2C0SCLL = 4;
#endif

	//I2C0STAT = 0;						//clear the flag - read only

	//configure the pins
	PINSEL0 = (PINSEL0 & (0x03 << 4)) | (0x01 << 4);	//scl0 on p0.2
	PINSEL0 = (PINSEL0 & (0x03 << 6)) | (0x01 << 6);	//sda0 on p0.3

	I2C0CONSET = 1<<6;					//1->enable the i2c module
	
}

//send data
uint8_t i2c0Write(uint8_t dat) {
	I2C0DAT = dat;						//write to i2c
	i2c0Wait();							//wait for the transmission to end
	if (I2C0STAT & (1<<8)) return I2C_ACK;
	else return I2C_NOACK;
}

//read data
uint8_t i2c0Read(uint8_t ack) {
	I2C0DAT = 0x00;
	if (ack==I2C_NOACK) i2c0NoAck();
	else i2c0Ack();
	i2c0Wait();

	return I2C0DAT;
}


//initialize i2c1
//master mode only
void i2c1Init(void) {
	uint16_t div;

	PCONP |= 1<<19;					//1->enable clock. 7: i2c0, 19: i2c1

	I2C1CONCLR = 1<<6;				//0->disable the i2c module
	
	//calculate the diver
#if 0								//a simple implementation
	div = F_PHB / F_I2C0 / 2;		//calculate the divider, 16-bit
	if (div < 4) div = 4;			//divider at least 4
	I2C1SCLH = I2C1SCLL = div; 		//equal value for SCLH/SCLL
#else								//a more accurate implementation (70 bytes more in flash :))
	div = (F_PHB + F_I2C0/2) / F_I2C0;	//rounding up
	I2C1SCLH = div/2; if (I2C1SCLH < 4) I2C0SCLH = 4;
	I2C1SCLL = div - I2C1SCLH; if (I2C1SCLL < 4) I2C1SCLL = 4;
#endif

	I2C1STAT = 0;					//clear the flag

	//configure the pins
	PINSEL1 = (PINSEL1 & (0x03 << 2)) | (0x01 << 2);	//scl1 on p0.17
	PINSEL1 = (PINSEL1 & (0x03 << 4)) | (0x01 << 4);	//sda1 on p0.18

	I2C1CONSET = 1<<6;				//1->enable the i2c module
	
}

//end i2c


#if 0
/*
MAPR Bits 7:6 TIM1_REMAP[1:0]: TIM1 remapping
These bits are set and cleared by software. They control the mapping of TIM1 channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN) on the GPIO ports.
00: No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
01: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1)
10: not used
11: Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12)
*/
//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm1Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	//source from internal clock -> disable slave mode
	TIM1->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIM1->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIM1->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIM1->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIM1->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIM1->CR1 = 0;						//much easier
	TIM1->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIM1->CR2 = 0;						//default value
	TIM1->SMCR= 0;						//default value

	//set the prescaler
	TIM1->PSC = TxCCP_PS - 1;					//set the prescaler
	TIM1->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIM1->ARR = PWM_PR;						//auto reload register / period = 0; - need to change for downcounters
	TIM1->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIM1->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIM1->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//configure CCP1..4
#if defined(TIM1CH1toGPIO)
	//configure CCP1
	TIM1->CCMR1 = 	(TIM1->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM1->CCR1 = 0;						//0% duty cycle

	//configure gpio
	TIM1CH1toGPIO();					//route TIM1CH1 to GPIO
#endif

#if defined(TIM1CH2toGPIO)
	//configure CCP2
	TIM1->CCMR1 = 	(TIM1->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM1->CCR2 = 0;						//0% duty cycle

	//configure gpio
	TIM1CH2toGPIO();					//route TIM1CH1 to GPIO
#endif

#if defined(TIM1CH3toGPIO)
	//configure CCP3
	TIM1->CCMR2 = 	(TIM1->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 8)) |
					(0<<11) |			//0->normal polarity for CC3N, 1->inverse polarity
					(0<<10) |			//0->disable CC3N, 1->enable CC3N
					(0<< 9) |			//0->normal polarity for CC3, 1->inverse polarity
					(1<< 8) |			//1->enable CC3, 0->disable CC3
					0x00;
	TIM1->CCR3 = 0;						//0% duty cycle

	//configure gpio
	TIM1CH3toGPIO();					//route TIM1CH1 to GPIO
#endif

#if defined(TIM1CH4toGPIO)
	//configure CCP4
	TIM1->CCMR2 = 	(TIM1->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 12)) |
					(0<<15) |			//0->normal polarity for CC4N, 1->inverse polarity
					(0<<14) |			//0->disable CC4N, 1->enable CC4N
					(0<<13) |			//0->normal polarity for CC4, 1->inverse polarity
					(1<<12) |			//1->enable CC4, 0->disable CC4
					0x00;
	TIM1->CCR4 = 0;						//0% duty cycle

	//configure gpio
	TIM1CH4toGPIO();					//route TIM1CH1 to GPIO
#endif

	TIM1->EGR = 0xff;					//force an update
	TIM1->BDTR|= TIM_BDTR_MOE;				//enable the main output
	//enable the timer.
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer

}


//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm3Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	//source from internal clock -> disable slave mode
	//TIM3->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIM3->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIM3->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIM3->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIM3->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIM3->CR1 = 0;						//much easier
	TIM3->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIM3->CR2 = 0;						//default value
	TIM3->SMCR= 0;						//default value - use internal clock

	//set the prescaler
	TIM3->PSC = TxCCP_PS - 1;					//set the prescaler
	TIM3->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIM3->ARR = PWM_PR;						//auto reload register / period = 0; - need to change for downcounters
	TIM3->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIM3->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIM3->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//configure CCP1..4
#if defined(TIM3CH1toGPIO)
	//configure CCP1
	TIM3->CCMR1 = 	(TIM3->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM3->CCR1 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM3CH1toGPIO();
#endif

#if defined(TIM3CH2toGPIO)
	//configure CCP2
	TIM3->CCMR1 = 	(TIM3->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM3->CCR2 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM3CH2toGPIO();
#endif

#if defined(TIM3CH3toGPIO)
	//configure CCP3
	TIM3->CCMR2 = 	(TIM3->CCMR2 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 8)) |
					(0<<11) |			//0->normal polarity for CC3N, 1->inverse polarity
					(0<<10) |			//0->disable CC3N, 1->enable CC3N
					(0<< 9) |			//0->normal polarity for CC3, 1->inverse polarity
					(1<< 8) |			//1->enable CC3, 0->disable CC3
					0x00;
	TIM3->CCR3 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM3CH3toGPIO();
#endif

#if defined(TIM3CH4toGPIO)
	//configure CCP4
	TIM3->CCMR2 = 	(TIM3->CCMR2 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 12)) |
					(0<<15) |			//0->normal polarity for CC4N, 1->inverse polarity
					(0<<14) |			//0->disable CC4N, 1->enable CC4N
					(0<<13) |			//0->normal polarity for CC4, 1->inverse polarity
					(1<<12) |			//1->enable CC4, 0->disable CC4
					0x00;
	TIM3->CCR4 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM3CH4toGPIO();
#endif

	TIM3->EGR = 0xff;					//force an update
	TIM3->BDTR|= TIM_BDTR_MOE;				//enable the main output
	//enable the timer.
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer

}


//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm14Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;

	//source from internal clock -> disable slave mode
	//TIM14->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIM14->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIM14->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIM14->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIM14->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIM14->CR1 = 0;						//much easier
	TIM14->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIM14->CR2 = 0;						//default value
	TIM14->SMCR= 0;						//default value - use internal clock

	//set the prescaler
	TIM14->PSC = TxCCP_PS - 1;			//set the prescaler
	TIM14->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIM14->ARR = PWM_PR;				//auto reload register / period = 0; - need to change for downcounters
	TIM14->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIM14->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIM14->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//configure CCP1..4
#if defined(TIM14CH1toGPIO)
	//configure CCP1
	TIM14->CCMR1 = 	(TIM14->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM14->CCER = 	(TIM14->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM14->CCR1 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM14CH1toGPIO();
#endif

	TIM14->EGR = 0xff;					//force an update
	TIM14->BDTR|= TIM_BDTR_MOE;			//enable the main output
	//enable the timer.
	TIM14->CR1 |= TIM_CR1_CEN;			//enable the timer

}


//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm15Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;

	//source from internal clock -> disable slave mode
	//TIM15->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIM15->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIM15->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIM15->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIM15->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIM15->CR1 = 0;						//much easier
	TIM15->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIM15->CR2 = 0;						//default value
	TIM15->SMCR= 0;						//default value - use internal clock

	//set the prescaler
	TIM15->PSC = TxCCP_PS - 1;					//set the prescaler
	TIM15->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIM15->ARR = PWM_PR;						//auto reload register / period = 0; - need to change for downcounters
	TIM15->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIM15->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIM15->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//configure CCP1..4
#if defined(TIM15CH1toGPIO)
	//configure CCP1
	TIM15->CCMR1 = 	(TIM15->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM15->CCER = 	(TIM15->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM15->CCR1 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM15CH1toGPIO();
#endif

#if defined(TIM15CH2toGPIO)
	//configure CCP2
	TIM15->CCMR1 = 	(TIM15->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM15->CCER = 	(TIM15->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM15->CCR2 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM15CH2toGPIO();
#endif

	TIM15->EGR = 0xff;					//force an update
	TIM15->BDTR|= TIM_BDTR_MOE;				//enable the main output
	//enable the timer.
	TIM15->CR1 |= TIM_CR1_CEN;			//enable the timer

}

/*
MAPR2 Bit 1 TIM16_REMAP: TIM16 remapping
This bit is set and cleared by software. It controls the mapping of the alternate functions of TIM16 channel 1 onto the GPIO ports.
0: No remap (CH1/PB8)
1: Remap (CH1/PA6)
*/
//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm16Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM16EN;

	//source from internal clock -> disable slave mode
	//TIM16->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIM16->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIM16->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIM16->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIM16->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIM16->CR1 = 0;						//much easier
	TIM16->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIM16->CR2 = 0;						//default value
	TIM16->SMCR= 0;						//default value - use internal clock

	//set the prescaler
	TIM16->PSC = TxCCP_PS - 1;					//set the prescaler
	TIM16->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIM16->ARR = PWM_PR;						//auto reload register / period = 0; - need to change for downcounters
	TIM16->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIM16->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIM16->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//configure CCP1..4
#if defined(TIM16CH1toGPIO)
	//configure CCP1
	TIM16->CCMR1 = 	(TIM16->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM16->CCER = 	(TIM16->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM16->CCR1 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM16CH1toGPIO();
#endif

	TIM16->EGR = 0xff;					//force an update
	TIM16->BDTR|= TIM_BDTR_MOE;				//enable the main output
	//enable the timer.
	TIM16->CR1 |= TIM_CR1_CEN;			//enable the timer

}

/*
MAPR2 Bit 2 TIM17_REMAP: TIM17 remapping
This bit is set and cleared by software. It controls the mapping of the alternate functions of TIM17 channel 1 onto the GPIO ports.
0: No remap (CH1/PB9)
1: Remap (CH1/PA7)
*/
//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm17Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM17EN;

	//source from internal clock -> disable slave mode
	//TIM17->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIM17->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIM17->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIM17->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIM17->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIM17->CR1 = 0;						//much easier
	TIM17->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIM17->CR2 = 0;						//default value
	TIM17->SMCR= 0;						//default value - use internal clock

	//set the prescaler
	TIM17->PSC = TxCCP_PS - 1;					//set the prescaler
	TIM17->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIM17->ARR = PWM_PR;						//auto reload register / period = 0; - need to change for downcounters
	TIM17->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIM17->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIM17->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//configure CCP1..4
#if defined(TIM17CH1toGPIO)
	//configure CCP1
	TIM17->CCMR1 = 	(TIM17->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM17->CCER = 	(TIM17->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM17->CCR1 = 0;						//0% duty cycle

	//configure the gpio for PWM output
	TIM17CH1toGPIO();
#endif
	TIM17->EGR = 0xff;					//force an update
	TIM17->BDTR|= TIM_BDTR_MOE;				//enable the main output
	//enable the timer.
	TIM17->CR1 |= TIM_CR1_CEN;			//enable the timer

}


//adc module
//global variables
static uint32_t _adc_calfactor;				//adc calibration factor
//initialize adc
void adc1Init(void) {
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;		//enable clock to ADC1

	//configure adc
	ADC1->CFGR1 = 	(0x00<<26) |			//0->awd on channel 0
					(0<<23) |				//0->AWD disabled
					(0<<22) |				//0->AWD on all channels (but disabled by bit 22
					(1<<16) |				//1->enable discontinuous conversion
					(0<<15) |				//0->auto off disabled
					(0<<14) |				//0->wait conversion disabled
					(0<<13) |				//0->single conversion mode, 1->continuous mode
					(0<<12) |				//0->adc data register preserved in overrun
					(0x00<<10) |			//00->hardware external trigger disabled
					(0x00<<6) |				//0000->external on TRG0 - but disabled
					(0<<5) |				//0->right aligned, 1->left aligned
					(0x00<<3) |				//00->data resolution = 12bit, 01->10bit, 10->8bit, 11->6bit
					(0<<2) |				//0->upward scan
					(0<<1) |				//0->DMA one shot mode selected
					(0<<0) |				//0->DMA disabled
					0x00;
	ADC1->CFGR2 = 	(0x02 << 30);			//00->adc clock, 01->PCLK/2, 10->PCLK/4 -> no jitter
	//set adc sample time
	//0b111->239.5 cycles for all channels
	ADC1->SMPR = 	(ADC_SMPR1_SMPR << (3 * 0)) |
					0x00;
	//set adc channel sequence
	//ADC1->SQR3 = ADC1->SQR2 = ADC1->SQR1 = 0;							//0->1 conversion

	//start self-calibration
	ADC1->CR =	0;							//reset CR
	ADC1->CR = (1<<15);						//start the calibration
	while (ADC1->CR & (1<<15)) continue;	//wait for ADC calibration to finish
	_adc_calfactor = ADC1->DR;				//save adc calibration factor

	//optional: enable temperature sensors
	ADC->CCR |= 	(1ul<<23) |				//1->enable temperature sensor
					(1ul<<22) |				//1->enable Vrefint. 1.20v nominal
					0x00;

	ADC1->CR = 	(1<<0);						//enable aden
	while ((ADC1->ISR & (1<<0)) == 0) continue;	//wait for the adc to be ready
}

//analog to digital converter on ADC1
//ain/analog input channel: ain valid values: 0..15, 16=temperature sensor, 17=Vrefint
//***user needs to be configured as floating input***
uint16_t adc1Read(uint32_t ain) {
	//ADC1->ISR &= ~(1<<2);					//clear the eoc flag
	//ADC1->CR1 = (ADC1->CR1 &~0x1f) | (ain & 0x1f);	//pick the adc channel
	//ADC1->CR2|= (1<<0);					//start the conversion
	ADC1->CHSELR = ain & 0x03fffful;		//define the first (and only) adc ch
	ADC1->CR |= (1<<2);						//start conversion
	while ((ADC1->ISR & (1<<2)) == 0) continue;	//wait for conversion to end (EOC set at end of conversion)
	return ADC1->DR;						//return adc result and clears the EOC bit
}


//end ADC

#if 0
//input capture
static void (*_ic1_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC1DAT=0;						//buffer 

//input capture ISR
void _ISR_PSV _IC1Interrupt(void) {				//for PIC32
	//clear the flag
	IC1DAT = IC1BUF;							//read the captured value
	IFS0bits.IC1IF = 0;							//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic1_isrptr();								//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic1Init(void) {
	_ic1_isrptr = empty_handler;				//reset user handler

	IC12RP();									//assign pin to IC
	PMD2bits.IC1MD = 0;							//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
	IC1CON1 = 0;						//reset to default value
	IC1CON2 = 0;						//reset to default value
	IC1CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC1BUF;								//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC1CON1bits.ON = 1;					//1->enable the module, 0->disable the module
#else
	//for ga002 devices
	IC1CON = 0;						//reset to default value
	//IC1CON2 = 0;						//reset to default value
	IC1CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC1BUF;								//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC1CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
	//input capture running now
}

//activate user ptr
void ic1AttachISR(void (*isrptr)(void)) {
	_ic1_isrptr = isrptr;				//install user ptr
	IC1BUF;								//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic1Get(void) {
	return IC1DAT;
}
	
static void (*_ic2_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC2DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC2Interrupt(void) {		//for PIC32
	//clear the flag
	IC2DAT = IC2BUF;					//read the captured value
	IFS0bits.IC2IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic2_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic2Init(void) {
	_ic2_isrptr = empty_handler;		//reset user handler

	IC22RP();							//assign pin to IC
	PMD2bits.IC2MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
	IC2CON1 = 0;						//reset to default value
	IC2CON2 = 0;						//reset to default value
	IC2CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC2BUF;								//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC2CON1bits.ON = 1;				//1->enable the module, 0->disable the module
#else
	//for ga002 devices
	IC2CON = 0;							//reset to default value
	//IC2CON2 = 0;						//reset to default value
	IC2CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC2BUF;								//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC2CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic2AttachISR(void (*isrptr)(void)) {
	_ic2_isrptr = isrptr;				//install user ptr
	IC2BUF;								//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic2Get(void) {
	return IC2DAT;
}
	
static void (*_ic3_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC3DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC3Interrupt(void) {		//for PIC32
	//clear the flag
	IC3DAT = IC3BUF;					//read the captured value
	IFS2bits.IC3IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic3_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic3Init(void) {
	_ic3_isrptr = empty_handler;		//reset user handler

	IC32RP();							//assign pin to IC
	PMD2bits.IC3MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
	IC3CON1 = 0;						//reset to default value
	IC3CON2 = 0;						//reset to default value
	IC3CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC3BUF;								//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC3CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC3CON = 0;							//reset to default value
	//IC3CON2 = 0;						//reset to default value
	IC3CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC3BUF;								//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC3CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic3AttachISR(void (*isrptr)(void)) {
	_ic3_isrptr = isrptr;				//install user ptr
	IC3BUF;								//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic3Get(void) {
	return IC3DAT;
}
	
static void (*_ic4_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC4DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC4Interrupt(void) {		//for PIC32
	//clear the flag
	IC4DAT = IC4BUF;					//read the captured value
	IFS2bits.IC4IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic4_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic4Init(void) {
	_ic4_isrptr = empty_handler;		//reset user handler

	IC42RP();							//assign pin to IC
	PMD2bits.IC4MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
	IC4CON1 = 0;						//reset to default value
	IC4CON2 = 0;						//reset to default value
	IC4CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC4BUF;								//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC4CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC4CON = 0;						//reset to default value
	//IC4CON2 = 0;						//reset to default value
	IC4CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC4BUF;								//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC4CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic4AttachISR(void (*isrptr)(void)) {
	_ic4_isrptr = isrptr;				//install user ptr
	IC4BUF;								//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic4Get(void) {
	return IC4DAT;
}
	
static void (*_ic5_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC5DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC5Interrupt(void) {		//for PIC32
	//clear the flag
	IC5DAT = IC5BUF;					//read the captured value
	IFS2bits.IC5IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic5_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic5Init(void) {
	_ic5_isrptr = empty_handler;		//reset user handler

	IC52RP();							//assign pin to IC
	PMD2bits.IC5MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
	IC5CON1 = 0;						//reset to default value
	IC5CON2 = 0;						//reset to default value
	IC5CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC5BUF;								//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC5CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC5CON = 0;							//reset to default value
	//IC5CON2 = 0;						//reset to default value
	IC5CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
                (0<<13) |				//0->operates in idle, 1->don't operate in idle
                (1<<9) |				//1-.capture rising edge first (only used for ICM110)
                (0<<8) |				//1->32-bit mode, 0->16-bit mode
                (1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
                (0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
                (0<<4) |				//0->ICx no overflow, 1->ICx overflow
                (0<<3) |				//0->buffer is empty, 1->buffer is not empty
                (3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
                0x00;

	IC5BUF;								//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC5CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic5AttachISR(void (*isrptr)(void)) {
	_ic5_isrptr = isrptr;				//install user ptr
	IC5BUF;								//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic5Get(void) {
	return IC5DAT;
}
//end input capture


//spi
//rest spi1
void spi1Init(uint16_t br) {
	PMD1bits.SPI1MD = 0;				//0->enable the module
	
	//map the pins
	
	//initialize the spi module
	//master mode, PBCLK as clock, 8-bit data, enhanced buffer mode
	SPI1CON1 = SPI1CON2 = 0; 			//reset the spi module
	SPI1CON1bits.MSTEN = 1;				//1->master mode, 0->slave mode
	//SPI1CON1bits.ENHBUF= 1;			//1->enable enhanced buffer mode, 0->disable enhanced buffer mode
	SPI1CON1bits.PPRE = br;				//set the baudrate generator
	//need to deal with secondary as well
	SPI1BUF;							//read the buffer to reset the flag
	IFS0bits.SPI1IF = 0;				//0->reset the flag
	IEC0bits.SPI1IE = 0;				//0->disable the interrupt, 1->enable the interrupt
	//SPI1CONbits.ON = 1;				//1->enable the module, 0->disable the module
}

//send data via spi
void spi1Write(uint8_t dat) {
	while (spi1Busy()) continue;		//tx buffer is full
	SPI1BUF = dat;						//load the data
}

//rest spi2
void spi2Init(uint16_t br) {
	PMD1bits.SPI2MD = 0;				//0->enable the module
	
	//map the pins
	
	//initialize the spi module
	//master mode, PBCLK as clock, 8-bit data, enhanced buffer mode
	SPI2CON1 = SPI2CON2 = 0; 			//reset the spi module
	SPI2CON1bits.MSTEN = 1;				//1->master mode, 0->slave mode
	//SPI2CON1bits.ENHBUF= 1;			//1->enable enhanced buffer mode, 0->disable enhanced buffer mode
	SPI2CON1bits.PPRE = br;				//set the baudrate generator
	//need to deal with 2nd ary as well
	SPI2BUF;							//read the buffer to reset the flag
	IFS2bits.SPI2IF = 0;				//0->reset the flag
	IEC2bits.SPI2IE = 0;				//0->disable the interrupt, 1->enable the interrupt
	//SPI2CONbits.ON = 1;				//1->enable the module, 0->disable the module
}

//send data via spi
void spi2Write(uint8_t dat) {
	while (spi2Busy()) continue;		//tx buffer is full
	SPI2BUF = dat;						//load the data
}
//end spi

//i2c

//end i2c

//rtcc
//end rtcc
#endif	//xxxxx

//cnint
//global variables
static void (* _exti0_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti1_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti2_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti3_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti4_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti5_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti6_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti7_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti8_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti9_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti10_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti11_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti12_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti13_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti14_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti15_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default

//EXTI0-1 ISR
void EXTI0_1_IRQHandler(void) {
	//clear the flag and execute user isr
	switch (EXTI->PR) {
		case (1<<0): EXTI->PR |= (1<<0); _exti0_isrptr(); break;
		case (1<<1): EXTI->PR |= (1<<1); _exti1_isrptr(); break;
	}
}

//EXTI2-3 ISR
void EXTI2_3_IRQHandler(void) {
	//clear the flag and execute user isr
	switch (EXTI->PR) {
		case (1<<2): EXTI->PR |= (1<<2); _exti2_isrptr(); break;
		case (1<<3): EXTI->PR |= (1<<3); _exti3_isrptr(); break;
	}
}

//EXTI15-10 ISR
void EXTI4_15_IRQHandler(void) {
	//clear the flag and execute user isr
	switch (EXTI->PR) {
		case (1<< 4): EXTI->PR |= (1<< 4); _exti4_isrptr(); break;
		case (1<< 5): EXTI->PR |= (1<< 5); _exti5_isrptr(); break;
		case (1<< 6): EXTI->PR |= (1<< 6); _exti6_isrptr(); break;
		case (1<< 7): EXTI->PR |= (1<< 7); _exti7_isrptr(); break;
		case (1<< 8): EXTI->PR |= (1<< 8); _exti8_isrptr(); break;
		case (1<< 9): EXTI->PR |= (1<< 9); _exti9_isrptr(); break;
		case (1<<10): EXTI->PR |= (1<<10); _exti10_isrptr(); break;
		case (1<<11): EXTI->PR |= (1<<11); _exti11_isrptr(); break;
		case (1<<12): EXTI->PR |= (1<<12); _exti12_isrptr(); break;
		case (1<<13): EXTI->PR |= (1<<13); _exti13_isrptr(); break;
		case (1<<14): EXTI->PR |= (1<<14); _exti14_isrptr(); break;
		case (1<<15): EXTI->PR |= (1<<15); _exti15_isrptr(); break;
	}
}

//global defines
#define EXTI_FALLING	FALLING				//trigger on falling edge
#define EXTI_RISING		RISING				//trigger on rising edge
#define EXTI_BOTH		CHANGE				//trigger on falling and rising edges

//global variables
//initialize the exti
//pin: one pin only
//gpio: GPIOA..GPIOG
void extiInit(GPIO_TypeDef * gpio, uint16_t pin, uint8_t edge) {
	uint16_t tmp;
	//enable afio
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	//enable the clock
	switch ((uint32_t) gpio) {
#if defined(RCC_AHBENR_GPIOAEN)
		case (uint32_t) GPIOA: RCC->AHBENR |= RCC_AHBENR_GPIOAEN; tmp = 0x00; break;
#endif
#if defined(RCC_AHBENR_GPIOBEN)
		case (uint32_t) GPIOB: RCC->AHBENR |= RCC_AHBENR_GPIOBEN; tmp = 0x01; break;
#endif
#if defined(RCC_AHBENR_GPIOCEN)
		case (uint32_t) GPIOC: RCC->AHBENR |= RCC_AHBENR_GPIOCEN; tmp = 0x02; break;
#endif
#if defined(RCC_AHBENR_GPIODEN)
		case (uint32_t) GPIOD: RCC->AHBENR |= RCC_AHBENR_GPIODEN; tmp = 0x03; break;
#endif
#if defined(RCC_AHBENR_GPIOEEN)
		case (uint32_t) GPIOE: RCC->AHBENR |= RCC_AHBENR_GPIOEEN; tmp = 0x04; break;
#endif
#if defined(RCC_AHBENR_GPIOFEN)
		case (uint32_t) GPIOF: RCC->AHBENR |= RCC_AHBENR_GPIOFEN; tmp = 0x05; break;
#endif
#if defined(RCC_AHBENR_GPIOGEN)
		case (uint32_t) GPIOG: RCC->AHBENR |= RCC_AHBENR_GPIOGEN; tmp = 0x06; break;
#endif
	}
	//configure exti edges
	//1->falling/rising edge enabled, 0->falling/rising edge disabled
	switch (edge) {
		case EXTI_FALLING: 	EXTI->FTSR |= pin; EXTI->RTSR &=~pin; break;
		case EXTI_RISING: 	EXTI->FTSR &=~pin; EXTI->RTSR |= pin; break;
		case EXTI_BOTH: 	EXTI->FTSR |= pin; EXTI->RTSR |= pin; break;
	}
	//configure the port
	switch (pin) {
		case (1<< 0): SYSCFG->EXTICR[0] = (SYSCFG->EXTICR[0] &~0x000f) | ((tmp) <<  0); break;
		case (1<< 1): SYSCFG->EXTICR[0] = (SYSCFG->EXTICR[0] &~0x00f0) | ((tmp) <<  4); break;
		case (1<< 2): SYSCFG->EXTICR[0] = (SYSCFG->EXTICR[0] &~0x0f00) | ((tmp) <<  8); break;
		case (1<< 3): SYSCFG->EXTICR[0] = (SYSCFG->EXTICR[0] &~0xf000) | ((tmp) << 12); break;
		case (1<< 4): SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] &~0x000f) | ((tmp) <<  0); break;
		case (1<< 5): SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] &~0x00f0) | ((tmp) <<  4); break;
		case (1<< 6): SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] &~0x0f00) | ((tmp) <<  8); break;
		case (1<< 7): SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] &~0xf000) | ((tmp) << 12); break;
		case (1<< 8): SYSCFG->EXTICR[2] = (SYSCFG->EXTICR[2] &~0x000f) | ((tmp) <<  0); break;
		case (1<< 9): SYSCFG->EXTICR[2] = (SYSCFG->EXTICR[2] &~0x00f0) | ((tmp) <<  4); break;
		case (1<<10): SYSCFG->EXTICR[2] = (SYSCFG->EXTICR[2] &~0x0f00) | ((tmp) <<  8); break;
		case (1<<11): SYSCFG->EXTICR[2] = (SYSCFG->EXTICR[2] &~0xf000) | ((tmp) << 12); break;
		case (1<<12): SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] &~0x000f) | ((tmp) <<  0); break;
		case (1<<13): SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] &~0x00f0) | ((tmp) <<  4); break;
		case (1<<14): SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] &~0x0f00) | ((tmp) <<  8); break;
		case (1<<15): SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] &~0xf000) | ((tmp) << 12); break;
	};
}

//install user handler
void extiAttachISR(uint16_t pin, void (*isr_ptr)(void)) {
	//clear the flag
	EXTI->PR |= pin;						//1->clear the flag
	//enable the interrupt
	EXTI->IMR |= pin;							//1->enable the interrupt, 0->disable the interrupt
	EXTI->EMR |= pin;							//1->enable the event trigger, 0->disable the event trigger

	//enable nvic
	switch (pin) {
		case (1<< 0): NVIC_EnableIRQ(EXTI0_1_IRQn); _exti0_isrptr = isr_ptr; break;
		case (1<< 1): NVIC_EnableIRQ(EXTI0_1_IRQn); _exti1_isrptr = isr_ptr; break;
		case (1<< 2): NVIC_EnableIRQ(EXTI2_3_IRQn); _exti2_isrptr = isr_ptr; break;
		case (1<< 3): NVIC_EnableIRQ(EXTI2_3_IRQn); _exti3_isrptr = isr_ptr; break;
		case (1<< 4): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti4_isrptr = isr_ptr; break;
		case (1<< 5): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti5_isrptr = isr_ptr; break;
		case (1<< 6): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti6_isrptr = isr_ptr; break;
		case (1<< 7): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti7_isrptr = isr_ptr; break;
		case (1<< 8): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti8_isrptr = isr_ptr; break;
		case (1<< 9): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti9_isrptr = isr_ptr; break;
		case (1<<10): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti10_isrptr = isr_ptr; break;
		case (1<<11): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti11_isrptr = isr_ptr; break;
		case (1<<12): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti12_isrptr = isr_ptr; break;
		case (1<<13): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti13_isrptr = isr_ptr; break;
		case (1<<14): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti14_isrptr = isr_ptr; break;
		case (1<<15): NVIC_EnableIRQ(EXTI4_15_IRQn); _exti15_isrptr = isr_ptr; break;
	}
}

//end cnint
#endif //0
