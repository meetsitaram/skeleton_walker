// /*************************************************** 
//   This is an example for our Adafruit 16-channel PWM & Servo driver
//   Servo test - this will drive 16 servos, one after the other

//   Pick one up today in the adafruit shop!
//   ------> http://www.adafruit.com/products/815

//   These displays use I2C to communicate, 2 pins are required to  
//   interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

//   Adafruit invests time and resources providing this open source code, 
//   please support Adafruit and open-source hardware by purchasing 
//   products from Adafruit!

//   Written by Limor Fried/Ladyada for Adafruit Industries.  
//   BSD license, all text above must be included in any redistribution
//  ****************************************************/

// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>
// #include <math.h>

// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// int valueHigh = 400;
// int valueLow = 200;

// void setup() {
  
  
//   Serial.begin(9600);
//   Serial.println("16 channel, dual shield, Servo test!");

//   pwm.begin();
//   pwm.setPWMFreq(50); 
  

//   yield();
// }

// void step1() {

//   // 495
//   valueHigh = valueHigh + 5;
//   int value = valueHigh;

//   Serial.println(value);
//   pwm.setPWM(0, 0, value);
//   delay(2000);    
// }


// void step2() {

//   // 90
//   valueLow = valueLow - 5;
//   int value = valueLow;

//   Serial.println(value);
//   pwm.setPWM(0, 0, value);
//   delay(2000);    
// }

// void step3(int servoMin, int servoMax) {
//   int value = servoMin;
//   pwm.setPWM(0, 0, value);
//   delay(5000);
//   value = servoMax;
//   pwm.setPWM(0, 0, value);
//   delay(5000);  
// }

// void step4(int servoMin) {
//   for(int value = 160; value>= servoMin; value=value-5) {
//     pwm.setPWM(0,0,value);
//     Serial.println(value);
//     delay(3000);
//   }
// }

// void step5(int servoMax) {
//   for(int value = 380; value<= servoMax; value=value+5) {
//     pwm.setPWM(0,0,value);
//     Serial.println(value);
//     delay(3000);
//   }
// }

// void step6(int pos0, int pos180, int thetaOffsetMin, int thetaOffsetMax) {

//   int pulseInitial = map(thetaOffsetMin, 0, 180, pos0, pos180);
//   Serial.println("pulse Initial");
//   Serial.println(pulseInitial);
//   Serial.println("Theta Offset Min");
//   Serial.println(thetaOffsetMin);  
//   pwm.setPWM(0, 0, pulseInitial);
//   delay(5000); 

//   if (45 >= thetaOffsetMin && 45 <= thetaOffsetMax) {
//     int pulse45 = map(45, 0, 180, pos0, pos180);
//     Serial.println("pulse 45");
//     Serial.println(pulse45);
//     pwm.setPWM(0, 0, pulse45);
//     delay(5000);  
//   }

//   int pulse90 = map(90, 0, 180, pos0, pos180);
//   Serial.println("pulse 90");
//   Serial.println(pulse90);
//   pwm.setPWM(0, 0, pulse90);
//   delay(5000); 

//   if (135 >= thetaOffsetMin && 135 <= thetaOffsetMax) {
//     int pulse135 = map(135, 0, 180, pos0, pos180);
//     Serial.println("pulse 135");
//     Serial.println(pulse135);
//     pwm.setPWM(0, 0, pulse135);
//     delay(5000); 
//   }

//   int pulseFinal = map(thetaOffsetMax, 0, 180, pos0, pos180);
//   Serial.println(" pulseFinal");
//   Serial.println(pulseFinal);
//   Serial.println("thetaOffsetMax ");
//   Serial.println(thetaOffsetMax);  
//   pwm.setPWM(0, 0, pulseFinal);
//   delay(5000); 

// }
 
// //testTorqueLimit(pos0, pos180, 90); // test max torque by placing enough load on arm jat 90 degree
// void testTorqueLimit(int pos0, int pos180, int theta) {
//   int pulse = map(theta, 0, 180, pos0, pos180);
//   Serial.println("pulse");
//   Serial.println(pulse);
//   pwm.setPWM(0, 0, pulse);
//   delay(5000);   
// }

// void loop() {
//   int servoMax = 480; // value close to 500
//   int servoMin = 90;  // value close to 100
//   int pos0 = 105;
//   int pos180 = 480;
//   int thetaOffsetMin = 0;
//   int thetaOffsetMax = 180;
  

//   //// no need of these 6 steps. use the new approach below
//   //// step1();  // get servo max
//   //// step2(); // get servo min

//   //// step3(servoMin, servoMax);  // confirm servo limits

//   //// step4(servoMin); // to get accurate 0 degree position 

//   //// step5(servoMax);  // to get accurate 180 degree position 

//   //// step6(pos0, pos180, thetaOffsetMin, thetaOffsetMax); // set accuerate 45/90/135 degree position


//   int pos1 = 300;
//   int pos2 = 360;

//   // pwm.setPWM(0, 0, pos1);
//   // delay(10000);
//   // pwm.setPWM(0, 0, pos2);
//   // delay(10000);

//   int theta1 = 111;
//   int theta2 = 140;
//   pwm.setPWM(0, 0, map(60, theta1, theta2, pos1, pos2));
//   delay(3000);
//   pwm.setPWM(0, 0, map(90, theta1, theta2, pos1, pos2));
//   delay(3000);
//   pwm.setPWM(0, 0, map(120, theta1, theta2, pos1, pos2));
//   delay(3000);
//   delay(5000);
// }
