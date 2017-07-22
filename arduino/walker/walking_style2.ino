#include "walking_style2.h"
#include "walker.h"

WalkingStyle2::WalkingStyle2() {
    for(int i=0; i<maxNumServos; ++i) {
        servosInAction[i] = false;
    }
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