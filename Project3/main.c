#include <REGX51.H>
#include "Timer0.h"
#include "Timer1.h"
#include "Delay.h"
#include "MatrixKey.h"

char dig[]={0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98};
void main()
{
	Timer0_Init();
	Timer1_Init();
	P2=0x07;
	//P0=0x01;
	while(1)
	{
		int key=MatrixKey();
		if(key)
		{
			key=MatrixKey();
			while(key);
			P0=0x01;
		}
	}
}

unsigned int count0=0;
void Timer0_LED()	interrupt 1
{
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	count0++;
	if(count0%200==0)
		P3_0=~P3_0;
	if(count0%300==0)
		P3_1=~P3_1;
	if(count0%500==0)
		P3_2=~P3_2;
	if(count0%1000==0)
		P3_3=~P3_3;
	if(count0==3000)
		count0=0;
}

unsigned int count1=0;

void Timer1()	interrupt 3
{
	TL1 = 0x18;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	count1++;
	if(count1==5)
	{
		count1=0;
		P2--;
		if(P2<0)
			P2=0x07;
	}
}
