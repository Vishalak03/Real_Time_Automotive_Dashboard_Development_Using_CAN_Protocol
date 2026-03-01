 #include<lpc21xx.h>
 #include<stdio.h>
#include"header.h"

void lcd_data(s8 data)

{

IOCLR1=0X00FE0000;

IOSET1=((data&0XF0)<<16);

IOCLR1=1<<18;

IOSET1=1<<17;

IOSET1=1<<19;

delay_ms(2);

IOCLR1=1<<19;


IOCLR1=0X00FE0000;

IOSET1=((data&0X0F)<<20);

IOCLR1=1<<18;

IOSET1=1<<17;

IOSET1=1<<19;

delay_ms(2);

IOCLR1=1<<19;


}


void lcd_cmd(s8 cmd)

{

IOCLR1=0X00FE0000;

IOSET1=(cmd&0XF0)<<16;

IOCLR1=1<<18;

IOCLR1=1<<17;

IOSET1=1<<19;

delay_ms(2);

IOCLR1=1<<19;


IOCLR1=0X00FE0000;

IOSET1=(cmd&0X0F)<<20;

IOCLR1=1<<18;

IOCLR1=1<<17;

IOSET1=1<<19;

delay_ms(2);

IOCLR1=1<<19;


}

void lcd_init(void)

{

 IODIR1|=0X00FE0000;

 PINSEL2=0;

 lcd_cmd(0x03);

 lcd_cmd(0x02);

 lcd_cmd(0x28);

 lcd_cmd(0x0C);

 lcd_cmd(0x01);

}


void lcd_string(s8 *p)

{

	while(*p)

	{

		lcd_data(*p++);

	}

}
void lcd_integer(int num)
{
char arr[10];
sprintf(arr,"%d",num);
}
void lcd_atof(float f)
{
        int i;
        i=f;
        lcd_integer(i);
        lcd_data('.');

        i=(f-i)*1000;
        lcd_integer(i);
}

void lcd_cgram(void)

{

 	u8 a1[8]={0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00};


	u8 a2[8]={0x00,0x10,0x18,0x1C,0x1E,0x1C,0x18,0x10};


	u8 a3[8]={0x00,0x01,0x03,0x07,0x0F,0x07,0x03,0x01};


	u8 a4[8]={0x03,0x05,0x09,0x11,0x11,0x09,0x05,0x03};


	u8 a5[8]={0x1E,0x00,0x1E,0x00,0x1E,0x00,0x1E,0x00};


	int i;


	lcd_cmd(0x40);

	for(i=0;i<8;i++)

	{

	 	lcd_data(a1[i]);

	}


	lcd_cmd(0x40+8);

	for(i=0;i<8;i++)

	{

	 	lcd_data(a2[i]);

	}

	lcd_cmd(0x40+16);

	for(i=0;i<8;i++)

	{

	 	lcd_data(a3[i]);

	}


	lcd_cmd(0x40+24);

	for(i=0;i<8;i++)

	{

	 	lcd_data(a4[i]);

	}


	lcd_cmd(0x40+32);

	for(i=0;i<8;i++)

	{

	 	lcd_data(a5[i]);

	}

}

