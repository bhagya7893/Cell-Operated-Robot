#include"lcd.h"
#include"motor.h"

#define Q1 (PINF&(1<<0))
#define Q2 (PINF&(1<<1))
#define Q3 (PINF&(1<<2))
#define Q4 (PINF&(1<<3))

void main()
{
DDRF=0x00;
PORTF=0xff;
motor_init();
init_lcd();
lcd_data('c');
stop();
/*
forward();
_delay_ms(2000);
left();
_delay_ms(2000);
right();
_delay_ms(2000);
backward();
_delay_ms(2000);
stop();
*/
while(1)
{
lcd_cmd(0xc0);
lcd_num(PINF);


//if(!Q1 && Q2 && !Q3 && !Q4)
if((PINF&0x0f)==0x02)
{

forward();
}
//else if(!Q1 && !Q2 && !Q3 && Q4)
if((PINF&0x0f)==0x08)
{
	backward();
}
//else if(!Q1 && !Q2 && Q3 && !Q4)
if((PINF&0x0f)==0x06)
{	
	left();
}
//else if(!Q1 && Q2 && Q3 && !Q4)
if((PINF&0x0f)==0x04)
{
	right();
}
if((PINF&0x0f)==0x00)
//else if(Q1 && !Q2 && Q3 && !Q4)
{
	stop();
}

}

}
