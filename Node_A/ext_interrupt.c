#include<lpc21xx.h>

#include"header.h"

extern int FLAG_HEADLIGHT;

extern int FLAG_INDICATOR_RIGHT;

extern int FLAG_INDICATOR_LEFT;
 
 int flag1=1,flag2=1,flag3=1;

void ext_init(void)

{

 	PINSEL0|=0xA0000000;//EINT0 – P0.14 EINT1 – P0.15 

	PINSEL1|=0X00000001;//EINT2 – P0.16

	EXTMODE=0x7;// Edge-sensitive mode for EINT0–EINT2

	EXTPOLAR=0x0;// Falling-edge triggered

}


void EXT0_handler(void)__irq

{
	if(flag1)
	{
		flag1^=1;// Toggle flag
	FLAG_INDICATOR_RIGHT=1;

	EXTINT=0x01;// Clear EINT0

	VICVectAddr=0; // End of interrupt	
	}
}

void EXT1_handler(void)__irq

{
	if(flag2)
	{
		flag2^=1;
	FLAG_INDICATOR_LEFT=1;

	EXTINT=0x02;

	VICVectAddr=0;

		
	}
}

void EXT2_handler(void)__irq

{
	if(flag3)
	{
		flag3^=1;
	FLAG_HEADLIGHT=1;

	EXTINT=0x04;

	VICVectAddr=0;			

}
}

void interrupt_confg(void)

{

		VICIntSelect=0;// All as IRQ type (not FIQ)

	    VICVectAddr0=(u32)EXT0_handler;

		VICVectCntl0=14|(1<<5);// Enabling slot 0 for EINT0-14

	    VICVectAddr1=(u32)EXT1_handler;

		VICVectCntl1=15|(1<<5); // Slot 1 for EINT1-15

	    VICVectAddr2=(u32)EXT2_handler;

		VICVectCntl2=16|(1<<5);	 // Slot 2 for EINT1-16

      	VICIntEnable=(1<<14)|(1<<15)|(1<<16);

}



