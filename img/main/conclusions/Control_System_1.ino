#include "Servo.h"
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11 
#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   pinMode(ENABLE,OUTPUT);
   pinMode(DIRA,OUTPUT);
   pinMode(DIRB,OUTPUT);
   Serial.begin(9600);//Initialization of Serial Port
}

void loop() {
   a=sr04.Distance();
   if(a < 10){
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRA,HIGH);
    delay(1205);
    digitalWrite(DIRA,LOW);
    digitalWrite(ENABLE,LOW);
    delay(5000);
    }
   Serial.print(a);
   Serial.println("cm"); 
   delay(250);
   
}
   //testMotor();

void testMotor(){
  
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRA,HIGH);
    delay(1300);
    digitalWrite(DIRA,LOW);
    digitalWrite(ENABLE,LOW);
    delay(400);
    }
