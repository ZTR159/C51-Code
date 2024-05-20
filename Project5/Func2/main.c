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
			Compare=i;			//���ñȽ�ֵ���ı�PWMռ�ձ�
			Delay(10);
		}
		for(i=num;i>0;i--)
		{
			Compare=i;			//���ñȽ�ֵ���ı�PWMռ�ձ�
			Delay(10);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	Counter++;
	Counter%=255;	//����ֵ�仯��Χ������0~99
	if(Counter<Compare)	//����ֵС�ڱȽ�ֵ
	{
		P2_1=1;		//���1
	}
	else				//����ֵ���ڱȽ�ֵ
	{
		P2_1=0;		//���0
	}
}