#include <LPC17xx.H>
#include "uart0.h"
#include "gsm_init.h"
#include "gsm_send.h"
unsigned char k;
void uart0_init(void);
void gsm_init(void);
void gsm_send(void);

int main()
{
SystemInit ();
LPC_SC->PCONP |= 0x00000000;
LPC_PINCON->PINSEL0 = 0X00000050;
uart0_init();
gsm_init();
gsm_send();
}
