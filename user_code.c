//LPC21duino code
// - using LPC210x: LPC2101/2/3
// - features implemented so far: 
//	- Systick generation via Timer0 overflow
//	- low-power clock gating: peripheral clock disabled on reboot
//	- SystemCoreClock: automatically update SystemCoreClock (=CCLK/F_CPU), and peripheral clock (=PCLK/F_PHB)
//	- GPIO0..5: if available
//	- UART0/1, Timer0..3, External Interrupts0..2
//	- PWM generation on TIMER0..3, Match channel 0..3 - CH3s set periods
//
// - features to be implemented: ADC, RTC, SPI, I2C
// - 
// - version history
// - v0.1, 8/28/2022: initial implementation, including systick, gpio, uart, and output compare
// - v0.2, 8/29/2022: implemented SystemCoreClockUpdate()
// - v0.3, 9/02/2022: PWM implemented
//
//
//               LPC210x (@14.7456Mhz)
//              |=====================|
//        Xtal->|                 P07 |>---------> LED2
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
// unmapped: I2C0/1, ADC, SPI, IC
//
//

#include "lpc21duino.h"					//we use lpc2101/2/3

//hardware configuration
#define LED			P026				//led pin
#define LED_DLY		(F_PHB / 2)		//half a second

#define LED1		P06
#define LED2		P07
//end hardware configuration

//flip led
void led_flp(void) {
	digitalWrite(LED, !digitalRead(LED));
}

//flip p00
void led1_flp(void) {
	digitalWrite(LED1, !digitalRead(LED1));
}

//flip p01
void led2_flp(void) {
	digitalWrite(LED2, !digitalRead(LED2));
}

//user defined set up code
void setup(void) {
	//volatile uint32_t tmp;

	pinMode(LED, OUTPUT);					//led as output pin
	pinMode(P01, OUTPUT); digitalWrite(P01, LOW);	//p0.1 low
	pinMode(LED1, OUTPUT); digitalWrite(LED1, HIGH);
	pinMode(LED2, OUTPUT); digitalWrite(LED2, LOW);
	
	//initialize the timer
	tmr3Init();								//start tmr16b0
	//tmr3SetPS(2);							//set prescaler
	tmr3OC0SetPR(5000); tmr3OC0AttachISR(led1_flp);			//install user isr
	tmr3OC3SetPR(5005); tmr3OC3AttachISR(led2_flp);			//install user isr
	//tmr3IC1AttachISR(led_flp);			//install user isr
	//tmr0PWM0Init();						//initialize pwm
	//tmr0PWM0SetDC(0xffff);				//set duty cycle
	
	//pwm output
	//analogWriteInit(P00); analogWrite(P00, PWM_PR/20);
	//analogWriteInit(P01); analogWrite(P01, PWM_PR/4);

	//tmr3Init(); //tmr3SetPR0(0xffff/1); 	//tmr2OC0AttachISR(led_flp);
	//tmr3PWM3Init();	tmr3PWM3SetDC(-PWM_PR);					//set the period
	//tmr3PWMInit();
	//tmr3PWM0Init();	tmr3PWM0SetDC(PWM_PR/2);
	//tmr3PWM1Init();	tmr3PWM1SetDC(tmr3PWMGetPR()*14/180);
	//tmr3PWM2Init();	tmr3PWM2SetDC(0xffff*10/16);
	//tmp = tmr3PWM1GetDC();
	//exint
	//int0Init(FALLING); int0AttachISR(led_flp);				//attach user isr
	//int1Init(RISING ); int1AttachISR(led_flp);				//attach user isr
	//int2Init(FALLING); int2AttachISR(led_flp);				//attach user isr

	//adc
	//adcInit();
	//adcRead(ADC_CH0);
	//analogRead(P023);

	//spi
	//spi0Init(); spi0Write(0xff);
	//spi1Init(); spi1Write(0xff);

	//rtc
	//rtcInit();
	//rtcInit2PCLK();
	
	//initialize the uart
	uart0Init(UART_BR9600);					//initialize uart1
	uart1Init(UART_BR9600);				//initialize uart2

	//i2c
	//i2c0Init();
	//i2c1Init();
}

//user defined main loop
void loop(void) {
	static uint32_t tick0=0;
	volatile uint32_t tmp0, tmp1;

	if (ticks() - tick0 > LED_DLY) {
		tick0 += LED_DLY;						//advance to the next match point
		digitalWrite(LED, !digitalRead(LED));	//flip led, 105 ticks
		//digitalWrite(LED1, !digitalRead(LED1));
		//digitalWrite(LED2, !digitalRead(LED2));
		//FIOPIN ^= 1<<7;
		//IO_FLP(LPC_FGPIO0, 1<<7);				//fast gpio access
		tmp0=ticks(); 							//time stamp tmp0
		//mandelbrot0();
		//Julia(100, 1, 200, 1);
		//mandelbrot();
		//delay(10);				   			//waste sometime
		//tmr3PWM2SetDC(tmr3PWM2GetDC()+2000);
		//digitalRead(PA5);						//read a pin, 59 ticks (base case = 29 ticks, if there is nothing)
		//uart1Init(UART_BR9600);				//initial uart, 1328 ticks
		//digitalWrite(LED, !digitalRead(LED));	//flip led, 105 ticks
		//tmp=analogRead(ADC_TS);
		//for (tmp=0; tmp<1000; tmp++) digitalWrite(LED, !digitalRead(LED));	//flip led, 89100/1000 ticks
		//for (tmp=0; tmp<1000; tmp++) IO_FLP(LATB, 1<<7);					//flip led, 16040/1000 ticks
#if 0
		FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4;
		FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4;
		FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4;
		FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4; FIOSET = 1<<4; FIOCLR = 1<<4;
#else
		IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4;
		IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4;
		IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4;
		IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4; IOSET = 1<<4; IOCLR = 1<<4;
#endif
tmp0=ticks() - tmp0;
		
		//display some information
		u0Print("tick0=                    ", tick0);
		u0Print("tmp0 =                    ", tmp0);
		u0Println();
	}	
}
