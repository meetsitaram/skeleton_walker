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

#include <math.h>
#include "core_servo_utils.h"
#include "hexapod.h"

#include "walking_style.h"

WalkingStyle style;

void setup() {
  
  Serial.begin(9600);
  Serial.println("Waking up 18 servo spider hexapod!");

  setupPwm();

  setInitialServoPositions();

  // for(int t=15; t>0; t--) {
  //   Serial.print("Starting in "); Serial.print(t); Serial.println(" seconds");
  //   delay(1000);
  // }
  delay(10000);

  //style.sleepPosition();
  //style.flyPosition();

  // style.setStandUpPosition();
  // delay(2000);
  // style.standUp();
  // delay(3000);
  // // style.liftMiddleLegs();
  // // delay(6000);
  // // style.riseMiddleLegs();
  // // delay(3000);
  // // //style.liftFrontLegs();
  // // style.moveFrontRightLeg();
  // // delay(3000);
  // // style.moveFrontLeftLeg();
  // // delay(3000);
  // // // style.liftMiddleLegs();
  // // // delay(6000);
  // // // style.riseMiddleLegs();
  // // // delay(3000);
  // // //style.moveMiddleRightLeg();
  // // //delay(3000);
  // // //style.moveMiddleLeftLeg();
  // // //delay(3000);
  // // style.moveRareRightLeg();
  // // delay(3000);
  //  style.moveRareLeftLeg();
  //  delay(3000);


  yield();
}

void loop() {

  // initialCallibrate(servoN30);

  //style.flyPosition();

  // delay(2000);
  // return;

  
  //int speed = 1 ;
  //style.continueWalking(1);

}
