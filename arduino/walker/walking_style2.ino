#include "walking_style2.h"
#include "walker.h"

WalkingStyle2::WalkingStyle2() {
    for(int i=0; i<maxNumServos; ++i) {
        servosInAction[i] = false;
    }
}

void WalkingStyle2::setStandUpPosition() {
    setServoPosition(servoN60, 60);
    setServoPosition(servoN50, 120);
    setServoPosition(servoN20, 120);
    setServoPosition(servoN10, 60);

    setServoPosition(servoN22, 70);
    setServoPosition(servoN42, 70);
    setServoPosition(servoN62, 70);
    setServoPosition(servoN12, 110);
    setServoPosition(servoN32, 110);
    setServoPosition(servoN52, 110);
}

void WalkingStyle2::standUp() {
    setServoPosition(servoN21, 60);
    setServoPosition(servoN41, 40);
    setServoPosition(servoN61, 60);
    setServoPosition(servoN11, 120);
    setServoPosition(servoN31, 140);
    setServoPosition(servoN51, 120);
}

void WalkingStyle2::liftMiddleLegs() {
    setServoPosition(servoN30, initThetaN30);
    setServoPosition(servoN31, initThetaN31);
    setServoPosition(servoN32, initThetaN32);

    setServoPosition(servoN40, initThetaN40);
    setServoPosition(servoN41, initThetaN41);
    setServoPosition(servoN42, initThetaN42);    
}

void WalkingStyle2::riseMiddleLegs() {
    liftMiddleLegs();
    delay(1000);

    setServoPosition(servoN42, 50);
    setServoPosition(servoN32, 130);  
    delay(1000);
    setServoPosition(servoN41, 40);
    setServoPosition(servoN31, 140);      
    
}

void WalkingStyle2::liftFrontLegs() {
    setServoPosition(servoN11, initThetaN11);
    setServoPosition(servoN21, initThetaN21);

    setServoPosition(servoN12, initThetaN12);    
    setServoPosition(servoN22, initThetaN22);     

    setServoPosition(servoN10, initThetaN10);
    setServoPosition(servoN20, initThetaN20);    
}

void WalkingStyle2::moveFrontRightLeg() {
    setServoPosition(servoN11, initThetaN11);
    setServoPosition(servoN12, initThetaN12);  
    setServoPosition(servoN10, initThetaN10);

    delay(2000);

    setServoPosition(servoN10, 30);
    delay(500);
    setServoPosition(servoN12, 110);
    delay(1000);
    setServoPosition(servoN11, 120);
}

void WalkingStyle2::moveFrontLeftLeg() {
    setServoPosition(servoN21, initThetaN21);
    setServoPosition(servoN22, initThetaN22);
    setServoPosition(servoN20, initThetaN20); 

    delay(2000);

    setServoPosition(servoN20, 150);
    delay(500);
    setServoPosition(servoN22, 70);
    delay(1000);
    setServoPosition(servoN21, 60);
}

void WalkingStyle2::moveMiddleRightLeg() {

    setServoPosition(servoN31, initThetaN31);
    setServoPosition(servoN32, initThetaN32);  
    setServoPosition(servoN30, initThetaN30);

    delay(2000);

    setServoPosition(servoN30, 60);
    delay(500);
    setServoPosition(servoN32, 130);
    delay(1000);
    setServoPosition(servoN31, 120);
}

void WalkingStyle2::moveMiddleLeftLeg() {
    setServoPosition(servoN41, initThetaN41);
    setServoPosition(servoN42, initThetaN42);
    setServoPosition(servoN40, initThetaN40); 

    delay(2000);

    setServoPosition(servoN40, 120);
    delay(500);
    setServoPosition(servoN42, 50);
    delay(1000);
    setServoPosition(servoN41, 60);
}

void WalkingStyle2::moveRareRightLeg() {
    setServoPosition(servoN51, initThetaN51);
    setServoPosition(servoN52, initThetaN52);  
    setServoPosition(servoN50, initThetaN50);

    delay(2000);

    setServoPosition(servoN50, 150);
    delay(500);
    setServoPosition(servoN52, 110);
    delay(1000);
    setServoPosition(servoN51, 120);
}

void WalkingStyle2::moveRareLeftLeg() {
    setServoPosition(servoN61, initThetaN61);
    setServoPosition(servoN62, initThetaN62);
    setServoPosition(servoN60, initThetaN60); 

    delay(2000);

    setServoPosition(servoN60, 30);
    delay(500);
    setServoPosition(servoN62, 70);
    delay(1000);
    setServoPosition(servoN61, 60);
}

void WalkingStyle2::startWalking() {

}


void WalkingStyle2::continueWalking(int speed) {
  int delayTime = 100;
  delayTime = delayTime/speed;

  int strideReduce = 0;

  Serial.println("set down right leg");
  setDownRightLegServoPositions(L_MAX, servoN11, servoN12);
  delay(delayTime/5);

  //delay(3000);

  Serial.println("move right leg");
  for(double L = L_MAX - strideReduce; L>L_MIN; L=L-0.5) {
    moveRightLegServoPositions(L, servoN11, servoN12);
    //delay(delayTime);
  }
  delay(delayTime/5);
  //delay(3000);

  Serial.println("set down left leg");
  setDownLeftLegServoPositions(L_MAX - strideReduce, servoN21, servoN22);
  delay(delayTime/5);
  //delay(3000);

  Serial.println("lift up right leg");
  liftUpRightLegServoPositions(L_MIN, servoN11, servoN12); 
  delay(delayTime/5);
  //delay(3000);

  Serial.println("move left leg");
  for(double L = L_MAX - strideReduce; L>L_MIN; L=L-0.5) {
    moveLeftLegServoPositions(L, servoN21, servoN22);
    //delay(delayTime);
  }
  delay(delayTime/5);  
  //delay(3000);

  Serial.println("set down right leg");
  setDownRightLegServoPositions(L_MAX - strideReduce, servoN11, servoN12);
  delay(delayTime/5);
  //delay(3000);

  Serial.println("lift up left leg");
  liftUpLeftLegServoPositions(L_MIN, servoN21, servoN22); 
  delay(delayTime/5);
  //delay(3000);
}


void WalkingStyle2::stopWalking() {
    
}

void WalkingStyle2::setDownLeftLegServoPositions(int L, int servo1, int servo2) {
  int servoLift = 0;
  double alpha = getAlpha(L, servoLift);
  alpha = 180 - alpha;
  Serial.print("alpha:"); Serial.println(alpha);

  double beta = getBeta(L, servoLift);
  beta = 180 - beta;
  Serial.print("beta:"); Serial.println(beta);

  for(double theta = 0; theta < beta; theta = theta + 0.5) {   
    setServoPosition(servo2, theta);
  }

  for(double theta = 0; theta < alpha; theta = theta + 0.5) {   
    setServoPosition(servo1, theta);
  }
}

void WalkingStyle2::setDownRightLegServoPositions(int L, int servo1, int servo2) {
  int servoLift = 0;
  double alpha = getAlpha(L, servoLift);
  Serial.print("alpha:"); Serial.println(alpha);

  double beta = getBeta(L, servoLift);
  Serial.print("beta:"); Serial.println(beta);

  for(double theta = 180; theta > beta; theta = theta - 0.5) {   
    setServoPosition(servo2, theta);
  }

  for(double theta = 180; theta > alpha; theta = theta - 0.5) {   
    setServoPosition(servo1, theta);
  }
}

void WalkingStyle2::moveLeftLegServoPositions(int L, int servo1, int servo2) {
  int servoLift = 0;
  double alpha = getAlpha(L, servoLift);
  alpha = 180 - alpha;
  Serial.print("alpha:"); Serial.println(alpha);
  setServoPosition(servo1, alpha);

  double beta = getBeta(L, servoLift);
  beta = 180 - beta;
  Serial.print("beta:"); Serial.println(beta);
  setServoPosition(servo2, beta);
}


void WalkingStyle2::moveRightLegServoPositions(int L, int servo1, int servo2) {
  int servoLift = 0;
  double alpha = getAlpha(L, servoLift);
  Serial.print("alpha:"); Serial.println(alpha);
  setServoPosition(servo1, alpha);

  double beta = getBeta(L, servoLift);
  Serial.print("beta:"); Serial.println(beta);
  setServoPosition(servo2, beta);
}

void WalkingStyle2::liftUpLeftLegServoPositions(int L, int servo1, int servo2) {
  int servoLift = 0;
  double alphaCurr = getAlpha(L, servoLift);
  double betaCurr = getBeta(L, servoLift);

  servoLift = 0;
  double alpha = getAlpha(L, servoLift);
  alpha = 180 - alpha;
  Serial.print("alpha:"); Serial.println(alpha);

  double beta = getBeta(L, servoLift);
  beta = 180 - beta;
  Serial.print("beta:"); Serial.println(beta);

  Serial.print("alpha curr:"); Serial.println(alphaCurr);
  Serial.print("alpha:"); Serial.println(alpha);
  Serial.print("beta:"); Serial.println(beta);
  Serial.print("beta curr:"); Serial.println(betaCurr);

  //delay(3000);

  // for(; betaCurr > beta; betaCurr = betaCurr - 0.2) {   
  //   setServoPosition(servo2, betaCurr);
  //   delay(50);
  // }

  for(; beta > 0; beta = beta - 0.2) {   
    setServoPosition(servo2, beta);
    //delay(50);
  }


  // for(; alphaCurr > alpha; alphaCurr = alphaCurr - 0.2) {   
  //   setServoPosition(servo1, alphaCurr);
  //   delay(50);
  // }

  for(; alpha > 0; alpha = alpha - 0.2) {   
    setServoPosition(servo1, alpha);
    //delay(50);
  }

}
void WalkingStyle2::liftUpRightLegServoPositions(int L, int servo1, int servo2) {
  int servoLift = 0;
  double alphaCurr = getAlpha(L, servoLift);
  double betaCurr = getBeta(L, servoLift);

  servoLift = 0;
  double alpha = getAlpha(L, servoLift);
  Serial.print("alpha:"); Serial.println(alpha);

  double beta = getBeta(L, servoLift);
  Serial.print("beta:"); Serial.println(beta);

  Serial.print("alpha curr:"); Serial.println(alphaCurr);
  Serial.print("alpha:"); Serial.println(alpha);
  Serial.print("beta:"); Serial.println(beta);
  Serial.print("beta curr:"); Serial.println(betaCurr);

  //delay(3000);

  // for(; betaCurr < beta; betaCurr = betaCurr + 0.2) {   
  //   setServoPosition(servo2, betaCurr);
  //   delay(50);
  // }

  for(; beta < 180; beta = beta + 0.2) {   
    setServoPosition(servo2, beta);
    //delay(50);
  }


  // for(; alphaCurr <alpha; alphaCurr = alphaCurr + 0.2) {   
  //   setServoPosition(servo1, alphaCurr);
  //   delay(50);
  // }

  for(; alpha < 180; alpha = alpha + 0.2) {   
    setServoPosition(servo1, alpha);
    //delay(50);
  }

}