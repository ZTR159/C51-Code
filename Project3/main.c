#include <REGX51.H>
#include "Timer0.h"
#include "Timer1.h"
#include "Delay.h"
#include "MatrixKey.h"
int i=0;
int press=0;
char dig[]={0x3f, 0x06, 0x5b, 0x4f,0x66, 0x6d, 0x7d, 0x07,0x7f, 0x6f, 0x77, 0x7c,0x39, 0x5e, 0x79, 0x71};
char show[]={0,0,0,0,0,0,0,0};
void main()
{
//	Timer0_Init();
	Timer1_Init();
	P2=0x00;
	P0=0x3f;
	while(1)
	{
		char key=MatrixKey();
		if(key)
		{
			

			int tmp=7;
			while(tmp>=0)
			{
				show[tmp]=show[tmp-1];
				tmp--;
			}


			show[0]=dig[key];
			press++;
			if(press>7)
				press=0;
		}
		
	}
}

//unsigned int count0=0;
//void Timer0_LED()	interrupt 1
//{
//	TL0 = 0x18;				//设置定时初始值
//	TH0 = 0xFC;				//设置定时初始值
//	count0++;
//	if(count0%200==0)
//		P3_0=~P3_0;
//	if(count0%300==0)
//		P3_1=~P3_1;
//	if(count0%500==0)
//		P3_2=~P3_2;
//	if(count0%1000==0)
//		P3_3=~P3_3;
//	if(count0==3000)
//		count0=0;
//}

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
		P0=0;
		P0=show[i];
		i++;
		if(i>7)
			i=0;
		if(P2<0)
			P2=0x07;
	}
}
