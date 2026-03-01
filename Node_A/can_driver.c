#include<lpc21xx.h>

#include"header.h"

//extern u32 RECEIVER_FLAG;

extern CAN2_ST M1;

void can2_init(void)

{

  	PINSEL1|=0X00014000;

	VPBDIV=1;

	C2MOD=0X1;

	AFMR=0X2;

	C2BTR=0X001C001D;

	C2MOD=0;

}



