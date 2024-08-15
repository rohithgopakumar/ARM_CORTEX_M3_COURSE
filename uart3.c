#include <LPC17xx.H>
#include "uart3.h"
#include "delay.h"



void delay(unsigned long int di);
void uart3_init(void);
unsigned char k;
unsigned char msg[]="hello Sr";



int main()
	

{

SystemInit ();
LPC_SC->PCONP |= 0x00000000;
LPC_PINCON->PINSEL9 = 0X0F000000;
uart3_init();

//for(k=0;msg[k]!='\0';k++)
//{
//  LPC_UART3-> THR=msg[k];
//	while((LPC_UART3->LSR&0X20)!=0X20)
//	  {
//	  }
//	
//}
//while(1);
	
while(1)
	
{
	

while((LPC_UART3->LSR&0X01)!=0X01)
	  {
	  }
		
k=LPC_UART3->RBR;
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
		
LPC_UART3->THR=k;
		
while((LPC_UART3->LSR&0X20)!=0X20)
	  {
	  }
		


	
}

}