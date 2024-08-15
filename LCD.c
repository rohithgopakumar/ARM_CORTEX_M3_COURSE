#include <LPC17xx.H>
//write a function for this

unsigned char cmd[]={0x38,0x0E,0X06,0X01,0X80},k;
unsigned char msg[]="Hello World";
unsigned char msg2[]="How is world";
void delay(unsigned long int di);
int main()
{
SystemInit ();
//while(1)
{



LPC_SC->PCONP |= 0x00001000;
//PORT INITIALIZATION 

LPC_GPIO0->FIOMASKH =0XE01F;
LPC_GPIO0->FIODIRH |=0X1FE0;	


LPC_GPIO2->FIOMASK1=0XC7;
LPC_GPIO2->FIODIR1=0X38;

//
LPC_GPIO2->FIOCLR1=0X10;  //RW=0
//------------------------------------


LPC_GPIO2->FIOCLR1=0X08;  //RS=0


for(k=0;k<5;k++)
{
  LPC_GPIO0 -> FIOPIN=cmd[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0x5000);
}

LPC_GPIO2->FIOSET1=0X08;  //RS=1


for(k=0;msg[k]!='\0';k++)
{
  LPC_GPIO0 -> FIOPIN=msg[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0x1000);
}


LPC_GPIO2->FIOCLR1=0X08;  //RS=0

LPC_GPIO0 -> FIOPIN=0xC0<<21;
LPC_GPIO2 -> FIOSET1=0x20;
delay(0x500);
LPC_GPIO2 -> FIOCLR1=0x20;
delay(0x10000);


LPC_GPIO2->FIOSET1=0X08; //Rs=1

for(k=0;msg2[k]!='\0';k++)
{
  LPC_GPIO0 -> FIOPIN=msg2[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0x1000);
}

}
}




void delay(unsigned long int di)
{
unsigned long int i=0;
 for(i=0;i<di;i++);

}