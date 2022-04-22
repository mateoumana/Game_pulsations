#include <Arduino.h>
#define LED_YELL 11
#define LED_GREN 9
#define LED_RED 10
#define BOTTON 8

int cont, state, band = 0;
char data_serial;
String flag = "Stop";

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREN, OUTPUT);
  pinMode(LED_YELL, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BOTTON, INPUT);
  Serial.begin(9600);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREN, LOW);
  digitalWrite(LED_YELL, LOW);
  flag = "Stop";
  cont = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
      data_serial = Serial.read();
      switch(data_serial){
        case 'r':
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_GREN, HIGH);
          digitalWrite(LED_YELL, LOW);
          flag = "ready";
          break;
        case 's':
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_GREN, LOW);
          digitalWrite(LED_YELL, HIGH);
          flag = "start";
          break;
        case 'S':
          digitalWrite(LED_RED, HIGH);
          digitalWrite(LED_GREN, LOW);
          digitalWrite(LED_YELL, LOW);
          flag = "Stop";
          cont = 0;
          break;
        default:
          digitalWrite(LED_RED, HIGH);
          digitalWrite(LED_GREN, LOW);
          digitalWrite(LED_YELL, LOW);
          flag = "Stop";
          cont = 0;
          break;
      }
  }else{
      if(flag == "ready"){
        if((digitalRead(BOTTON) == HIGH) && (band == 0)){
          band = 1;
          cont += 1;
          Serial.write(cont);
        }else if((digitalRead(BOTTON) == LOW) && (band == 1)){
          band = 0;
        }
      }
  }
}