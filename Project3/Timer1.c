#include <REGX51.H>

void Timer1_Init(void)		//1����@12.000MHz
{
	ET1=1;
	EA=1;
	PT1=0;
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TL1 = 0x20;				//���ö�ʱ��ʼֵ
	TH1 = 0xD1;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
}
