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

#define TRIG_IN 6

#define ECHO_IN 7

#define TRIG_OUT 8

#define ECHO_OUT 9



// Servos

#define SERVO_IN 10

#define SERVO_OUT 11



Servo servoIn, servoOut;



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



  servoIn.attach(SERVO_IN);

  servoOut.attach(SERVO_OUT);

  servoIn.write(closePos);

  servoOut.write(closePos);



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

  lcd.setCursor(0, 0);

  lcd.print("Slots: ");

  lcd.print(available);

  lcd.print("/");

  lcd.print(totalSlots);



  // Entry detection

  long entryDist = readDistance(TRIG_IN, ECHO_IN);

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

  long exitDist = readDistance(TRIG_OUT, ECHO_OUT);

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
#define TRIG_IN 6
#define ECHO_IN 7
#define TRIG_OUT 8
#define ECHO_OUT 9

// Servos
#define SERVO_IN 10
#define SERVO_OUT 11

Servo servoIn, servoOut;

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

  servoIn.attach(SERVO_IN);
  servoOut.attach(SERVO_OUT);
  servoIn.write(closePos);
  servoOut.write(closePos);

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
  lcd.setCursor(0, 0);
  lcd.print("Slots: ");
  lcd.print(available);
  lcd.print("/");
  lcd.print(totalSlots);

  // Entry detection
  long entryDist = readDistance(TRIG_IN, ECHO_IN);
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
  long exitDist = readDistance(TRIG_OUT, ECHO_OUT);
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