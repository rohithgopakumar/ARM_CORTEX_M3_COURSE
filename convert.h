#include <LPC17xx.H>
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
    LPC_UART0-> THR=adc+0x30;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
		delay(0x20000);
		
    {
    LPC_UART0-> THR= x3+0x30;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
	  delay(0x20000);
		{
    LPC_UART0-> THR=x2+0x30;
	
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
		delay(0x10000);
		
		{
    LPC_UART0-> THR=x1+0x30;
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }	
    }
	delay(0xFFFFFFF);
    
	

}