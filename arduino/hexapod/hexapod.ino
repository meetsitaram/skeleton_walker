//
// Hexapod Code
//

#include <math.h>
#include "core_servo_utils.h"
#include "hexapod.h"

#include "walking_style.h"

WalkingStyle style;
bool ENABLE_DEBUG = false;

void setup() {
  
  if(ENABLE_DEBUG) {
    Serial.begin(9600);
  }
  Serial.println("Waking up 18 servo spider hexapod!");

  setupPwm();

  setInitialServoPositions();

  delay(5000);
  yield();
}

void loop() {

  // setServoPosition(sn60_pin, 60);
  // delay(5000);
  // setServoPosition(sn60_pin, 90);
  // delay(5000);
  // setServoPosition(sn60_pin, 120);
  // delay(10000);
  style.go();
  
}
