#include <REGX52.H>
#include "string.h"
#include "Delay.h"
#include <stdlib.h>

/**
  * @brief  串口初始化，4800bps@12.000MHz
  * @param  无
  * @retval 无
  */
void UART_Init()
{
	SCON=0x50;		//配置serial control
	PCON |= 0x80;
	TMOD &= 0x0F;	//设置定时器模式
	TMOD |= 0x20;	//设置定时器模式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA=1;
	ES=1;			//打开中断
}

/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);	//TI=1时发送
	TI=0;			//清空
}

void UART_SendStr(unsigned char *Str)
{
	while(*Str!=0)
	{
		SBUF=*Str;
		while(TI==0);
		TI=0;
		Str++;
	}
}


