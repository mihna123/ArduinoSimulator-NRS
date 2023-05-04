#include<arduinoPlatform.h>
#include<tasks.h>
#include<interrupts.h>
#include<stdio.h>
#include<serial.h>
#include <pwm.h>
#include<data.h>

extern serial Serial;
int a,b,c,d,e,f,g,n,i=0;
void setup()
{
    createSegmentDisplayAt(26);
    createSegmentDisplayAt(27);
    createSegmentDisplayAt(30);
    createSegmentDisplayAt(31);

}

void loop()
{
    a = i & 0b0001;
    b = i & 0b0010;
    c = i & 0b0100;
    d = i & 0b1000;
    e = i & 0b10000;
    f = i & 0b100000;
    g = i & 0b1000000;
    n = i & 0b10000000;

    i = (i+1)%256;
    digitalWrite(26,a);
    digitalWrite(27,b);
    digitalWrite(28,c);
    digitalWrite(29,d);
    digitalWrite(30,e);
    digitalWrite(31,f);
    digitalWrite(32,g);
    digitalWrite(33,n);
    delay(200);

}
