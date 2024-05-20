#include <REGX51.H>
#include "LCD1602.h"
#include "XPT2046.h"

void main()
{
	LCD_Init();
	while(1)
	{
		LCD_ShowString(1,1,"GR1");
		LCD_ShowNum(2,1,XPT2046_ReadAD(XPT2046_VBAT),3);

		LCD_ShowString(1,5,"Pot");
		LCD_ShowNum(2,5,XPT2046_ReadAD(XPT2046_XP),3);
		
		LCD_ShowString(1,9,"NTC1");
		LCD_ShowNum(2,9,XPT2046_ReadAD(XPT2046_YP),3);
	}
}
