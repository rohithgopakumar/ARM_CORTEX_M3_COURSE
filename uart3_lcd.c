#include <LPC17xx.H>
#include "uart3.h"
#include "delay.h"
#include "uart0.h"
#include "gsm_init.h"
#include "gsm_send.h"


unsigned int msg[12];
unsigned char data[]="09008206C944",j;
unsigned char data1[]="840085A99038",a;
unsigned char cmd[]={0x38,0x0E,0X06,0X01,0X80},k;
unsigned char msg1[]="Hello welcome";
unsigned char msg2[]="PERMISSION DENIED";

void uart0_init(void);
void uart3_init(void);
void gsm_init(void);
void gsm_send(void);
int main()
{
SystemInit ();
//UART INT
LPC_SC->PCONP |= 0x00000000;
LPC_SC->PCONP |= 0x00001000;
LPC_SC->PCONP |= 0x02000000;
LPC_GPIO0->FIOMASKH =0XE01F;
LPC_GPIO0->FIODIRH |=0X1FE0;
LPC_GPIO2->FIOMASK1=0XC7;
LPC_GPIO2->FIODIR1=0X38;
LPC_PINCON->PINSEL0 = 0X00000050;

uart0_init();
LPC_PINCON->PINSEL9 = 0X0F000000;
uart3_init();
gsm_init();
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
//LED
	
LPC_GPIO1 -> FIOMASK3=0XDF;
LPC_GPIO1-> FIODIR3=0X20;
LPC_GPIO1->FIOSET3 =0X20 ;

LPC_GPIO2->FIOCLR1=0X10;  //RW=0
LPC_GPIO2->FIOCLR1=0X08;  //RS=0

for(k=0;k<5;k++)
{
  LPC_GPIO0 -> FIOPIN=cmd[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0x5000);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

while(1)
{
//int the lcd
delay(0xFFFFFF);

LPC_GPIO2->FIOCLR1=0X08;  //RS=0

for(k=0;k<5;k++)
{
  LPC_GPIO0 -> FIOPIN=cmd[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0x5000);
}

//recieving from uart
	for(k=0;k<12;k++)
	{
    	while((LPC_UART3->LSR&0X01)!=0X01)
	  {
		}

	msg[k]=LPC_UART3->RBR;
	
	}



//transitting to uart
for(k=0;k<12;k++)	
{
LPC_UART3->THR=msg[k];
		
while((LPC_UART3->LSR&0X20)!=0X20)
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
//LCD INIT




///////////////////////////////////////////////////////////////
if (j==12 || a==12)
{
  LPC_GPIO1->FIOCLR3 =0X20;
  //delay(0xFFFFFF);
	LPC_GPIO1->FIOSET3 =0X20;
	LPC_GPIO2->FIOSET1=0X08;  //RS=1
	for(k=0;msg1[k]!='\0';k++)
   {
  LPC_GPIO0 -> FIOPIN=msg1[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  //delay(0x1000);
   }

}
else 
{
    LPC_GPIO1->FIOSET3 =0X20;
		LPC_GPIO2->FIOSET1=0X08;  //RS=1
	  for(k=0;msg2[k]!='\0';k++)
    {
    LPC_GPIO0 -> FIOPIN=msg2[k] <<21;
	  LPC_GPIO2 -> FIOSET1=0x20;
    delay(0x500);
	  LPC_GPIO2 -> FIOCLR1=0x20;
    
	    }
		gsm_send();
}


}

}



