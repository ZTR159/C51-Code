#include <REGX51.H>
#include "Delay.h"

unsigned int MatrixKey()
{
	int KeyNum=0;
	
	P1=0xFF;
	P1_0=0;
	if(P1_4==0){Delay(10);while(P1_4==0);Delay(10);KeyNum=1;}
	if(P1_5==0){Delay(10);while(P1_5==0);Delay(10);KeyNum=2;}
	if(P1_6==0){Delay(10);while(P1_6==0);Delay(10);KeyNum=3;}
	if(P1_7==0){Delay(10);while(P1_7==0);Delay(10);KeyNum=4;}
	
	P1=0xFF;
	P1_1=0;
	if(P1_4==0){Delay(10);while(P1_4==0);Delay(10);KeyNum=5;}
	if(P1_5==0){Delay(10);while(P1_5==0);Delay(10);KeyNum=6;}
	if(P1_6==0){Delay(10);while(P1_6==0);Delay(10);KeyNum=7;}
	if(P1_7==0){Delay(10);while(P1_7==0);Delay(10);KeyNum=8;}

	P1=0xFF;
	P1_2=0;
	if(P1_4==0){Delay(10);while(P1_4==0);Delay(10);KeyNum=9;}
	if(P1_5==0){Delay(10);while(P1_5==0);Delay(10);KeyNum=10;}
	if(P1_6==0){Delay(10);while(P1_6==0);Delay(10);KeyNum=11;}
	if(P1_7==0){Delay(10);while(P1_7==0);Delay(10);KeyNum=12;}

	P1=0xFF;
	P1_3=0;
	if(P1_4==0){Delay(10);while(P1_4==0);Delay(10);KeyNum=13;}
	if(P1_5==0){Delay(10);while(P1_5==0);Delay(10);KeyNum=14;}
	if(P1_6==0){Delay(10);while(P1_6==0);Delay(10);KeyNum=15;}
	if(P1_7==0){Delay(10);while(P1_7==0);Delay(10);KeyNum=16;}

	return KeyNum;
}