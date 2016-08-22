#include<avr/io.h>
#include<util/delay.h>
/*
void enable()
{
DDRB=0xff;
PORTB|=(1<<4);
}
*/

void motor_init()
{
DDRB|=(1<<5)|(1<<6)|(1<<4);
DDRE|=(1<<2)|(1<<3);
PORTB|=(1<<4);
}


void forward()
{
PORTB|=(1<<6);
PORTB&=~(1<<5);
PORTE|=(1<<2);
PORTE&=~(1<<3);
}

void backward()
{
PORTB&=~(1<<6);
PORTB|=(1<<5);
PORTE&=~(1<<2);
PORTE|=(1<<3);
}

void stop()
{
PORTB|=(1<<6);
PORTB|=(1<<5);
PORTE|=(1<<2);
PORTE|=(1<<3);
}
void left()
{
PORTB&=~(1<<6);
PORTB&=~(1<<5);
PORTE|=(1<<2);
PORTE&=~(1<<3);
}

void right()
{
PORTB|=(1<<6);
PORTB&=~(1<<5);
PORTE&=~(1<<2);
PORTE&=~(1<<3);
}
