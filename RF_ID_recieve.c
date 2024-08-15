#include <LPC17xx.H>
#include "uart0.h"
#include "delay.h"

void uart0_init(void);
unsigned int msg[12],k;
unsigned char data[]="09008206C944",j;
unsigned char data1[]="840085A99038",a;

	
int main()
{
SystemInit ();
//UART INT
LPC_SC->PCONP |= 0x00000000;
LPC_PINCON->PINSEL0 = 0X00000050;
uart0_init();
///////////////////////////////////////////////////////////////////////////////////////////////

	
//LED
	
LPC_GPIO1 -> FIOMASK3=0XDF;
LPC_GPIO1-> FIODIR3=0X20;
LPC_GPIO1->FIOSET3 =0X20 ;

///////////////////////////////////////////////////////////////////////////////////////////////

while(1)
{

//recieving from uart
	for(k=0;k<12;k++)
	{
	while((LPC_UART0->LSR&0X01)!=0X01)
	  {
		}

	msg[k]=LPC_UART0->RBR;
	
	}



//transitting to uart
for(k=0;k<12;k++)	
{
LPC_UART0->THR=msg[k];
		
while((LPC_UART0->LSR&0X20)!=0X20)
	  {
	  }
		

	
}
j=0;a=0;
for(k=0;k<12;k++)
{
 if(msg[k]==data[k])
 {
  j=j+1 ;
 }
 else
 {
 break;
 }

}


for(k=0;k<12;k++)
{
 if(msg[k]==data1[k])
 {
	 a=a+1;
 }
 else
 {
 break;
 }

}

//LPC_GPIO1->FIOSET3 =0X20 ;//led on 

if (j==12 || a==12)
{
 LPC_GPIO1->FIOCLR3 =0X20;
 delay(0xFFFFFF);
	LPC_GPIO1->FIOSET3 =0X20;
}
else 
{
LPC_GPIO1->FIOSET3 =0X20;
}

//if (a!=12)
//{
// LPC_GPIO1->FIOPIN3 =0X20;
//}
//else
//{
//LPC_GPIO1->FIOPIN3 =0X00;
//}
}

}



