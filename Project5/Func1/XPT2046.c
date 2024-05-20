#include <REGX52.H>
#include <INTRINS.H>

//引脚定义
sbit XPY2046_DIN=P1^2;
sbit XPY2046_CS=P1^1;
sbit XPY2046_DCLK=P1^0;
sbit XPY2046_DOUT=P1^3;

/**
  * @brief  XPT2046读取AD值
  * @param  Command 命令字，范围：头文件内定义的宏，结尾的数字表示转换的位数
  * @retval AD转换后的数字量，范围：8位为0~255，12位为0~4095
  */
unsigned int XPT2046_ReadAD(unsigned char Command)
{
	unsigned char i;
	unsigned int Data=0;
	XPY2046_DCLK=0;
	XPY2046_CS=0;
	for(i=0;i<8;i++)
	{
		XPY2046_DIN=Command&(0x80>>i);		//发送数据
		XPY2046_DCLK=1;		
		XPY2046_DCLK=0;		//模拟时序信号
	}
	for(i=0;i<16;i++)
	{
		XPY2046_DCLK=1;
		XPY2046_DCLK=0;
		if(XPY2046_DOUT){Data|=(0x8000>>i);}
	}
	XPY2046_CS=1;
	return Data>>8;
}
