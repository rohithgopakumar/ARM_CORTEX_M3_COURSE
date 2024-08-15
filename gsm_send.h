#include <LPC17xx.H>
#include "delay1.h"


void gsm_send(void)
	
{
unsigned char cmd4[]="AT+CMGS=\"7019781361\"\r\n";
unsigned char cmd5[]="Intruder Alert!!!!!!!!!!!!!!!!!",k;
	for(k=0;cmd4[k]!='\0';k++)
   {
		
    LPC_UART0-> THR=cmd4[k];
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
		
	  {
    }
	}
	 
delay1(0xFFFFF);	
	
for(k=0;cmd5[k]!='\0';k++)
   {
		
    LPC_UART0-> THR=cmd5[k];
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
		
	  {
    }
	}
	 
delay1(0xFFFFF);
{	
	    LPC_UART0-> THR=0x1A;
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
		
	  {
    }
	 
}
	
	
}