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
		if(index<17) LCD_ShowString(1,1,str);//长度16以内显示在第一行
		else
		{
			LCD_ShowString(2,1,&str[16]);//长度超过16显示在第二行
			if(index>32) index=0;//长度超过32索引置0
		}
	}
}


void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		char rev=SBUF;
		RI=0;
		if(rev>=97 && rev<=122)//小写转大写
		{
			UART_SendByte(rev-32);//回传
			str[index]=rev-32;
		}
		else
		{
			UART_SendByte(rev);//回传
			str[index]=rev;
		}
		
		index++;
	}
}