#include <REGX51.H>
#include "Delay.h"
#include "LCD1602.h"
#include "XPT2046.h"
#include "Timer0.h"

unsigned char Counter,Compare,i,num;

void main()
{
	LCD_Init();
	Timer0_Init();
	while(1)
	{

		num=XPT2046_ReadAD(XPT2046_XP);
		LCD_ShowString(1,1,"Pot");  
		LCD_ShowNum(2,1,num,3);

		for(i;i<num;i++)
		{
			Compare=i;			//设置比较值，改变PWM占空比
			Delay(10);
		}
		for(i=num;i>0;i--)
		{
			Compare=i;			//设置比较值，改变PWM占空比
			Delay(10);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	Counter++;
	Counter%=255;	//计数值变化范围限制在0~99
	if(Counter<Compare)	//计数值小于比较值
	{
		P2_1=1;		//输出1
	}
	else				//计数值大于比较值
	{
		P2_1=0;		//输出0
	}
}