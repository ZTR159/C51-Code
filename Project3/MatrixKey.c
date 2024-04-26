#include <REGX51.H>
#include "Delay.h"

int MatrixKey()
{
	int KeyNumber=0;

	P1=0xFF;// 1111 1111 全部置高电平默认
	P1_7=0; // 矩阵按键第四列扫描
	Delay(5);
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);KeyNumber=16;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);KeyNumber=12;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);KeyNumber=8;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);KeyNumber=4;}

	P1=0xFF;
	P1_6=0; // 矩阵按键第三列扫描
	Delay(5);
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);KeyNumber=15;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);KeyNumber=11;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);KeyNumber=7;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);KeyNumber=3;}

	P1=0xFF;
	P1_5=0; // 矩阵按键第二列扫描
	Delay(20);
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);KeyNumber=14;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);KeyNumber=10;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);KeyNumber=6;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);KeyNumber=2;}

	P1=0xFF;
	P1_4=0; // 矩阵按键第一列扫描
	Delay(20);
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);KeyNumber=13;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);KeyNumber=9;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);KeyNumber=5;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);KeyNumber=1;}

	return KeyNumber;
}