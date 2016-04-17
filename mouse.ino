#include <PS2Mouse.h>
#define MOUSE_DATA 5
#define MOUSE_CLOCK 6

PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);
int f = 9;
int b= 10;

int l= 8;
int r= 7;

int motorsPinEnable = 2;
char mx = 0;
char my = 0;
void setup()
{
  //Serial.begin(38400);
  mouse.initialize();
  mouse.set_resolution(02);
  
  pinMode(f, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(r, OUTPUT);
digitalWrite(f, 1);//ACTIVE LOW
    digitalWrite(b, 1);
  digitalWrite(l, 1);
  digitalWrite(r, 1);
}

void loop()
{
  int data[2];
  mouse.report(data);
  mx = data[1];
  my = data[2];
 
   if(my < 0)
   backward(my);
 else if(my > 0)
   forward(my);
  
 if(mx > 0)
   right(mx);
 else if (mx < 0)
    left(mx);
}
void forward(int del){
  // Serial.println("Begin");
    delay(20);
    digitalWrite(f, 0);
    digitalWrite(b, 1);
  digitalWrite(l, 1);
  digitalWrite(r, 1); // delay(500);
   delay(abs(del)*2);
  
  //  Serial.println("Einde");
}

void backward(int del){ delay(20);
    digitalWrite(b, 0);
   digitalWrite(l, 1);
  digitalWrite(r, 1);
   digitalWrite(f, 1);
   delay(abs(del)*2);
 // delay(500);
}

void left(int del){ delay(20);
     digitalWrite(l, 0);
   
     digitalWrite(b, 1);
  digitalWrite(r, 1);
   digitalWrite(f, 1); // delay(500);
   delay(abs(del)*2);
}

void right(int del){ delay(20);
      digitalWrite(r, 0);
   
     digitalWrite(l, 1);
  digitalWrite(b, 1);
   digitalWrite(f, 1);  //delay(500);
   delay(abs(del)*2);
}


