#include <REGX51.H>


void Timer0_Init(void)		//1毫秒@12.000MHz
{
	ET0=1;
	EA=1;
	PT0=0;
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x9C;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
}

