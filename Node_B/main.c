#include"header.h"

#include <lpc21xx.h>

CAN2_ST M1;

#define LED1 (1<<17)

#define LED2 (1<<18)

#define LED3 (1<<19)



u32 RECEIVER_FLAG;

int main()

{

        float temp,result;

        u32 spd;

        unsigned char flag1=0,flag2=0;

        IODIR0|=LED1|LED2|LED3;
				
				IOCLR0 = LED1|LED2|LED3;
	
        IOSET0|=LED1|LED2|LED3;

        lcd_init();

        can2_init();

        EN_CAN2_INTERRUPT();

        lcd_cgram();

        lcd_cmd(0x80);

        lcd_string("SPD:");

        lcd_cmd(0x88);

        lcd_string("TEMP:");

        lcd_cmd(0xC7);

        lcd_data(3);

        while(1)   //The infinite while(1) loop constantly checks for new CAN data.

        {

                if(RECEIVER_FLAG)

                {

                        RECEIVER_FLAG=0;

                    if(M1.ID==TEMPERATURE_ID)

                        {
													
                                lcd_cmd(0x8D);

                                temp=(M1.BYTEA*3.3)/1023;

                                result=(temp-0.5)/0.01;

                                //lcd_data(((int)result/100)+48);
													
																 lcd_atof(((int)result/100)+48);

                               // lcd_data((((int)result/10)%10)+48);
																
																lcd_atof((((int)result/10)%10)+48);

                                //lcd_data(((int)result%10)+48);
																
																lcd_atof(((int)result%10)+48);
													
                        }

                        if(M1.ID==SPEED_ID)

                        {

                                lcd_cmd(0x84);

                                spd=(M1.BYTEA*280)/1023;

                                lcd_data((spd/100)+48);

                                lcd_data(((spd/10)%10)+48);

                                lcd_data((spd%10)+48);

                        }

                        if(M1.ID==HEADLIGHT_ID)

                        {

                                if(M1.BYTEA==HEADLIGHT_ON)

                                {

                                        lcd_cmd(0xC8);

                                    lcd_data(4);

                                        IOCLR0=LED1;

                                }

                                else if(M1.BYTEA==HEADLIGHT_OFF)

                                {

                                    lcd_cmd(0xC8);

                                    lcd_data(' ');

                                        IOSET0=LED1;

                                }

                        }

                        if(M1.ID==INDICATOR_ID)

                        {

                                if(M1.BYTEA==INDICATOR_RIGHT_ON)

                                {

                                        lcd_cmd(0xC1);

                                        lcd_data(' ');

                                        lcd_data(' ');

                                        lcd_cmd(0xCD);

                                    lcd_data(0);

                                        lcd_data(1);

                                        flag2=1;
                                }

                                else if(M1.BYTEA==INDICATOR_LEFT_ON)

                                {

                                        lcd_cmd(0xC1);

                                    lcd_data(2);

                                        lcd_data(0);

                                        lcd_cmd(0xCD);

                                        lcd_data(' ');

                                        lcd_data(' ');

                                        flag1=1;

                                }

                                else if(M1.BYTEA==INDICATOR_RIGHT_OFF)

                                {

                                        lcd_cmd(0xCD);

                                    lcd_data(' ');

                                        lcd_data(' ');

                                        IOSET0=LED3;

                                        flag2=0;

                                }

                                else if(M1.BYTEA==INDICATOR_LEFT_OFF)

                                {

                                        lcd_cmd(0xC1);

                                    lcd_data(' ');

                                        lcd_data(' ');

                                        IOSET0=LED2;

                                        flag1=0;

                                }

                        }

            }

                if(flag1)
                {
                        IOCLR0=LED2;

                        delay_ms(100);

                        IOSET0=LED2;

                        delay_ms(100);
                }

                if(flag2)
                {
                        IOCLR0=LED3;

                        delay_ms(100);

                        IOSET0=LED3;

                        delay_ms(100);
                }

        }

}
