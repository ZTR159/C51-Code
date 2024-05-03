#include <REGX51.H>
#include "Delay.h"
#include "UART.h"
#include "LCD1602.h"
#include "string.h"
#include <stdlib.h>

char str[32]="";
static char index=0;

void main()
{
	LCD_Init();
	UART_Init();
	
	while(1)
	{
		if(index<17) LCD_ShowString(1,1,str);//����16������ʾ�ڵ�һ��
		else
		{
			LCD_ShowString(2,1,&str[16]);//���ȳ���16��ʾ�ڵڶ���
			if(index>32) index=0;//���ȳ���32������0
		}
	}
}


void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		char rev=SBUF;
		RI=0;
		if(rev>=97 && rev<=122)//Сдת��д
		{
			UART_SendByte(rev-32);//�ش�
			str[index]=rev-32;
		}
		else
		{
			UART_SendByte(rev);//�ش�
			str[index]=rev;
		}
		
		index++;
	}
}