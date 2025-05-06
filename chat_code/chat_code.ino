#include <Servo.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>



// LCD address (change to 0x27 or 0x3F based on your LCD)

LiquidCrystal_I2C lcd(0x27, 16, 2);



// IR Sensors

#define IR1 2

#define IR2 3

#define IR3 4

#define IR4 5



// Ultrasonic sensors

#define ultra_sonic_in_1 6
#define ultra_sonic_out_1 7
#define ultra_sonic_in_2 A1
#define ultra_sonic_out_2 A2


/******SERVO*********/
int servo_pin_1 = 8;
int servo_pin_2 = 9;

Servo servo_1;
Servo servo_2;
/**********************/

int slots[4];

int totalSlots = 4;



// Servo positions

int openPos = 90;

int closePos = 0;



// Function to measure distance

long readDistance(int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  long distance = duration * 0.034 / 2;

  return distance;

}



void setup() {

  lcd.init();

  lcd.backlight();



  pinMode(IR1, INPUT);

  pinMode(IR2, INPUT);

  pinMode(IR3, INPUT);

  pinMode(IR4, INPUT);



  pinMode(TRIG_IN, OUTPUT);

  pinMode(ECHO_IN, INPUT);

  pinMode(TRIG_OUT, OUTPUT);

  pinMode(ECHO_OUT, INPUT);



  servo_1.attach(servo_pin_1);

  servo_2.attach(servo_pin_2);

  servo_1.write(closePos);

  servo_2.write(closePos);



  lcd.setCursor(0, 0);

  lcd.print(" Smart Garage ");

  delay(2000);

  lcd.clear();

}



void loop() {

  // Read IR Sensors

  slots[0] = digitalRead(IR1);

  slots[1] = digitalRead(IR2);

  slots[2] = digitalRead(IR3);

  slots[3] = digitalRead(IR4);



  int occupied = 0;

  for (int i = 0; i < 4; i++) {

    if (slots[i] == LOW) occupied++; // LOW = car present

  }



  int available = totalSlots - occupied;



  // Display status on LCD

  lcd.setCursor(4, 0);

  lcd.print("Slots: ");

  lcd.print(available);

  lcd.print("/");

  lcd.print(totalSlots);



  // Entry detection
// #define ultra_sonic_in_1 6
// #define ultra_sonic_out_1 7
// #define ultra_sonic_in_2 A1
// #define ultra_sonic_out_2 A2



  long entryDist = readDistance(ultra_sonic_in_1, ultra_sonic_out_1);

  if (entryDist > 0 && entryDist < 20 && available > 0) {

    lcd.setCursor(0, 1);

    lcd.print("Car IN: Opening ");

    servoIn.write(openPos);

    delay(3000);

    servoIn.write(closePos);

    lcd.setCursor(0, 1);

    lcd.print("                "); // clear

  }



  // Exit detection

  long exitDist = readDistance(ultra_sonic_in_2, ultra_sonic_out_2);

  if (exitDist > 0 && exitDist < 20) {

    lcd.setCursor(0, 1);

    lcd.print("Car OUT: Opening");

    servoOut.write(openPos);

    delay(3000);

    servoOut.write(closePos);

    lcd.setCursor(0, 1);

    lcd.print("                "); // clear

  }



  delay(500);

}

