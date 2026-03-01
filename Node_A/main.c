	#include<lpc21xx.h>

#include"header.h"

CAN2_ST M1;
/*Flags set by interrupt routines must be declared volatile, otherwise 
compiler optimization may skip reading the updated value.*/

volatile int FLAG_HEADLIGHT;

volatile int FLAG_INDICATOR_RIGHT;

volatile int FLAG_INDICATOR_LEFT;



int main()

{

	int HEADLIGHT_TOGGLE=1;

	int INDICATOR_RIGHT_TOGGLE=1;

	int INDICATOR_LEFT_TOGGLE=1;

	adc_init();

	can2_init();

	ext_init();

	interrupt_confg();

	while(1)

	{

		C2TID1=TEMPERATURE_ID;

		C2TFI1=4<<16;// DLC = 4 bytes

		C2TDA1=adc_read(1); // Read ADC channel 1

		C2CMR=0x21;//// Transmission command


		delay_ms(100);		

		C2TID1=SPEED_ID;		

		C2TFI1=4<<16;

		C2TDA1=adc_read(2);	//ADCR channel 2

		C2CMR=0x21;

		delay_ms(100);


		if(FLAG_HEADLIGHT)

		{

		 	FLAG_HEADLIGHT=0;

			C2TID1=HEADLIGHT_ID;

			C2TFI1=4<<16;

			if(HEADLIGHT_TOGGLE)

			{

				C2TDA1=HEADLIGHT_ON;

				HEADLIGHT_TOGGLE=0;		

			}

			else

			{

				C2TDA1=HEADLIGHT_OFF;

				HEADLIGHT_TOGGLE=1;		

			}	

			C2CMR=0x21;

		}

	  // delay_ms(2000);

		if(FLAG_INDICATOR_RIGHT)

		{

			FLAG_INDICATOR_RIGHT=0;

	   		C2TID1=INDICATOR_ID;

			C2TFI1=4<<16;

	   		if(INDICATOR_RIGHT_TOGGLE)

			{

				C2TDA1=INDICATOR_RIGHT_ON;

				INDICATOR_RIGHT_TOGGLE=0;

				INDICATOR_LEFT_TOGGLE=1;		

			}

			else

			{

				C2TDA1=INDICATOR_RIGHT_OFF;

				INDICATOR_RIGHT_TOGGLE=1;		

			}	

			C2CMR=0x21;

		}

	   //delay_ms(2000);

	   if(FLAG_INDICATOR_LEFT)

		{

	   		FLAG_INDICATOR_LEFT=0;

	   		C2TID1=INDICATOR_ID;

			C2TFI1=4<<16;

	   		if(INDICATOR_LEFT_TOGGLE)

			{

				C2TDA1=INDICATOR_LEFT_ON;

				INDICATOR_LEFT_TOGGLE=0;

				INDICATOR_RIGHT_TOGGLE=1;		

			}

			else

			{

				C2TDA1=INDICATOR_LEFT_OFF;

				INDICATOR_LEFT_TOGGLE=1;		

			}	

			C2CMR=0x21;

		}

	}

}
