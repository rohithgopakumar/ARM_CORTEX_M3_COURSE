#include <LPC17xx.H>
#include "uart0.h"
#include "delay.h"
void delay(unsigned long int di);
void uart0_init(void);
unsigned char k;
unsigned char msg[]="hello Sr";

int main()
	

{

SystemInit ();
LPC_SC->PCONP |= 0x00000000;
LPC_PINCON->PINSEL0 = 0X00000050;
uart0_init();

for(k=0;msg[k]!='\0';k++)
{
  LPC_UART0-> THR=msg[k];
	while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }
	
}
while(1);
}






