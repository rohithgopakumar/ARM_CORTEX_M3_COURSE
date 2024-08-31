#include <LPC17xx.H>
#include "delay.h"
#include "uart0.h"
unsigned char k,GpsRx,i,j,m,n;
unsigned char GpsData[70];
unsigned char cmd[]={0x38,0x0E,0X06,0X01,0X80};
unsigned char msg1[]="Lat";
unsigned char msg2[]="Lon";
int main()
	


{
SystemInit ();	
LPC_SC->PCONP |= 0x00000000;
LPC_SC->PCONP |= 0x00001000;
LPC_SC->PCONP |= 0x02000000;
LPC_GPIO0->FIOMASKH =0XE01F;
LPC_GPIO0->FIODIRH |=0X1FE0;
LPC_GPIO2->FIOMASK1=0XC7;
LPC_GPIO2->FIODIR1=0X38;
LPC_PINCON->PINSEL0 = 0X00000050;
uart0_init();
	
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


while(1)
	
{
	
do{
while((LPC_UART0->LSR&0X01)!=0X01)
	  {
	  }		
GpsRx=LPC_UART0->RBR;
	} while(GpsRx!='$');    //checks if the lsr ==1 and then checks if symbol is $ sign

	
i = 0;
do {
    while((LPC_UART0->LSR & 0x01) != 0x01) {
        
    }        
    GpsData[i] = LPC_UART0->RBR; 
    i = i + 1;                   
} while(GpsData[i - 1] != '\r');  



	if (GpsData[2]== 'R'  && GpsData[17]== 'A')
	{
		
	LPC_GPIO2->FIOSET1=0X08; //Rs=1
		
for(m=0;msg1[m]!='\0';m++)
{
  LPC_GPIO0 -> FIOPIN=msg1[m] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0xFFFFF);
}

   //LPC_GPIO2->FIOSET1=0X08; //Rs=1
   j=18;
   while(j<29 && GpsData[j-1] != '\r')
   {
  LPC_GPIO0 -> FIOPIN=GpsData[j] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0xFFFFF);
	j=j+1;
   }
	 	 
  delay(0x5000);	 	 
  LPC_GPIO2->FIOCLR1=0X08;  //RS=0
  LPC_GPIO0 -> FIOPIN=0xC0<<21;
  LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
  LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0x10000);
	 	 
	 
	 
	 LPC_GPIO2->FIOSET1=0X08; //Rs=1

for(n=0;msg2[n]!='\0';n++)
{
  LPC_GPIO0 -> FIOPIN=msg2[n] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0xFFFFF);
}
	 //LPC_GPIO2->FIOSET1=0X08; //Rs=1
   k=30;
   while(k<42 && GpsData[k-1] != '\r')
   {
  LPC_GPIO0 -> FIOPIN=GpsData[k] <<21;
	LPC_GPIO2 -> FIOSET1=0x20;
  delay(0x500);
	LPC_GPIO2 -> FIOCLR1=0x20;
  delay(0xFFFFF);
  k=k+1;
   }
	 
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
	 

	}
	
	
	
	



	




	
}
}





  


