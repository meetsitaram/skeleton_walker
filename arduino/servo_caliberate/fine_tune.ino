/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);



void setup() {
  
  
  Serial.begin(9600);
  Serial.println("16 channel, dual shield, Servo test!");

  pwm.begin();
  pwm.setPWMFreq(50); 
  

  yield();
}


void loop() {

  int s10_300 = 82;
  int s10_360 = 112;
  int s11_300 = 105;
  int s11_360 = 135;
  int s12_300 = 62;
  int s12_360 = 92;

  int s20_240 = 95;
  int s20_360 = 152;
  int s21_300 = 75;
  int s21_360 = 110;
  int s22_300 = 53;
  int s22_360 = 82;

  int s30_300 = 90;
  int s30_360 = 120;
  int s31_300 = 111;
  int s31_360 = 140;
  int s32_300 = 108;
  int s32_360 = 138;

  int s40_300 = 115;
  int s40_360 = 145;
  int s41_300 = 110;
  int s41_360 = 135;
  int s42_300 = 111;
  int s42_360 = 141;

  int s50_300 = 99;
  int s50_360 = 128;
  int s51_300 = 105;
  int s51_360 = 137;
  int s52_300 = 103;
  int s52_360 = 133;

  int s60_300 = 100;
  int s60_360 = 125;
  int s61_300 = 80;
  int s61_360 = 105;
  int s62_300 = 100;
  int s62_360 = 136;  


//   int pos1 = 300;
//   int pos2 = 360;

  // pwm.setPWM(0, 0, pos1);
  // delay(10000);
  // pwm.setPWM(0, 0, pos2);
  // delay(10000);

//   int theta1 = s61_300;
//   int theta2 = s61_360;
//   int pos1 = 300;
//   int pos2 = 360;

  int theta1 = 60;
  int theta2 = 120;
  int pos1 = 163;
  int pos2 = 267;

  int pulse = 0;

  pulse = map(60, theta1, theta2, pos1, pos2);
  pwm.setPWM(0, 0, pulse);
  Serial.print("pulse for 60:"); Serial.println(pulse);
  delay(5000);

  pulse = map(90, theta1, theta2, pos1, pos2);
  pwm.setPWM(0, 0, pulse);
  Serial.print("pulse for 90:"); Serial.println(pulse);
  delay(5000);

  pulse = map(120, theta1, theta2, pos1, pos2);
  pwm.setPWM(0, 0, pulse);
  Serial.print("pulse for 120:"); Serial.println(pulse);
  delay(5000);
}
