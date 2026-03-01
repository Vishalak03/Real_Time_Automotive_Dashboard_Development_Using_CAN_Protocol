typedef unsigned int u32;

typedef int s32;

typedef unsigned short int u16;

typedef short int s16;

typedef unsigned char u8;

typedef char s8;


typedef struct CAN2_msg

{

 	u32 ID;

	u8 RTR;

	u8 DLC;

	u32 BYTEA;

	u32 BYTEB;

} CAN2_ST;


#define TEMPERATURE_ID 0x22

#define SPEED_ID 0x33


#define HEADLIGHT_ID 0xDF

#define HEADLIGHT_ON 0XAA

#define HEADLIGHT_OFF 0XBB


//#define INDICATOR_ID_0N 0xDF

//#define INDICATOR_ID_0FF 0xDF  

#define INDICATOR_ID 0xAF


#define INDICATOR_RIGHT_ON 0xEE

#define INDICATOR_RIGHT_OFF 0xFF




#define INDICATOR_LEFT_ON 0xCC

#define INDICATOR_LEFT_OFF 0xDD




extern u16 adc_read(u8 ch_num);

extern void adc_init(void);


extern void delay_ms(u32);

extern void delay_sec(u32);


void can2_init(void);

void EN_CAN2_INTERRUPT(void);

void interrupt_confg(void);

void ext_init(void);





