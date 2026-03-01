//#include<LPC21xx.h>

//#include"header.h"

//#define RS (1<<8)

//#define RW (1<<9)

//#define EN (1<<10)





//void lcd_data(s8 data)

//{

//IOCLR0 = 0x7FF;

//IOSET0 = data;

//IOSET0 = RS;

//IOCLR0 = RW;

//IOSET0 = EN;

//delay_ms(2);

//IOCLR0 = EN;

//}



//void lcd_cmd(s8 cmd)

//{

//IOCLR0 = 0x7FF;

//IOSET0 = cmd;

//IOCLR0 = RS;

//IOCLR0 = RW;

//IOSET0 = EN;

//delay_ms(2);

//IOCLR0 = EN;

//}





//void lcd_init(void)

//{

//IODIR0 |= 0x7FF;

//lcd_cmd(0x38);

//lcd_cmd(0x0E);

//lcd_cmd(0x01);

//}



//void lcd_string(char *ptr)

//{

//while(*ptr){

//lcd_data(*ptr);

//ptr++;

//}

//}





//void lcd_cgram(void)

//{

// 	u8 a1[8]={0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00};



//	u8 a2[8]={0x00,0x10,0x18,0x1C,0x1E,0x1C,0x18,0x10};



//	u8 a3[8]={0x00,0x01,0x03,0x07,0x0F,0x07,0x03,0x01};



//	u8 a4[8]={0x03,0x05,0x09,0x11,0x11,0x09,0x05,0x03};



//	u8 a5[8]={0x1E,0x00,0x1E,0x00,0x1E,0x00,0x1E,0x00};



//	int i;



//	lcd_cmd(0x40);

//	for(i=0;i<8;i++)

//	{

//	 	lcd_data(a1[i]);

//	}



//	lcd_cmd(0x40+8);

//	for(i=0;i<8;i++)

//	{

//	 	lcd_data(a2[i]);

//	}

//	lcd_cmd(0x40+16);

//	for(i=0;i<8;i++)

//	{

//	 	lcd_data(a3[i]);

//	}



//	lcd_cmd(0x40+24);

//	for(i=0;i<8;i++)

//	{

//	 	lcd_data(a4[i]);

//	}



//	lcd_cmd(0x40+32);

//	for(i=0;i<8;i++)

//	{

//	 	lcd_data(a5[i]);

//	}

//}

