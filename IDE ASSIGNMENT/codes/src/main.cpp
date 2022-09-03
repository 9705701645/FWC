#include <Arduino.h>
int Z,Y,X,W;
int A=0 ,B=1, C=1, D=0;
int a,b,c,d,e,f,g;

//Code released under GNU GPL.  Free to use for anything.
void disp_BTOXS3(int a, int b, int c, int d,int e,int f,int g)
{
  digitalWrite(2, a); //LSB
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g);

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
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
disp_BTOXS3(a,b,c,d,e,f,g);
}
