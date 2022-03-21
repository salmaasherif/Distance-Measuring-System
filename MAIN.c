#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include "util/delay.h"


int main(void){
	SREG |= (1<<7);
	LCD_init();
	Ultrasonic_init();
	int dis;
	LCD_displayString("Distance =    cm");
	while(1){
		dis = Ultrasonic_readDistance();
		LCD_moveCursor(0, 11);
		if(dis<=58){
			dis+=1;
		}
		else if (dis>58){
			dis+=2;
		}
		if(dis>=100){
			LCD_intgerToString(dis);
		}
		else{
			LCD_intgerToString(dis);
			LCD_displayCharacter(' ');
		}
	}
}
