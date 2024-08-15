#include <LPC17xx.H>

void delay(unsigned long int di);
unsigned int j;
unsigned char val;
int main()
{
SystemInit ();
LPC_SC->PCONP&=0X00008000;
//LPC_GPIO0->FIOMASK1 |=0XF0;
//LPC_GPIO0->FIODIR1 |=0X0F;	
LPC_GPIO0->FIOMASK |=0XBFDFF0FF;
LPC_GPIO0->FIODIR |=0X00200F00;	
//for (val=0X0000;val<0X1000;val++)
//{
//LPC_GPIO0->FIOSET1|=val;	
//delay(0x200000);	

//LPC_GPIO0->FIOCLR1|=val;	
///delay(0x200000);

//LPC_GPIO0->FIOPIN1=val;	
//delay(0x200000);	
	
//}
//while(1);
//}

while(1)
{
val= LPC_GPIO0->FIOPIN3;

if (val==0x40)
{
	LPC_GPIO0->FIOSET1 =0X0F;	
	for(j=0;j<10;j++)
	{
		LPC_GPIO0->FIOSET=0X00200000;
	  delay(0x10000);
	  LPC_GPIO0->FIOCLR=0X00200000;
    delay(0x10000);
	}
	//while(1);
}
else
{
  LPC_GPIO0->FIOCLR1 =0X0F;	
  //delay(0x100000);
}

}
}
void delay(unsigned long int di)
{
unsigned long int i=0;
 for(i=0;i<di;i++);

}