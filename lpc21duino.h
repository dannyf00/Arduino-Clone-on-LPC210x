#ifndef _LPC17DUINO_H
#define _LPC17DUINO_H

//LPC21duino code
// - using LPC210x: LPC2101/2/3
// - features implemented so far: 
//	- Systick generation via Timer0 overflow
//	- low-power clock gating: peripheral clock disabled on reboot
//	- SystemCoreClock: automatically update SystemCoreClock (=CCLK/F_CPU), and peripheral clock (=PCLK/F_PHB)
//	- GPIO0..5: if available
//	- UART0/1, Timer0..3, External Interrupts0..2
//	- PWM generation on TIMER0..3, Match channel 0..3 - CH3s set periods
//	- ADC and SPI0/SPI1 (SSP) supported
//
// - features to be implemented: I2C
// - 
// - version history
// - v0.1, 8/28/2022: initial implementation, including systick, gpio, uart, and output compare
// - v0.2, 8/29/2022: implemented SystemCoreClockUpdate()
// - v0.3, 9/02/2022: RTC, PWM, ADC and SPI implemented
//
//
//               LPC210x
//              |=====================|
//        Xtal->| 14.7456Mhz      P07 |>---------> LED2
//              |                     |
//              |                 P00 |>---------> U0TX
//              |                 P01 |<---------< U0RX
//              |                     |
//              |                 P08 |>---------> U1TX
//              |                 P09 |<---------< U1RX
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |=====================|
//
//
//	please don't assign other ISRs to those channels (VICIntAddrn)
//	ISR usage: 
//	FIQ: not used
//	Vectored Interrupt:
//	0: unused - WDT
//	1: unused
//	2: unused - ARM Core1
//	3: unused - ARM Core2
//	4: TIMER0
//	5: TIMER1	
//	6: UART0 - reserved	
//	7: UART1 - reserved
//	8: unused
//	9: unused
//	10:unused
//	11:INT0
//	12:INT1
//	13:INT2
//	14:TIMER2
//	15:TIMER3
//
//	Non-vectored interrupt
//	UART0 and UART1
//
// unmapped: I2C0/1, ADC, SPI, IC
//
//

#include <lpc2103.h>						//we use LPC2103.h for LPC2101/2/3
//#include <lpc210x.h>						//we use LPC210x.h for LPC2104/5/6
#include <stdint.h>							//we use uint types
#include <string.h>							//we use strcpy

//hardware configuration
//oscillator configuration
#define F_XTAL				14745600ul		//crystal frequency, user-defined
#define uRAM_SIZE			40				//size of the uram
#define F_SPI0				100000ul		//SPI0 frequency, in Hz
#define F_SPI1				100000ul		//spi1/ssp frequency
#define F_RTC				32768			//rtc crystal
#define F_I2C0				100000ul		//i2c0 clock speed
#define F_I2C1				100000ul		//i2c1 clock speed
//#define USE_FGPIO							//use fast IO. comment out if legacy/"slow" gpio is used
#define USE_U0TXISR							//define to enable uart0 transmission via interrupt
#define USE_U1TXISR							//define to enable uart1 transmission via interrupt

//uart0 pins
#define U0TX_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 0)) | (0x01ul << 0);} while (0)	//U0TX to P0.0
//#define U0RX_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 2)) | (0x01ul << 2);} while (0)	//U0RX to P0.1
#define U1TX_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<16)) | (0x01ul <<16);} while (0)	//U1TX to P0.8
#define U1RX_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<18)) | (0x01ul <<18);} while (0)	//U1RX to P0.9

#define INT0_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 0)) | (0x01ul << 0);} while (0)	//INT0 to P0.16
#define INT1_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<28)) | (0x01ul <<28);} while (0)	//INT1 to P0.14. 1 for LPC2101/2/3, 2 for LPC2104/5/6: why NXP?! 
#define INT2_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<30)) | (0x01ul <<30);} while (0)	//INT2 to P0.15. 1 for LPC2101/2/3, 2 for LPC2104/5/6. why NXP?! 
//#define INT3_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03 << 2)) | (0x01 << 2);} while (0)	//INT3 to P0.1

#define IC00_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 4)) | (0x02ul << 4);} while (0)	//CAP0.0 on P0.2
#define IC01_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 8)) | (0x02ul << 8);} while (0)	//CAP0.1 on P0.4
#define IC02_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<12)) | (0x02ul <<12);} while (0)	//CAP0.2 on P0.6
//#define IC03_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 8)) | (0x02ul << 8);} while (0)	//CAP0.1 on P0.4
#define IC10_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<20)) | (0x02ul <<20);} while (0)	//CAP1.0 on P0.10
#define IC11_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<22)) | (0x02ul <<22);} while (0)	//CAP1.1 on P0.11
#define IC12_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 2)) | (0x02ul << 2);} while (0)	//CAP1.2 on P0.17
#define IC13_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 4)) | (0x02ul << 4);} while (0)	//CAP1.3 on P0.18
#define IC20_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul <<22)) | (0x02ul <<22);} while (0)	//CAP2.0 on P0.27
#define IC21_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul <<24)) | (0x02ul <<24);} while (0)	//CAP2.1 on P0.28
#define IC22_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul <<26)) | (0x02ul <<26);} while (0)	//CAP2.2 on P0.29
//#define IC23_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 4)) | (0x02ul << 4);} while (0)	//CAP1.3 on P0.18
//datasheet notes that CAP3.0..2 not usable on Timer3
//#define IC30_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<20)) | (0x02ul <<20);} while (0)	//CAP1.0 on P0.10
//#define IC31_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<22)) | (0x02ul <<22);} while (0)	//CAP1.1 on P0.11
//#define IC32_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 2)) | (0x02ul << 2);} while (0)	//CAP1.2 on P0.17
//#define IC33_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 4)) | (0x02ul << 4);} while (0)	//CAP1.3 on P0.18

#define PWM00_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 6)) | (0x02ul << 6);} while (0)	//MAT0.0 on P0.3
#define PWM01_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<10)) | (0x02ul <<10);} while (0)	//MAT0.1 on P0.5
#define PWM02_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 0)) | (0x02ul << 0);} while (0)	//MAT0.2 on P0.16
//#define PWM03_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 6)) | (0x02ul << 6);} while (0)	//MAT0.0 on P0.3

#define PWM10_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<24)) | (0x02ul <<24);} while (0)	//MAT1.0 on P0.12
#define PWM11_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<26)) | (0x02ul <<26);} while (0)	//MAT1.1 on P0.13
#define PWM12_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 6)) | (0x02ul << 6);} while (0)	//MAT1.2 on P0.19
#define PWM13_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul << 8)) | (0x02ul << 8);} while (0)	//MAT1.3 on P0.20

#define PWM20_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<14)) | (0x02ul <<14);} while (0)	//MAT2.0 on P0.7
#define PWM21_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<16)) | (0x02ul <<16);} while (0)	//MAT2.1 on P0.8
#define PWM22_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul <<18)) | (0x02ul <<18);} while (0)	//MAT2.2 on P0.9
//#define PWM23_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 6)) | (0x02ul << 6);} while (0)	//MAT0.0 on P0.3

#define PWM30_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul <<10)) | (0x02ul <<10);} while (0)	//MAT3.0 on P0.21
#define PWM31_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 0)) | (0x02ul << 0);} while (0)	//MAT3.1 on P0.0
#define PWM32_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 2)) | (0x02ul << 2);} while (0)	//MAT3.2 on P0.1
#define PWM33_PIN()			do {PINSEL1 = (PINSEL1 &~(0x03ul <<28)) | (0x02ul <<28);} while (0)	//MAT3.3 on P0.30 - as the reset channel


//spi0 pins
#define SCLK0_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul << 8)) | (0x01ul << 8);} while (0)	//sclk0 on P0.4
#define SSEL0_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<14)) | (0x01ul <<14);} while (0)	//ssel0 on P0.7
#define MOSI0_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<12)) | (0x01ul <<12);} while (0)	//mosi0 on P0.6
#define MISO0_PIN()			do {PINSEL0 = (PINSEL0 &~(0x03ul <<10)) | (0x01ul <<10);} while (0)	//miso0 on P0.5
//end user specification

//end pin configuration
extern volatile uint32_t SystemCoreClock;				//system coreclock (=CCLK)
extern volatile uint32_t AHBClock;						//system coreclock (=CCLK)
extern volatile uint32_t APBClock;						//system coreclock (=CCLK)
#define F_PHB				(F_APB)						//((APBDIV & 0x03) == 0)?(F_CPU/4):(((APBDIV & 0x03)== 2)?(F_CPU/2):F_CPU))						//=PCLK. 1/4 CCLK (default).
#define F_CPU				(SystemCoreClock)			//=CCLK
#define F_AHB				(AHBClock)
#define F_APB				(APBClock)

#define PWM_PR				0xffff						//pwm period - don't change

//port manipulation macros for PIC.
//MODE:
//Output modes: GPIOMODE_OUTPP, GPIOMODE_OUTOD
//Input mode: GPIOMODE_INPUT, GPIOMODE_INPUTP3, GPIOMODE_INPUTPU
//Alternate function: GPIOMODE_AFPP, GPIOMODE_AFOD
//for moder
#define GPIOMODE_INPUT		(0<<0)		//(0<<0)
#define GPIOMODE_OUTPUT		(1<<0)		//(1<<0)
#define GPIOMODE_AF			(2<<0)
#define GPIOMODE_AN			(3<<0)
//for otyper
#define GPIOMODE_PP			(1<<3)
#define GPIOMODE_OD			(0<<3)
//for puP3r
#define GPIOMODE_FL			(0<<4)
#define GPIOMODE_PU			(1<<4)
#define GPIOMODE_P3			(2<<4)

//AF defs
#define GPIOMODE_AF0		0
#define GPIOMODE_AF1		1
#define GPIOMODE_AF2		2
#define GPIOMODE_AF3		3
#define GPIOMODE_AF4		4
#define GPIOMODE_AF5		5
#define GPIOMODE_AF6		6
#define GPIOMODE_AF7		7

#define GPIOMODE_OUTPP		(GPIOMODE_OUTPUT | GPIOMODE_PP)		//gpio, output, push-pull
#define GPIOMODE_OUTOD		(GPIOMODE_OUTPUT | GPIOMODE_OD)		//gpio, output, od
#define GPIOMODE_INFL		(GPIOMODE_INPUT)
#define GPIOMODE_INPU		(GPIOMODE_INPUT | GPIOMODE_PU)
#define GPIOMODE_INP3		(GPIOMODE_INPUT | GPIOMODE_P3)
#define GPIOMODE_AFPP		(GPIOMODE_AF | GPIOMODE_PP)
#define GPIOMODE_AFOD		(GPIOMODE_AF | GPIOMODE_OD)
#define GPIOMODE_INAN		(GPIOMODE_AN)

//global variables

//port macros
#define IO_SET(port, pins)	port->SET = (pins)	//port->PIN |= (pins)	//port->ODR |= (pins)		//port->BSRR = (pins)
#define IO_CLR(port, pins)	port->CLR = (pins)	//port->PIN &=~(pins)	//port->BRR = (pins)
#define IO_FLP(port, pins)	port->PIN^= (pins)	//flip an output pin
#define IO_GET(port, pins)	((port->PIN) & (pins))	//return gpio pins

//fast gpio routines
//#define FIO_SET(port, pins)	port->MASKED_ACCESS[pins] = (pins)	//IO_SET(port, pins)		//port->BSRR = (pins)
//#define FIO_CLR(port, pins)	port->MASKED_ACCESS[pins] = 0		//IO_CLR(port, pins)		//port->BRR = (pins)
//#define FIO_FLP(port, pins)	IO_FLP(port, pins)		//no fast io routine for pin flipping
//#define FIO_GET(port, pins) (port->MASKED_ACCESS[pins] & (pins))	//IO_GET(port, pins)		// no fast io routines

//set pins to output
//void IO_OUT(GPIO_TypeDef* port, uint16_t pins);
#define IO_OUT(port, pins)	port->DIR |= (pins)		//GPIO_SetDir(port, pins, 1)

//set pins as floating input
//void IO_IN(GPIO_TypeDef* port, uint16_t pins);
#define IO_IN(port, pins)	port->DIR &=~(pins)		//GPIO_SetDir(port, pins, 0)

#define NOP()				Nop()                           //asm("nop")					//nop()
#define NOP2()				{NOP(); NOP();}
#define NOP4()				{NOP2(); NOP2();}
#define NOP8()				{NOP4(); NOP4();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP24()				{NOP16(); NOP8();}
#define NOP32()				{NOP16(); NOP16();}
#define NOP40()				{NOP32(); NOP8();}
#define NOP64()				{NOP32(); NOP32();}

#define sleep()				asm("sleep")					//put the mcu into sleep

#ifndef ei
#define ei()				//asm volatile ("ei")				//__builtin_enable_interrupts()	//do {INTEnableInterrupts();	INTEnableSystemMultiVectoredInt();} while (0)	//__builtin_enable_interrupts()
#endif

#ifndef di
#define di()				//asm volatile ("di")				//__builtin_enable_interrupts()	//INTDisableInterrupts()			//__builtin_disable_interrupts()	//
#endif


//simple multiples
#define x1(val)				(val)								//multiply val by 1
#define x2(val)				(((val) << 1))						//multiply val by 2
#define x3(val)				(x2(val) + (val))					//multiply val by 3
#define x4(val)				(((val) << 2))						//multiply val by 4
#define x5(val)				(x4(val) + (val))					//multiply val by 5
#define x6(val)				(x4(val) + x2(val))					//multiply val by 6
#define x7(val)				(x6(val) + (val))					//multiply val by 7
#define x8(val)				((val) << 3)						//multiply val by 8
#define x9(val)				(x8(val) + (val))					//multiply val by 9

//multiples of 10s
#define x10(val)			(x8(val) + x2(val))					//multiply val by 10
#define x100(val)			(x10(x10(val)))						//multiply val by 100
#define x1000(val)			(x100(x10(val)))					//multiply val by 1000
#define x1k(val)			x1000(val)							//multiply val by 1000
#define x10k(val)			(x100(x100(val)))					//multiply val by 10000

#define x20(val)			(x2(x10(val)))
#define x30(val)			(x3(x10(val)))
#define x40(val)			(x4(x10(val)))
#define x50(val)			(x5(x10(val)))
#define x60(val)			(x6(x10(val)))
#define x70(val)			(x7(x10(val)))
#define x80(val)			(x8(x10(val)))
#define x90(val)			(x9(x10(val)))

//multiples of 100s
#define x200(val)			(x2(x100(val)))
#define x300(val)			(x3(x100(val)))
#define x400(val)			(x4(x100(val)))
#define x500(val)			(x5(x100(val)))
#define x600(val)			(x6(x100(val)))
#define x700(val)			(x7(x100(val)))
#define x800(val)			(x8(x100(val)))
#define x900(val)			(x9(x100(val)))

//custom definitions
#define x34(val)			(x30(val) + x4(val))				//multiply val by 34
#define x97(val)			(x90(val) + x7(val))				//multiply val by 97x

//port structure

//global defines
//if user decides to use faster gpio and it exists on the chip
#if defined(USE_FGPIO) & defined(FIODIR)
//for fast gpio
typedef struct {
	uint32_t DIR;	   		//output direction register. offset:0xc000
	uint32_t reserved[3];	//stuffy
	uint32_t MASK;			//fiomask. offset: 0xc010
	uint32_t PIN;			//input data register. offset: 0xc014
	uint32_t SET;			//output set register. offset: 0xc018
	uint32_t CLR;		   	//output clear register. offset: 0xc01c
} LPC_GPIO_TypeDef;

#if defined(FIODIR) | defined(FIODIR0)
#define LPC_GPIO0			((LPC_GPIO_TypeDef *) &FIODIR)
#endif

#if defined(FIODIR1)
#define LPC_GPIO1			((LPC_GPIO_TypeDef *) &FIODIR1)
#endif

#if defined(FIODIR2)
#define LPC_GPIO2			((LPC_GPIO_TypeDef *) &FIODIR2)
#endif

#if defined(FIODIR3)
#define LPC_GPIO3			((LPC_GPIO_TypeDef *) &FIODIR3)
#endif

#if defined(FIODIR4)
#define LPC_GPIO4			((LPC_GPIO_TypeDef *) &FIODIR4)
#endif

#if defined(FIODIR5)
#define LPC_GPIO5			((LPC_GPIO_TypeDef *) &FIODIR5)
#endif

#else
//for legacy / slow gpio
typedef struct {
	uint32_t PIN;			//input data register
	uint32_t SET;			//output set register
	uint32_t DIR;	   		//output direction register
	uint32_t CLR;		   	//output clear register
} LPC_GPIO_TypeDef;

#if defined(IOPIN) | defined(IOPIN0)
#define LPC_GPIO0			((LPC_GPIO_TypeDef *) &IOPIN)
#endif

#if defined(IOPIN1)
#define LPC_GPIO1			((LPC_GPIO_TypeDef *) &IOPIN1)
#endif

#if defined(IOPIN2)
#define LPC_GPIO2			((LPC_GPIO_TypeDef *) &IOPIN2)
#endif

#if defined(IOPIN3)
#define LPC_GPIO3			((LPC_GPIO_TypeDef *) &IOPIN3)
#endif

#if defined(IOPIN4)
#define LPC_GPIO4			((LPC_GPIO_TypeDef *) &IOPIN4)
#endif

#if defined(IOPIN5)
#define LPC_GPIO5			((LPC_GPIO_TypeDef *) &IOPIN5)
#endif

#endif	//USE_FGPIO

//pin enum - matches GPIO_PinDef[]
//ports are 32 bits
typedef enum {
#if defined(LPC_GPIO0)
	P00,  P01,  P02,  P03,  P04,  P05,  P06,  P07,  P08,  P09,  P010, P011, P012, P013, P014, P015,
	P016, P017, P018, P019, P020, P021, P022, P023, P024, P025, P026, P027, P028, P029, P030, P031,
#endif
#if defined(LPC_GPIO1)
	P10,  P11,  P12,  P13,  P14,  P15,  P16,  P17,  P18,  P19,  P110, P111, P112, P113, P114, P115,
	P116, P117, P118, P119, P120, P121, P122, P123, P124, P125, P126, P127, P128, P129, P130, P131,
#endif
#if defined(LPC_GPIO2)
	P20,  P21,  P22,  P23,  P24,  P25,  P26,  P27,  P28,  P29,  P210, P211, P212, P213, P214, P215,
	P216, P217, P218, P219, P220, P221, P222, P223, P224, P225, P226, P227, P228, P229, P230, P231,
#endif		//GPIOC
#if defined(LPC_GPIO3)
	P30,  P31,  P32,  P33,  P34,  P35,  P36,  P37,  P38,  P39,  P310, P311, P312, P313, P314, P315,
	P316, P317, P318, P319, P320, P321, P322, P323, P324, P325, P326, P327, P328, P329, P330, P331,
#endif		//GPIOC
#if defined(LPC_GPIO4)
	P40,  P41,  P42,  P43,  P44,  P45,  P46,  P47,  P48,  P49,  P410, P411, P412, P413, P414, P415,
	P416, P417, P418, P419, P420, P421, P422, P423, P424, P425, P426, P427, P428, P429, P430, P431,
#endif		//GPIOC
#if defined(LPC_GPIO5)
	P50,  P51,  P52,  P53,  P54,  P55,  P56,  P57,  P58,  P59,  P510, P511, P512, P513, P514, P515,
	P516, P517, P518, P519, P520, P521, P522, P523, P524, P525, P526, P527, P528, P529, P530, P531,
#endif		//GPIOC
	PMAX
} PIN_TypeDef;

//map pin number to GPIOx
typedef struct {
	LPC_GPIO_TypeDef *gpio;				//gpio for a pin
	uint32_t mask;						//pin mask - 32-bit port
} PIN2GPIO;
	
#define INPUT				0
#define OUTPUT				1			//(!INPUT)
#define INPUT_PULLUP		2

#define LOW					0
#define HIGH				(!LOW)

#define PI 					3.1415926535897932384626433832795
#define HALF_PI 			(PI / 2)							//1.5707963267948966192313216916398
#define TWO_PI 				(PI + PI)							//6.283185307179586476925286766559
#define DEG_TO_RAD 			(TWO_PI / 360)						//0.017453292519943295769236907684886
#define RAD_TO_DEG 			(360 / TWO_PI)						//57.295779513082320876798154814105
#define EULER 				2.718281828459045235360287471352	//Euler's number

#define SERIAL  			0x0
#define DISPLAY 			0x1

#define LSBFIRST 			0
#define MSBFIRST 			1									//(!LSBFIRST)							//1

#define CHANGE 				1
#define FALLING 			2
#define RISING 				3

#ifndef min
#define min(a,b) 			((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) 			((a)>(b)?(a):(b))
#endif
#define abs(x) 				((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     		((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) 		((deg)*DEG_TO_RAD)
#define degrees(rad) 		((rad)*RAD_TO_DEG)
#define sq(x) 				((x)*(x))

#define interrupts() 		ei()
#define noInterrupts() 		di()

#define clockCyclesPerMillisecond() 	( F_CPU / 1000L )
#define clockCyclesPerMicrosecond() 	( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) 	( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) 	( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) 			((uint8_t) ((w) & 0xff))
#define highByte(w) 		((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) 	((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(n)				(1ul<<(n))

#define false				0
#define true				(!false)

//characters
#define isAlphaNumeric(c)	isalnum(c)
#define isAlpha(c)			isalpha(c)
#define isAscii(c)			isascii(c)
#define isWhitespace(c)		isblank(c)
#define isControl(c)		iscntrl(c)
#define isDigit(c)			isdigit(c)
#define isGraph(c)			isgraph(c)
#define isLowerCase(c)		islower(c)
#define isPrintable(c)		isprint(c)
#define isPunct(c)			ispunct(c)
#define isSpace(c)			isspace(c)
#define isUpperCase(c)		isupper(c)
#define isHexadecimalDigit(c)	isxdigit(c)

//external setup/loop - defined by user
extern void setup(void);
extern void loop(void);

//random number
#define randomSeed(seed)	srand(seed)
#define random(max)			random2(0, max)
#define random2(min, max)	((min) + (int32_t) ((max) - (min)) * rand() / 32768)

//GPIO
void pinMode(PIN_TypeDef pin, uint8_t mode);
void digitalWrite(PIN_TypeDef pin, uint8_t mode);
int digitalRead(PIN_TypeDef pin);

//time base
//uint32_t ticks(void);								//timer ticks from timer2
#define systicks()			(T0TC)					//T0TC as systick generator
#define coreticks()			systicks()			  	//for compatibility
#define ticks()				systicks()				//for compatibility
#define millis()			(ticks() / cyclesPerMillisecond())
#define micros()			(ticks() / cyclesPerMicrosecond())
//void delay(uint32_t ms);							//delay a given number of ms
//void delayMicroseconds(uint32_t us);				//delay a given number of us
void delayTks(uint32_t tks);						//delay a given number of ticks
#define delayMicroseconds(us)			delayTks((us) * cyclesPerMicrosecond())
#define delayMilliseconds(ms)			delayTks((ms) * cyclesPerMillisecond())
#define delay(ms)						delayMilliseconds(ms)
#define cyclesPerMicrosecond()			(F_CPU / 1000000ul)
#define cyclesPerMillisecond()			(F_CPU / 1000)

//advanced IO
//void tone(void);									//tone frequency specified by F_TONE in STM8Sduino.h
//void noTone(void);
//shiftin/out: bitOrder = MSBFIRST or LSBFIRST
uint8_t shiftIn(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder);
void shiftOut(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder, uint8_t val);
uint32_t pulseIn(PIN_TypeDef pin, uint8_t state);		//wait for a pulse and return timing

//pwm output
void analogWriteInit(PIN_TypeDef pin);					//initialize analog write output
void analogWrite(PIN_TypeDef pin, uint32_t dc);			//generate output

//analog read on ADC1
//read DRL first for right aligned results
uint16_t analogRead(PIN_TypeDef pin);

//analog reference - default to AVdd-AVss
//Vref sources: 0->Vref = AVdd-AVss, 1->Vref+-AVss, 2->AVdd-Vref-, 3->Vref+ - Vref-
//void analogReference(uint8_t Vref);

//interrupts
//install external interrupt handler
//mode 1: falling edge, 0: rising edge
//void attachInterrupt(uint8_t intx, void (*isrptr) (void), uint8_t mode);
//void detachInterrupt(uint8_t intx);

//change notification interrupts
//install user CN interrupt handler
//void attachCNInterrupt(void (*isrptr) (void));
//void detachCNInterrupt(void);
//void activateCNInterrupt(uint8_t cnx, uint8_t pue);
//void deactivateCNInterrupt(uint8_t cnx);

//global variables

//reset the mcu
void mcuInit(void);

//empty interrupt handler
void empty_handler(void);

//timer0
void tmr0Init(void);					//initializer tmr0
#define tmr0SetPS(ps)	T0PR = (ps) - 1	//set the prescaler
#define tmr0GetPS()		(T0PR+1)		//get the prescaler
#define tmr0PWMInit()	do {tmr0Init(); tmr0SetPS(1); tmr0PWM3Init(); tmr0PWMSetPR(PWM_PR);} while (0)	//initialize tmr3 pwm, using channel 3 as reset
#define tmr0PWMSetPR(pr)	tmr0PWM3SetDC(pr)
#define tmr0PWMGetPR()		tmr0PWM3GetDC()

void tmr0OC0SetPR(uint32_t pr);			//initialize timer0/match channel 0 period
uint32_t tmr0OC0GetPR(void);				//read timer period
void tmr0OC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr0
void tmr0IC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr0IC0Get()	(T0CR0)			//return the captured value
void tmr0PWM0Init(void);				//initialize pwm
#define tmr0PWM0SetDC(dc)	T0MR0 =-(dc)	//set duty cycle
#define tmr0PWM0GetDC()		((uint32_t) -T0MR0)		//get duty cycle

void tmr0OC1SetPR(uint32_t pr);			//initialize timer0/match channel 1 period
uint32_t tmr0OC1GetPR(void);				//read timer period
void tmr0OC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr1
void tmr0IC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic1
#define tmr0IC1Get()	(T0CR1)			//return the captured value
void tmr0PWM1Init(void);				//initialize pwm
#define tmr0PWM1SetDC(dc)	T0MR1 =-(dc)	//set duty cycle
#define tmr0PWM1GetDC()		((uint32_t) -T0MR1)		//get duty cycle

void tmr0OC2SetPR(uint32_t pr);			//initialize timer0/match channel 2 period
uint32_t tmr0OC2GetPR(void);				//read timer period
void tmr0OC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr2
void tmr0IC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic2
#define tmr0IC2Get()	(T0CR2)			//return the captured value
void tmr0PWM2Init(void);				//initialize pwm
#define tmr0PWM2SetDC(dc)	T0MR2 =-(dc)	//set duty cycle
#define tmr0PWM2GetDC()		((uint32_t) -T0MR2)		//get duty cycle

void tmr0OC3SetPR(uint32_t pr);			//initialize timer0/match channel 3 period
uint32_t tmr0OC3GetPR(void);				//read timer period
void tmr0OC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr3
void tmr0IC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic3
#define tmr0IC3Get()	(T0CR3)			//return the captured value
void tmr0PWM3Init(void);				//initialize pwm
#define tmr0PWM3SetDC(dc)	T0MR3 =(dc)	//set duty cycle
#define tmr0PWM3GetDC()		((uint32_t) T0MR3)		//get duty cycle

//timer1
void tmr1Init(void);					//initializer tmr0
#define tmr1SetPS(ps)	T1PR = (ps) - 1	//set the prescaler
#define tmr1GetPS()		(T1PR+1)		//get the prescaler
#define tmr1PWMInit()	do {tmr1Init(); tmr1SetPS(1); tmr1PWM3Init(); tmr1PWMSetPR(PWM_PR);} while (0)	//initialize tmr3 pwm, using channel 3 as reset
#define tmr1PWMSetPR(pr)	tmr1PWM3SetDC(pr)
#define tmr1PWMGetPR()		tmr1PWM3GetDC()

void tmr1OC0SetPR(uint32_t pr);			//initialize timer0/match channel 0 period
uint32_t tmr1OC0GetPR(void);				//read timer period
void tmr1OC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr0
void tmr1IC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr1IC0Get()	(T1CR0)			//return the captured value
void tmr1PWM0Init(void);				//initialize pwm
#define tmr1PWM0SetDC(dc)	T1MR0 =-(dc)	//set duty cycle
#define tmr1PWM0GetDC()		((uint32_t)-T1MR0)		//get duty cycle

void tmr1OC1SetPR(uint32_t pr);			//initialize timer0/match channel 1 period
uint32_t tmr1OC1GetPR(void);				//read timer period
void tmr1OC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr1
void tmr1IC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic1
#define tmr1IC1Get()	(T1CR1)			//return the captured value
void tmr1PWM1Init(void);				//initialize pwm
#define tmr1PWM1SetDC(dc)	T1MR1 =-(dc)	//set duty cycle
#define tmr1PWM1GetDC()		((uint32_t)-T1MR1)		//get duty cycle

void tmr1OC2SetPR(uint32_t pr);			//initialize timer0/match channel 2 period
uint32_t tmr1OC2GetPR(void);				//read timer period
void tmr1OC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr2
void tmr1IC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic2
#define tmr1IC2Get()	(T1CR2)			//return the captured value
void tmr1PWM2Init(void);				//initialize pwm
#define tmr1PWM2SetDC(dc)	T1MR2 =-(dc)	//set duty cycle
#define tmr1PWM2GetDC()		((uint32_t)-T1MR2)		//get duty cycle

void tmr1OC3SetPR(uint32_t pr);			//initialize timer0/match channel 3 period
uint32_t tmr1OC3GetPR(void);				//read timer period
void tmr1OC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr3
void tmr1IC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic3
#define tmr1IC3Get()	(T1CR3)			//return the captured value
void tmr1PWM3Init(void);				//initialize pwm
#define tmr1PWM3SetDC(dc)	T1MR3 = (dc)	//set duty cycle
#define tmr1PWM3GetDC()		((uint32_t) T1MR3)		//get duty cycle


//timer2
void tmr2Init(void);					//initializer tmr0
#define tmr2SetPS(ps)	T2PR = (ps) - 1	//set the prescaler
#define tmr2GetPS()		(T2PR+1)		//get the prescaler
#define tmr2PWMInit()	do {tmr2Init(); tmr2SetPS(1); tmr2PWM3Init(); tmr2PWMSetPR(PWM_PR);} while (0)	//initialize tmr3 pwm, using channel 3 as reset
#define tmr2PWMSetPR(pr)	tmr2PWM3SetDC(pr)
#define tmr2PWMGetPR()		tmr2PWM3GetDC()

void tmr2OC0SetPR(uint32_t pr);			//initialize timer0/match channel 0 period
uint32_t tmr2OC0GetPR(void);				//read timer period
void tmr2OC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr0
void tmr2IC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr2IC0Get()	(T2CR0)			//return the captured value
void tmr2PWM0Init(void);				//initialize pwm
#define tmr2PWM0SetDC(dc)	T2MR0 =-(dc)	//set duty cycle
#define tmr2PWM0GetDC()		((uint32_t) -T2MR0)		//get duty cycle

void tmr2OC1SetPR(uint32_t pr);			//initialize timer0/match channel 1 period
uint32_t tmr2OC1GetPR(void);				//read timer period
void tmr2OC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr1
void tmr2IC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr2IC1Get()	(T2CR1)			//return the captured value
void tmr2PWM1Init(void);				//initialize pwm
#define tmr2PWM1SetDC(dc)	T2MR1 =-(dc)	//set duty cycle
#define tmr2PWM1GetDC()		((uint32_t) -T2MR1)		//get duty cycle

void tmr2OC2SetPR(uint32_t pr);			//initialize timer0/match channel 2 period
uint32_t tmr2OC2GetPR(void);				//read timer period
void tmr2OC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr2
void tmr2IC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr2IC2Get()	(T2CR2)			//return the captured value
void tmr2PWM2Init(void);				//initialize pwm
#define tmr2PWM2SetDC(dc)	T2MR2 =-(dc)	//set duty cycle
#define tmr2PWM2GetDC()		((uint32_t) -T2MR2)		//get duty cycle

void tmr2OC3SetPR(uint32_t pr);			//initialize timer0/match channel 3 period
uint32_t tmr2OC3GetPR(void);				//read timer period
void tmr2OC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr3
void tmr2IC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr2IC3Get()	(T2CR3)			//return the captured value
void tmr2PWM3Init(void);				//initialize pwm
#define tmr2PWM3SetDC(dc)	T2MR3 = (dc)	//set duty cycle
#define tmr2PWM3GetDC()		((uint16_t) T2MR3)		//get duty cycle


//timer3
void tmr3Init(void);					//initializer tmr0
#define tmr3SetPS(ps)	T3PR = (ps) - 1	//set the prescaler
#define tmr3GetPS()		(T3PR+1)		//get the prescaler
#define tmr3PWMInit()	do {tmr3Init(); tmr3SetPS(1); tmr3PWM3Init(); tmr3PWMSetPR(PWM_PR);} while (0)	//initialize tmr3 pwm, using channel 3 as reset
#define tmr3PWMSetPR(pr)	tmr3PWM3SetDC(pr)
#define tmr3PWMGetPR()		tmr3PWM3GetDC()

void tmr3OC0SetPR(uint32_t pr);			//initialize timer0/match channel 0 period
uint32_t tmr3OC0GetPR(void);				//read timer period
void tmr3OC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr0
void tmr3IC0AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr3IC0Get()	(T3CR0)			//return the captured value
void tmr3PWM0Init(void);				//initialize pwm
#define tmr3PWM0SetDC(dc)	T3MR0 =-(dc)	//set duty cycle - pin reset to low and set on match
#define tmr3PWM0GetDC()		((uint16_t) -T3MR0)		//get duty cycle

void tmr3OC1SetPR(uint32_t pr);			//initialize timer0/match channel 1 period
uint32_t tmr3OC1GetPR(void);				//read timer period
void tmr3OC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr1
void tmr3IC1AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr3IC1Get()	(T3CR1)			//return the captured value
void tmr3PWM1Init(void);				//initialize pwm
#define tmr3PWM1SetDC(dc)	T3MR1 =-(dc)	//set duty cycle - pin reset to low and set on match
#define tmr3PWM1GetDC()		((uint16_t) -T3MR1)		//get duty cycle

void tmr3OC2SetPR(uint32_t pr);			//initialize timer0/match channel 2 period
uint32_t tmr3OC2GetPR(void);				//read timer period
void tmr3OC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr2
void tmr3IC2AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr3IC2Get()	(T3CR2)			//return the captured value
void tmr3PWM2Init(void);				//initialize pwm
#define tmr3PWM2SetDC(dc)	T3MR2 =-(dc)	//set duty cycle - pin reset to low and set on match
#define tmr3PWM2GetDC()		((uint16_t) -T3MR2)		//get duty cycle

void tmr3OC3SetPR(uint32_t pr);			//initialize timer0/match channel 3 period
uint32_t tmr3OC3GetPR(void);				//read timer period
void tmr3OC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/mr3
void tmr3IC3AttachISR(void (*isr_ptr)(void));	//install user isr for timer0/ic0
#define tmr3IC3Get()	(T3CR3)			//return the captured value
void tmr3PWM3Init(void);				//initialize pwm
#define tmr3PWM3SetDC(dc)	T3MR3 =(dc)	//set duty cycle - pin reset to low and set on match
#define tmr3PWM3GetDC()		((uint16_t) T3MR3)		//get duty cycle


//#define Mhz					000000ul	//suffix for Mhz
#define F_UART				(F_PHB)	//8Mhz		//crystal frequency
#define UART_BR300			300ul		//buadrate=300
#define UART_BR600			600ul		//buadrate=600
#define UART_BR1200			1200ul		//buadrate=1200
#define UART_BR2400			2400ul		//buadrate=2400
#define UART_BR4800			4800ul		//buadrate=4800
#define UART_BR9600			9600ul		//buadrate=9600
#define UART_BR19200		19200ul		//buadrate=19200
#define UART_BR38400		38400ul		//buadrate=38400
#define UART_BR57600		57600ul		//buadrate=57600
#define UART_BR115200		115200ul	//buadrate=115200

//for uart0
//for compatability
#define uart0Put(ch)		uart0Putch(ch)
#define uart0Get()			uart0Getch()

//initiate the hardware usart
void uart0Init(uint32_t baud_rate);
void uart0Putch(char ch);
void uart0Puts(char *str);
//uint16_t uart0Available(void);
#define uart0Available()	(U0LSR & (1<<0))
//uint16_t uart0Busy(void);
#define uart0Busy()			((U0LSR & (1<<6)) == 0)		//5->tx buffer empty, 6->transmission ends
#define uart0Wait()			while (uart0Busy())

void uart0Putline(char *ln);
//read a char from usart
//uint8_t uart0Getch(void);
#define uart0Getch()		(U0RBR)
void u0Print(char *str, int32_t dat);					//print a string on uart01
#define u0Println()			uart0Puts("\r\n")	//print a return on uart01

//for uart1
//for compatability
#define uart1Put(ch)		uart1Putch(ch)
#define uart1Get()			uart1Getch()

//initiate the hardware usart
void uart1Init(uint32_t baud_rate);
void uart1Putch(char ch);
void uart1Puts(char *str);
//uint16_t uart0Available(void);
#define uart1Available()	(U1LSR & (1<<0))
//uint16_t uart0Busy(void);
#define uart1Busy()			((U1LSR & (1<<6))==0)		//5->tx buffer empty, 6->transmission ends
#define uart1Wait()			while (uart1Busy())

void uart1Putline(char *ln);
//read a char from usart
//uint8_t uart0Getch(void);
#define uart1Getch()		(U1RBR)
void u1Print(char *str, int32_t dat);					//print a string on uart01
#define u1Println()			uart1Puts("\r\n")	//print a return on uart01

//end Serial

//spi0
void spi0Init(void);			//initialize the spi transmission
uint8_t spi0Write(uint8_t dat);	//send spi transmision
#define spi0Read()			spi0Write(0x00)
#define spi0Available()		(!spi0Busy())	  	//1->spi transmission has ended
#define spi0Busy()			((S0SPSR & (1<<7))==0)		//1->spi transmision in progress
//end spi0

//spi1/ssp
void spi1Init(void);			//initialize the spi transmission
uint8_t spi1Write(uint8_t dat);	//send spi transmision
#define spi1Read()			spi1Write(0x00)
#define spi1Available()		(SSPSR & (1<<2))	  	//1->receiving buffer is not empty
#define spi1Busy()			((SSPSR & (1<<1))==0)	//1->buffer is full, 0->buffer is not full so you write to it.
//end spi1/ssp

//rtc
void rtcInit(void);				//reset rtc to use low speed crystal (F_RTC)
void rtcInit2PCLK(void);		//reset rtc to use PCLK
#define rtcSEC()			(SEC)
#define rtcMIN()			(MIN)
#define rtcHOUR()			(HOUR)
#define rtcDOW()			(DOW)
#define rtcDOM()			(DOM)
#define rtcDOY()			(DOY)
#define rtcMON()			(MON)
#define rtcYEAR()			(YEAR)

//end rtc


//i2c
void i2c0Init(void);				//initialize i2c
uint8_t i2c0Write(uint8_t dat);		//send data, return ack status
uint8_t i2c0Read(uint8_t ack);		//read data
#define i2c0NoAck()			do {I2C0CONCLR = 1<<2;} while (0)	//1->send an no ack
#define i2c0Ack()			do {I2C0CONSET = 1<<2; i2c0Wait(); I2C0CONCLR = 1<<2;} while (0)	//1->send an ack
#define i2c0Stop()			do {I2C0CONSET = 1<<4; i2c0Wait();                   } while (0)	//1->send a stop condition -> cleared automatically
#define i2c0Start()			do {I2C0CONSET = (1<<5) | (1<<6); } while (0)	//1->send a start condition
#define i2c0ReStart()		i2c0Start()			//restart condition
#define i2c0Wait()			do {while ((I2C0CONSET & (1<<3)) == 0) continue; I2C0CONCLR = 1<<3;} while (0)		//wait for the transmission to finish

void i2c1Init(void);				//initialize i2c

//pwm / oc
//global defines
//MODER=0b10 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 2, AFR[1]/high byte
#define TIM1CH1toPA8()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 8))) | (0b10<<(2* 8)); GPIOA->OTYPER &=~(1<< 8); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 8))) | (0b01<<(2* 8)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*( 8%8)))) | (2<<(4*( 8%8)));} while (0)
#define TIM1CH2toPA9()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 9))) | (0b10<<(2* 9)); GPIOA->OTYPER &=~(1<< 9); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 9))) | (0b01<<(2* 9)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*( 9%8)))) | (2<<(4*( 9%8)));} while (0)
#define TIM1CH3toPA10()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2*10))) | (0b10<<(2*10)); GPIOA->OTYPER &=~(1<<10); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2*10))) | (0b01<<(2*10)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(10%8)))) | (2<<(4*(10%8)));} while (0)
#define TIM1CH4toPA11()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2*11))) | (0b10<<(2*11)); GPIOA->OTYPER &=~(1<<11); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2*11))) | (0b01<<(2*11)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(11%8)))) | (2<<(4*(11%8)));} while (0)

//MODER=0b10 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 1, AFR[0]/low byte
#define TIM3CH1toPA6()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 6))) | (0b10<<(2* 6)); GPIOA->OTYPER &=~(1<< 6); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 6))) | (0b01<<(2* 6)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 6%8)))) | (1<<(4*( 6%8)));} while (0)
//AF1
#define TIM3CH1toPB4()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 4))) | (0b10<<(2* 4)); GPIOB->OTYPER &=~(1<< 4); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 4))) | (0b01<<(2* 4)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 4%8)))) | (1<<(4*( 4%8)));} while (0)
//AF1
#define TIM3CH2toPA7()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 7))) | (0b10<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 7))) | (0b01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (1<<(4*( 7%8)));} while (0)
//AF1
#define TIM3CH2toPB5()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 5))) | (0b10<<(2* 5)); GPIOB->OTYPER &=~(1<< 5); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 5))) | (0b01<<(2* 5)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 5%8)))) | (1<<(1*( 5%8)));} while (0)
//AF1
#define TIM3CH3toPB0()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 0))) | (0b10<<(2* 0)); GPIOB->OTYPER &=~(1<< 0); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 0))) | (0b01<<(2* 0)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 0%8)))) | (1<<(4*( 0%8)));} while (0)
//AF1
#define TIM3CH4toPB1()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 1))) | (0b10<<(2* 1)); GPIOB->OTYPER &=~(1<< 1); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 1))) | (0b01<<(2* 1)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 1%8)))) | (1<<(4*( 1%8)));} while (0)

//AF4, AFR[0]/low byte
#define TIM14CH1toPA4()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 4))) | (0b10<<(2* 4)); GPIOA->OTYPER &=~(1<< 4); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 4))) | (0b01<<(2* 4)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 4%8)))) | (4<<(4*( 4%8)));} while (0)
#define TIM14CH1toPA7()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 7))) | (0b10<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 7))) | (0b01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (4<<(4*( 7%8)));} while (0)
//AF0, AFR[0]/low byte
#define TIM14CH1toPB1()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 1))) | (0b10<<(2* 1)); GPIOB->OTYPER &=~(1<< 1); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 1))) | (0b01<<(2* 1)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 1%8)))) | (0<<(4*( 1%8)));} while (0)

//MODER=0b10 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 0, AFR[0]/low byte
#define TIM15CH1toPA2()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 2))) | (0b10<<(2* 2)); GPIOA->OTYPER &=~(1<< 2); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 2))) | (0b01<<(2* 2)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 2%8)))) | (0<<(4*( 2%8)));} while (0)
#define TIM15CH2toPA3()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 3))) | (0b10<<(2* 3)); GPIOA->OTYPER &=~(1<< 3); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 3))) | (0b01<<(2* 3)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 3%8)))) | (0<<(4*( 3%8)));} while (0)
//AF=1, AFR[1]/high byte
#define TIM15CH1toPB14()			do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2*14))) | (0b10<<(2*14)); GPIOB->OTYPER &=~(1<<14); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2*14))) | (0b01<<(2*14)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(14%8)))) | (1<<(4*(14%8)));} while (0)
#define TIM15CH1toPB15()			do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2*15))) | (0b10<<(2*15)); GPIOB->OTYPER &=~(1<<15); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2*15))) | (0b01<<(2*15)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(15%8)))) | (1<<(4*(15%8)));} while (0)

//MODER=0b10 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 5, AFR[0]/low byte
#define TIM16CH1toPA6()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 6))) | (0b10<<(2* 6)); GPIOA->OTYPER &=~(1<< 6); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 6))) | (0b01<<(2* 6)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 6%8)))) | (5<<(4*( 6%8)));} while (0)
//AF2, AFR[1]/high byte
#define TIM16CH1toPB8()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 8))) | (0b10<<(2* 8)); GPIOB->OTYPER &=~(1<< 8); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 8))) | (0b01<<(2* 8)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*( 8%8)))) | (2<<(4*( 8%8)));} while (0)

//MODER=0b10 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 5, AFR[0]/low byte
#define TIM17CH1toPA7()				do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(0b11<<(2* 7))) | (0b10<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(0b11<<(2* 7))) | (0b01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (5<<(4*( 7%8)));} while (0)
//AF2, AFR[1]/high byte
#define TIM17CH1toPB9()				do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(0b11<<(2* 9))) | (0b10<<(2* 9)); GPIOB->OTYPER &=~(1<< 9); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(0b11<<(2* 9))) | (0b01<<(2* 9)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*( 9%8)))) | (2<<(4*( 9%8)));} while (0)
//global variables

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm1Init(uint16_t TxCCP_PS);

//set duty cycle
#define pwm1SetDC1(dc)		TIM1->CCR1 = (dc)
#define pwm1SetDC2(dc)		TIM1->CCR2 = (dc)
#define pwm1SetDC3(dc)		TIM1->CCR3 = (dc)
#define pwm1SetDC4(dc)		TIM1->CCR4 = (dc)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm3Init(uint16_t TxCCP_PS);

//set duty cycle
#define pwm3SetDC1(dc)			TIM3->CCR1 = (dc)
#define pwm3SetDC2(dc)			TIM3->CCR2 = (dc)
#define pwm3SetDC3(dc)			TIM3->CCR3 = (dc)
#define pwm3SetDC4(dc)			TIM3->CCR4 = (dc)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm14Init(uint16_t TxCCP_PS);
//set duty cycle
#define pwm14SetDC1(dc)			TIM14->CCR1 = (dc)
#define pwm14SetDC2(dc)			TIM14->CCR2 = (dc)
#define pwm14SetDC3(dc)			TIM14->CCR3 = (dc)
#define pwm14SetDC4(dc)			TIM14->CCR4 = (dc)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm15Init(uint16_t TxCCP_PS);
//set duty cycle
#define pwm15SetDC1(dc)			TIM15->CCR1 = (dc)
#define pwm15SetDC2(dc)			TIM15->CCR2 = (dc)
#define pwm15SetDC3(dc)			TIM15->CCR3 = (dc)
#define pwm15SetDC4(dc)			TIM15->CCR4 = (dc)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm16Init(uint16_t TxCCP_PS);
//set duty cycle
#define pwm16SetDC1(dc)			TIM16->CCR1 = (dc)
#define pwm16SetDC2(dc)			TIM16->CCR2 = (dc)
#define pwm16SetDC3(dc)			TIM16->CCR3 = (dc)
#define pwm16SetDC4(dc)			TIM16->CCR4 = (dc)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm17Init(uint16_t TxCCP_PS);
//set duty cycle
#define pwm17SetDC1(dc)			TIM17->CCR1 = (dc)
#define pwm17SetDC2(dc)			TIM17->CCR2 = (dc)
#define pwm17SetDC3(dc)			TIM17->CCR3 = (dc)
#define pwm17SetDC4(dc)			TIM17->CCR4 = (dc)

//adc
//adc channel definitions
#define ADC_CH0			(1ul<<0)
#define ADC_CH1			(1ul<<1)
#define ADC_CH2			(1ul<<2)
#define ADC_CH3			(1ul<<3)
#define ADC_CH4			(1ul<<4)
#define ADC_CH5			(1ul<<5)
#define ADC_CH6			(1ul<<6)
#define ADC_CH7			(1ul<<7)

//convert temperature sensor adc reading into temperaturex10
//follow the datasheet. 3.3v Vref (3.0v for my board), 12bit adc
#define Tx10(adc)		(3529 - ((uint32_t) (3300*10*10/43 * (adc)) >> 12))

//rest the adc
//automatic sampling (ASAM=1), manual conversion
void adcInit(void);
uint16_t adcRead(uint8_t ch);

//read the adc
uint16_t analogRead(PIN_TypeDef pin);
//end ADC


//input capture
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic1Init(void);
void ic1AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic1Get(void);							//read buffer value

void ic2Init(void);
void ic2AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic2Get(void);							//read buffer value

void ic3Init(void);
void ic3AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic3Get(void);							//read buffer value

void ic4Init(void);
void ic4AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic4Get(void);							//read buffer value

void ic5Init(void);
void ic5AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic5Get(void);							//read buffer value
//end input capture

//int - level sensitive
void int0Init(int intEdge);							//initialize the module
void int0AttachISR(void (*isrptr) (void));		//attach user isr

void int1Init(int intEdge);							//initialize the module
void int1AttachISR(void (*isrptr) (void));		//attach user isr

void int2Init(int intEdge);							//initialize the module
void int2AttachISR(void (*isrptr) (void));		//attach user isr

void int3Init(int intEdge);							//initialize the module - not implemented
void int3AttachISR(void (*isrptr) (void));		//attach user isr

void int4Init(int intEdge);							//initialize the module - not implemented
void int4AttachISR(void (*isrptr) (void));		//attach user isr
//end int

//spi

//end spi

//i2c
//end i2c

//rtcc
//end rtcc

//extint
//pin: one pin only
//gpio: GPIOA..GPIOG
void extiInit(LPC_GPIO_TypeDef * gpio, uint16_t pin, uint8_t edge);
void extiAttachISR(uint16_t pin, void (*isr_ptr)(void));		//install user handler
//end extint


#endif
