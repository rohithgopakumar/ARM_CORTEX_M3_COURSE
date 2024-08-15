#include <LPC17xx.H>
void uart0_init(void)
{

	LPC_UART0->LCR =0X83;
  LPC_UART0->DLM=0X00;
  LPC_UART0->DLL=0X75;
	LPC_UART0->FDR=0X00000010;
	LPC_UART0->LCR=0X03;
	
}