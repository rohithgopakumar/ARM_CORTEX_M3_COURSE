#include <LPC17xx.H>
#include "delay.h"
#include "uart0.h"
unsigned int ad0;
unsigned char k;
//unsigned char msg[4];
void convert(unsigned int adc);

int main()
{
SystemInit ();
	//ADC
LPC_SC->PCONP |= 0x00001000;
LPC_GPIO1->FIOMASK3 =0X7F;
LPC_GPIO1->FIODIR3=0X00;
	
LPC_PINCON -> PINSEL3=0XC0000000;
LPC_ADC -> ADCR= 0x00210320;
/////////////////////////////////////////////////////////////////////
	
//UART
LPC_PINCON->PINSEL0 = 0X00000050;
uart0_init();
	
	
	
////////////////////////////////////////////////////////////////////
while(1)
{

while((LPC_ADC -> ADSTAT & 0x00000020) != 0x00000020)
	{	
	}
	ad0 =((LPC_ADC->ADDR5 & 0x0000FFF0)>>4);
	
	convert(ad0);
	
		
		


  
	
	

}
}

void convert(unsigned int adc)
{
	
unsigned char x1=0,x2=0,x3=0;
x1=adc%0x0A; //0XFFF%0X0A=05
adc=adc/0X0A; //0XFFF/0X0A=0X199
x2=adc%0X0A; //0X199%0X0A=9
adc=adc/0X0A; // 0X199/0X0A=0X28
x3=adc%0X0A; //0x28%0x0A=0x00
adc=adc/0X0A; //0x28/0x0A=0x04
	
	
	
    {
    LPC_UART0-> THR=adc;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
		delay(0x20000);
		
    {
    LPC_UART0-> THR= x3;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
	  delay(0x20000);
		{
    LPC_UART0-> THR=x2;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
		delay(0x20000);
		
		{
    LPC_UART0-> THR=x1;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
	
    delay(0x2000);
	

}





