//Turns LED on and off
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main(void)
{

	bool A=0,B=0,C=1,D=0;
	bool W,X,Y,Z,a,b,c,d,e,f,g;

	DDRD = 0XFC;
	DDRB =((1 << DDB0));

	//Equations
	
W= (!A&&B&&D) || (!A&&B&&C) || (A&&!B&&!C);
X= (!A&&!B&&D) || (!A&&!B&&C) || (!A&&B&&!C&&!D) || (A&&!B&&!C&&D);
Y= (!A&&!C&&!D) || (!A&&C&&D) || (A&&!B&&!C&&!D);
Z= (!A&&!D) || (A&&!B&&!C&&!D);
a= (!W&&X&&!Y&&!Z);
b= (!W&&X&&!Y&&Z) || (!W&&X&&Y&&!Z) || (W&&X&&!Y&&!Z);
c= (W&&X&&!Y&&!Z);
d= (!W&&X&&!Y&&!Z) || (!W&&X&&Y&&Z) || (W&&!X&&Y&&!Z);
e= (!W&&Y&&Z) || (!W&&X&&!Y) || (W&&!X&&!Y&&Z);
f= (!W&&Y&&Z);
g= (!W&&X&&Y&&Z) || (W&&X&&!Y&&!Z);

              PORTD |=(a <<2);
	      PORTD |=(b <<3);
              PORTD |=(c <<4);
	      PORTD |=(d <<5);
              PORTD |=(e <<6);
	      PORTD |=(f <<7);
              PORTD |=(g <<8);

	      return 0;


}	      




