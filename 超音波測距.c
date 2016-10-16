#include <REG_MG82FL524-564.H>
#include <stdio.h>
#include "UART.h"

#define ECHO_PIN P20
#define TRIG_PIN P21

void delay1ms(unsigned int x)
{
	unsigned int i,j;
	
	for(i=0;i<x;i++)
		for(j=0;j<1880;j++);
}

void delay10us(unsigned char x)
{
	unsigned char i,j;
	
	for(i=0;i<x;i++)
		for(j=0;j<5;j++);
}

int EchoTime=0;

int main()
{
	UART_Initial();
	TMOD|=0x01; //Timer0 at mode1
	P2 = 0x00;;
	ECHO_PIN=1;;
	
	printf("Ultra Sonic Distance meter\r\n");
	
	while(1)
	{
		EchoTime = 0; //�k�s
		TH0=TL0=0x00; //�k�s
		
		//Output a last 10us pulse to Trigger
		TRIG_PIN=1;
		delay10us(2);
		TRIG_PIN=0;
		
		while((!ECHO_PIN) && ((TH0*256+TL0)<4000));	//����Echo pulse�}�l
		TR0=1;
		
		while(ECHO_PIN);	//����Echo pulse����
		TR0=0;
		
		EchoTime = TH0*256 + TL0;
		//EchoTime *= 0.542534;	//a Timer bit is 0.542534uSec
	
		printf("%d\n",EchoTime);
		//printf("Echo Time = %duSec, Distance=%dcm\r\n",EchoTime,EchoTime/58); 
		delay1ms(100);
	}
}