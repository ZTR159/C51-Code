#include <REGX51.H>
#include "Timer0.h"
#include "Timer1.h"
#include "Delay.h"
#include "MatrixKey.h"
int i=0;
char dig[]={0x3f, 0x06, 0x5b, 0x4f,0x66, 0x6d, 0x7d, 0x07,0x7f, 0x6f, 0x77, 0x7c,0x39, 0x5e, 0x79, 0x71};//������ֵ
char show[]={0,0,0,0,0,0,0,0};//ÿ�������Ҫ��ʾ������
void main()
{
//	Timer0_Init();					//��ʼ����ʱ��0
	Timer1_Init();					//��ʼ����ʱ��1
	P2=0x00;//��ʼ��������
	while(1)
	{
		char key=MatrixKey();		//ɨ�谴��
		if(key)
		{
			int tmp=7;
			while(tmp>=0)
			{
				show[tmp]=show[tmp-1];
				tmp--;
			}						//����������ȫ������
			show[0]=dig[key-1];		//�����µİ������µ�������
		}	
	}
}

unsigned int count0=0;
void Timer0_LED()	interrupt 1
{
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	count0++;				//������+1
	if(count0%200==0)		//������200ʱ, ��200msʱ, LED��ƽ��ת
		P3_0=~P3_0;
	if(count0%300==0)		//������300ʱ, ��300msʱ, LED��ƽ��ת
		P3_1=~P3_1;
	if(count0%500==0)		//������500ʱ, ��500msʱ, LED��ƽ��ת
		P3_2=~P3_2;
	if(count0%1000==0)		//������1000ʱ, ��1000msʱ, LED��ƽ��ת
		P3_3=~P3_3;
	if(count0==3000)		//������3000ʱ, ����������, ��ֹ�����洦����
		count0=0;
}


unsigned int count1=0;
void Timer1()	interrupt 3
{
	TL1 = 0x18;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	count1++;
	if(count1==5)			//5msλ��һ��
	{
		count1=0;			//�Ѽ���������
		P2--;				//�������ʾ��һλ
		P0=0;				//�������Ӱ
		P0=show[i];			//��ͬλ����ʾ��ͬ����
		i++;
		if(i>7)
			i=0;			//��ֹ���
		if(P2<0)
			P2=0x07;		//��ֹ���
	}
}
