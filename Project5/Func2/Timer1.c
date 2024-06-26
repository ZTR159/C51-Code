#include <REGX51.H>

void Timer1_Init(void)		//1毫秒@12.000MHz
{
	ET1=1;
	EA=1;
	PT1=0;					//打开定时器
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x20;				//设置定时初始值
	TH1 = 0xD1;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
}
