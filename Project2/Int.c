#include <regx51.h>
#include <intrins.h>
#include "Delay.h"

char a[]={0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98};
int i=0;
int j=8;
flag=0;
void Init()
{
	IT0=1;
	EX0=1;
	IT1=1;
	EX1=1;
	EA=1;
}

void k1() interrupt 0
{
	
	if(P3_2==0)
	{
		DelayMs(10);
		while(P3_2==0);
		flag=1;
		i=0;
	}
	
}
void k2() interrupt 2
{
	if(P3_3==0)
	{	
		DelayMs(10);
		while(P3_3==0);
		flag=2;
		j=8;
	}
}

void goUp()
{
	
	while(flag==1)
	{
		P1=a[i];
		i++;
		if(i>8)
			i=8;
		DelayMs(300);
	}
}

void goLow()
{
	
	while(flag==2)
	{
		P1=a[j];
		j--;
		if(j<0)
			j=0;
		DelayMs(300);
	}
}

void main()
{
	Init();
	while(1)
	{
		if(flag==1)
			goUp();
		if(flag==2)
			goLow();
	}
}



