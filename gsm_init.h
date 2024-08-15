#include <LPC17xx.H>
#include "delay2.h"


void gsm_init(void)
	
{
unsigned char k;
unsigned char cmd1[]="AT\r\n";
unsigned char cmd2[]="AT+CREG?\r\n";
unsigned char cmd3[]="AT+CMGF=1\r\n";


//use a function to init 
for(k=0;cmd1[k]!='\0';k++)
   {
		
    LPC_UART0-> THR=cmd1[k];
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
		
	  {
    }
	}
	
delay2(0xFFFFF);
	
for(k=0;cmd2[k]!='\0';k++)
   {
		
    LPC_UART0-> THR=cmd2[k];
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
		
	  {
    }
	}
delay2(0xFFFFF);	 
	
for(k=0;cmd3[k]!='\0';k++)
   {
		
    LPC_UART0-> THR=cmd3[k];
		
	  while((LPC_UART0->LSR&0X20)!=0X20)
		
	  {
    }
	}
	 
delay2(0xFFFFF);	




}