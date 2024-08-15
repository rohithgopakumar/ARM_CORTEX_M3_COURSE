#include <LPC17xx.H>
void uart3_init(void)
{

	LPC_UART3->LCR =0X83;
  LPC_UART3->DLM=0X00;
  LPC_UART3->DLL=0X75;
	LPC_UART3->FDR=0X00000010;
	LPC_UART3->LCR=0X03;
	
}