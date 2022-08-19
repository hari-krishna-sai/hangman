#include <at89c5131.h>
#include "lcd.h"		//Header file with LCD interfacing functions
#include "serial.c"	//C file with UART interfacing functions


//Main function
void main(void)
{
	
	//Call initialization functions
	code unsigned char display_msg1[]="W.Guesses: ";char p_ascii[6]={0,0,0,0,0,'\0'};	unsigned int i=0;unsigned char d=0;unsigned int p=0;unsigned int j=0;unsigned int f=0;unsigned int first=0;
	unsigned char x[]= "abcd";
	unsigned char z[]= "____";
	lcd_init();
	uart_init();
	
	lcd_cmd(0x80);
	lcd_write_string(z);
	
	lcd_cmd(0xC0);
	lcd_write_string(display_msg1);
	int_to_string(p,p_ascii);
	lcd_write_string(p_ascii);
	while(1)
	{
		d = receive_char();
		p++;
		if(d==x[i])
		{
			z[i]=x[i];
			x[i]="_";
			if(first==0)
				{
                    p--;
				    first=1;
				}
			j++;
		}
		else
		{}
	i++;
	}
	  lcd_cmd(0x01);
	  lcd_cmd(0x80);
	  lcd_write_char(z);
	  lcd_write_string(z);
	  lcd_cmd(0xC0);
	  lcd_write_string(display_msg1);
	  sprintf(p,"%d", p);
      lcd_cmd("the position at which you want to print");
      lcd_write_string(str2);
	  int_to_string(p,p_ascii);
	  lcd_write_string(p_ascii);	
	if (p == 6)
        {
			lcd_cmd(0x01);
			lcd_cmd(0x80);
            lcd_write_string("You lost");
            
        }
        else{}
        if (j == 5) // length of your word
        {
            lcd_write_string("You won");
            
        }
	
}
