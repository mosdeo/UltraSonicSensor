unsigned char RxBuf;

void UART_Initial(void)
{
	//*************for UART***********//
	TMOD|=0x20;// �ϥ�Timer1 mode2
	SCON=0x70; //
	TH1=TL1=253;//Baud Rate = 19200bps 
	TR1=1; /*Timer1 �Ұ�!*/
	TI=1; //�϶ǰe�i�H�ǰe
	//*************for UART***********//
}