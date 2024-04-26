#include <REGX51.H>
#include "Timer0.h"
#include "Timer1.h"
#include "Delay.h"
#include "MatrixKey.h"
int i=0;
char dig[]={0x3f, 0x06, 0x5b, 0x4f,0x66, 0x6d, 0x7d, 0x07,0x7f, 0x6f, 0x77, 0x7c,0x39, 0x5e, 0x79, 0x71};//按键键值
char show[]={0,0,0,0,0,0,0,0};//每个数码管要显示的内容
void main()
{
//	Timer0_Init();					//初始化定时器0
	Timer1_Init();					//初始化定时器1
	P2=0x00;//初始化译码器
	while(1)
	{
		char key=MatrixKey();		//扫描按键
		if(key)
		{
			int tmp=7;
			while(tmp>=0)
			{
				show[tmp]=show[tmp-1];
				tmp--;
			}						//将数组内容全部后移
			show[0]=dig[key-1];		//将最新的按键更新到数组中
		}	
	}
}

unsigned int count0=0;
void Timer0_LED()	interrupt 1
{
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	count0++;				//计数器+1
	if(count0%200==0)		//计数器200时, 即200ms时, LED电平反转
		P3_0=~P3_0;
	if(count0%300==0)		//计数器300时, 即300ms时, LED电平反转
		P3_1=~P3_1;
	if(count0%500==0)		//计数器500时, 即500ms时, LED电平反转
		P3_2=~P3_2;
	if(count0%1000==0)		//计数器1000时, 即1000ms时, LED电平反转
		P3_3=~P3_3;
	if(count0==3000)		//计数器3000时, 计数器归零, 防止后续益处风险
		count0=0;
}


unsigned int count1=0;
void Timer1()	interrupt 3
{
	TL1 = 0x18;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	count1++;
	if(count1==5)			//5ms位移一次
	{
		count1=0;			//把计数器归零
		P2--;				//数码管显示下一位
		P0=0;				//数码管消影
		P0=show[i];			//不同位置显示不同数字
		i++;
		if(i>7)
			i=0;			//防止溢出
		if(P2<0)
			P2=0x07;		//防止溢出
	}
}
