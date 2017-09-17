#include <PS2Mouse.h>
#define MOUSE_DATA 5  // assign pin 5 to mouse data
#define MOUSE_CLOCK 6 // assign pin 6 to mouse data

PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);

int f = 9; // assign pin 9 to front led
int b= 10; // assign pin 10 to back led

int l= 8;  // assign pin 8 to right led
int r= 7;  // assign pin 7 to left led

int motorsPinEnable = 2;
char mx = 0;
char my = 0;
void setup()
{
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
  delay(20);
  digitalWrite(f, 0);
  digitalWrite(b, 1);
  digitalWrite(l, 1);
  digitalWrite(r, 1); // delay(500);
  delay(abs(del)*2);
}

void backward(int del){ delay(20);
  digitalWrite(b, 0);
  digitalWrite(l, 1);
  digitalWrite(r, 1);
  digitalWrite(f, 1);
  delay(abs(del)*2);
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


