#include<avr/io.h>
#include<util/delay.h>

void init_lcd();
void enable();
void lcd_cmd(unsigned char c);

void lcd_data(unsigned char c);




void init_lcd()
{
 
	DDRA=0xff;							//making port A as output 

		
	_delay_ms(15);
	lcd_cmd(0x03);
	
	_delay_ms(45);
	
	lcd_cmd(0x02);							//cmd for return to home 
	_delay_ms(15);
	
	lcd_cmd(0x01);							//cmd for clear screen
	lcd_cmd(0x0f);							//cmd for cursor blinking  
	lcd_cmd(0x80);							//bring cursor to 1st row 
														//1st col
}






void enable()						//to latch the data
{
 PORTA|=(1<<2);
 _delay_ms(1);
 PORTA&=~(1<<2);				
 _delay_ms(1);
}



void lcd_cmd(unsigned char c)
{
 PORTA&=~(1<<0);
 						//for lcd to take value as command
 PORTA=(c&0xf0);
 enable();

 PORTA=((c&0x0f)<<4);
 enable();
}

void lcd_data(unsigned char c)
{

	 PORTA|=(1<<0);					//for lcd to take value assigned as data 
	 //
	PORTA = (0x01)|(c&0xf0);
	enable();

	PORTA = (0x01)|((c&0x0f)<<4);
	enable();
  
}



void lcd_string(unsigned char *data)
{
	while(*data!='\0')
	{

	lcd_data(*data);
	data++;

	}

}

void lcd_num(unsigned int num)
{

unsigned char buff[100];

sprintf(buff,"data = %x",num);
lcd_string(buff);

}



































/*



void gotoxy1(unsigned char postion)
{

if(postion<16)
lcd_cmd(0x80+postion);

else
{
lcd_string("postion 0-15");
_delay_ms(1000);
lcd_cmd(0x01);

}

}






void gotoxy2(unsigned char postion)
{

if(postion<16)
lcd_cmd(0xc0+postion);

else
{
lcd_string("postion 0-15");
_delay_ms(1000);
lcd_cmd(0x01);

}

}








void lcd_string(unsigned char *str)
{
 PORTA|=(1<<RS);
 int i=0;
 
 while(*str!='\0')
 {
 if(i<16)
   lcd_cmd(0x80+i);
 else lcd_cmd(0xc0+(i%16));
  
 
  
  lcd_char(*str);
  str++;
  i++;
 }
}


















void lcd_num(int n)
{
  int a[6],i=0;
  while(n>0)
  { 
   a[i]=n%10;
   n/=10;
   i++;
  }

  for (i=i-1;i>=0;i--)
  { 
    PORTA=(0x03)|((48+a[i])&0xf0);
 
   enable();

  PORTA=(0x03)|(((48+a[i])&0x0f)<<4);
  enable();
  }
}

*/
