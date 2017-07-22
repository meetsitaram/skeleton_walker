#include "walking_style1.h"

void WalkingStyle1::startWalking() {
  //nothing to be done at beginning of walk
}


void WalkingStyle1::continueWalking(int speed) {
  int delayTime = 200;
  delayTime = delayTime/speed;

  int L = L_MAX;
  Serial.println("set down legs");
  setDownLegServoPositions(L);
  delay(delayTime/5);

  Serial.println("move legs");
  for(; L>L_MIN; L=L-0.2) {
    moveLegServoPositions(L);
    delay(delayTime);
  }
  delay(delayTime/5);

  Serial.println("lift up legs");
  liftUpLegServoPositions(L); 
  delay(delayTime/5);
}


void WalkingStyle1::stopWalking() {
    // nothing to be done at end of walk
}

void WalkingStyle1::setDownLegServoPositions(int L) {
  int servoLift = 2.0;
  double alpha = getAlpha(L, servoLift);
  Serial.print("alpha:"); Serial.println(alpha);

  double beta = getBeta(L, servoLift);
  Serial.print("beta:"); Serial.println(beta);

  for(double theta = 180; theta > beta; theta = theta - 0.5) {   
    setServoPosition(servoN12, theta);
    setServoPosition(servoN22, theta);
  }

  for(double theta = 180; theta > alpha; theta = theta - 0.5) {   
    setServoPosition(servoN11, theta);
    setServoPosition(servoN21, theta);
  }
}

void WalkingStyle1::moveLegServoPositions(int L) {
  int servoLift = 2.0;
  double alpha = getAlpha(L, servoLift);
  Serial.print("alpha:"); Serial.println(alpha);
  setServoPosition(servoN11, alpha);
  setServoPosition(servoN21, alpha);

  double beta = getBeta(L, servoLift);
  Serial.print("beta:"); Serial.println(beta);
  setServoPosition(servoN12, beta);
  setServoPosition(servoN22, beta);
}

void WalkingStyle1::liftUpLegServoPositions(int L) {
  int servoLift = 0.0;
  double alpha = getAlpha(L, servoLift);
  Serial.print("alpha:"); Serial.println(alpha);

  double beta = getBeta(L, servoLift);
  Serial.print("beta:"); Serial.println(beta);

  for(; beta < 180; beta = beta + 0.5) {   
    setServoPosition(servoN12, beta);
    setServoPosition(servoN22, beta);
  }

  for(; alpha < 180; alpha = alpha + 0.5) {   
    setServoPosition(servoN11, alpha);
    setServoPosition(servoN21, alpha);
  }

}