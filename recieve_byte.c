#include <LPC17xx.H>
#include "uart0.h"
//#include "delay.h"
//void delay(unsigned long int di);
void uart0_init(void);
unsigned char k;
//unsigned char msg[]="hello Sr";

int main()

{

SystemInit ();
LPC_SC->PCONP |= 0x00000000;
LPC_PINCON->PINSEL0 = 0X00000050;
uart0_init();
	
//LED
	
LPC_GPIO1 -> FIOMASK3=0XDF;
LPC_GPIO1-> FIODIR3=0X20;
while(1)
	
{
	

while((LPC_UART0->LSR&0X01)!=0X01)
	  {
	  }
		
k=LPC_UART0->RBR;
		if(k==0x31)
		{
		 LPC_GPIO1->FIOPIN3 =0X20;
		}
		else if(k==0x30)
		{
		 LPC_GPIO1->FIOPIN3 =0X00;
		}
		else
		{
		}
		
LPC_UART0->THR=k;
		
while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }
		


	
}

}
 