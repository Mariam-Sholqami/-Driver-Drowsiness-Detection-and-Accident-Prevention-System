/*
 * led.c
 *
 * Created: 5/18/2022 10:59:37 PM
 * Author : Mariam
 */ 


#define F_CPU 400000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB=0xff;      // output
  PORTB=0x0f;    // off
  DDRC &= ~((1<<PC0)|(1<<PC1));    // input
  PORTC |=(1<<PC0)|(1<<PC1);      // pull-up 
    while (1) 
    {
		 if (PINB & (1<<PC0))
		 {
			 _delay_ms(30);
			 if (PINB & (1<<PC0))
			 {
				 for (int i=0 ; i<=7 ;i++)
				 {
					 PORTB |=(1<<i);
					 _delay_ms(500);
				 	}
					 
					PORTB=0x0f;
					_delay_ms(500);
					 PORTB=0xff;
					_delay_ms(500);
					 PORTB=0x0f;
					 while((PINC & (1<<PC0))==0){}
					 
		         } 
			 }
			 else if ((PINC & (1<<PC1)) == 0)
			 {
				 _delay_ms(30);

				 if ((PINC & (1<<PC1)) == 0)
				 {
					   PORTB=0xff;
					   _delay_ms(500);
					   PORTB=0x0f;
					 _delay_ms(500);
					 while((PINC & (1<<PC1))==0){}
				 }
		      }
				else  PORTB=0x0f;
			}
			
			
			
			
			
		}

