#include <LPC17xx.H>

void delay(unsigned long int di);
unsigned int ad0;
unsigned int j;
int main()

{
SystemInit ();
LPC_SC->PCONP |= 0x00001000;
LPC_GPIO0->FIOMASK =0XFF9FF0FF;
LPC_GPIO0->FIODIR |=0X00600F00;	
	
LPC_PINCON -> PINSEL3=0XC0000000;
LPC_ADC -> ADCR= 0x00210320;
	
	
while(1)
{

	
	while((LPC_ADC -> ADSTAT & 0x00000020) != 0x00000020)
	{	
	}
  ad0 =((LPC_ADC->ADDR5 & 0x0000FFF0)>>4);
	 if(ad0 <= 0x174)
	 {
		 for(j=0;j<10;j++)
		 {
	   LPC_GPIO0->FIOPIN=0x00600F00;
		 delay(20000);
		 LPC_GPIO0->FIOPIN=0x00400F00;
		 delay(20000);
		 }
	 }
   else if (ad0>0x0174 & ad0<0x4DA)
	 {
		 LPC_GPIO0->FIOPIN=0x00000000;
     
	 }
   else if (ad0>0x4DA)
	 {
     for(j=0;j<10;j++)
		 {
	   LPC_GPIO0->FIOPIN=0x00600F00;
		 delay(20000);
		 LPC_GPIO0->FIOPIN=0x00400F00;
		 delay(20000);
		 }
	 }

}
}

void delay(unsigned long int di)
{
unsigned long int i=0;
 for(i=0;i<di;i++);

}