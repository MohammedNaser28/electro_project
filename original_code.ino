// C++ code
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>
/*****************************IRSENSOR***********************/
#define ir_sensor_1 2
#define ir_sensor_2 3
#define ir_sensor_3 4
#define ir_sensor_4 5

/*********************SERVO****************/
// #define servo_1 8
// #define servo_2 9
int servo_pin_1 = 8;
int servo_pin_2 = 9;

Servo servo_1;
Servo servo_2;

/****************ULTRASONIC*****************/
#define ultra_sonic_in_1 6
#define ultra_sonic_out_1 7
#define ultra_sonic_in_2 A1
#define ultra_sonic_out_2 A2
/**********LED************/
#define led_1 10
#define led_2 11
#define led_3 12
#define led_4 13

int ENTER, EXIT;
int cars = 4;




/********LCD****/
// #define lcd_data A4
// #define lcd_clock A5


LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // pinMode(pot,INPUT);
  // pinMode(button, INPUT);
  Serial.begin(9600);  // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working");
  /*****************************IRSENSOR*****************/
  pinMode(ir_sensor_1, INPUT);
  pinMode(ir_sensor_2, INPUT);
  pinMode(ir_sensor_3, INPUT);
  pinMode(ir_sensor_4, INPUT);
  /**********************ULTRASONIC********************/
  pinMode(ultra_sonic_in_1, INPUT);
  pinMode(ultra_sonic_out_1, OUTPUT);
  pinMode(ultra_sonic_in_2, INPUT);
  pinMode(ultra_sonic_out_2, OUTPUT);

  /********************SERVO*********************/

  // pinMode(servo_1, OUTPUT);
  // pinMode(servo_2, OUTPUT);

servo_1.attach(servo_pin_1);
servo_1.write(90);
servo_2.attach(servo_pin_2);
servo_2.write(90);
  /*****************************LED*********************/
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);


  /**********************LCD*************************/
  lcd.init();  // initialize the lcd
  lcd.backlight();
    lcd.setCursor(4,0);
  lcd.print("WELCOME!");

}

void loop() {
  // digitalWrite(ir,HIGh)


  
}