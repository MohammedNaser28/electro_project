/*SMART PARKING SYSTEM by: Omar Wael Morsi*/
/*YouTube: Morsi Hamed  https://www.youtube.com/c/morsihamed */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servo1;
Servo servo2;


LiquidCrystal_I2C lcd(0x27,16,2);


int IN = 2 , OUT = 3 , p1 = 4 , p2 = 5 , p3 = 6;
int led1 = 10 , led2 = 11 , led3 = 12;
// int buzzer = 7;
int ENTER , EXIT;
int cars = 3;
int x = 1 , y = 1;

void setup() {

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("WELCOME!");

  servo1.attach(9);
  servo1.write(90);
  servo2.attach(8);
  servo2.write(90);

  pinMode(IN,INPUT);
  pinMode(OUT,INPUT);
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led1,OUTPUT);

}

void loop() {

lcd.setCursor(0,1);
lcd.print("Places left: "); 
lcd.setCursor(13,1);
lcd.print(cars);
ENTER = digitalRead(IN);
EXIT = digitalRead(OUT);
if(ENTER == LOW && x == 1){
  if(cars != 0){
  servo1.write(180);
  }
  if(cars == 0){
    for(int i=0;i<10;i++){
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
    delay(200);
      }
    }
  x = 0;
  cars--;
  }
else if(ENTER == HIGH && x == 0){
  delay(2000);
  servo1.write(90);
  x = 1;
  }
if(EXIT == LOW && y == 1){
  servo2.write(180);
  y = 0;
  cars++;
  }
else if(EXIT == HIGH && y == 0){
  delay(2000);
  servo2.write(90);
  y = 1;
  }
if(cars<0)
cars = 0;
digitalWrite(led1 , !digitalRead(p1));
digitalWrite(led2 , !digitalRead(p2));
digitalWrite(led3 , !digitalRead(p3));

}
/*I hope this was helpful for you please check tutorial video in my youtube channel*/
/*and if you have any question I will be happy answering it :)*/
/* https://www.youtube.com/playlist?list=PLJRh_zZSG_PT0lJAzx0eTCyPwk_obpJjt */
