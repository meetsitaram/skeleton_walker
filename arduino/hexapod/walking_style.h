#ifndef WALKING_STYLE_INCLUDE
#define WALKING_STYLE_INCLUDE

class WalkingStyle {

    public:
    WalkingStyle();

    const int maxNumServos = 32;
    bool servosInAction[32];
    int currServoPositions[32];
    
    // //int servoN0 = 0
    // int servo1Alpha;
    // int servo2Alpha;

    // void startWalking();
    // void continueWalking(int speed);
    // void stopWalking();

    // void sleepPosition();
    // void flyPosition();

    // void setStandUpPosition();
    // void standUp();
    // void liftMiddleLegs();
    // void riseMiddleLegs();
    // void liftFrontLegs();
    // void moveFrontRightLeg();
    // void moveFrontLeftLeg();

    // void moveMiddleRightLeg();
    // void moveMiddleLeftLeg();

    // void moveRareRightLeg();
    // void moveRareLeftLeg();        

    // void setDownLeftLegServoPositions(int L, int servo1, int servo2);
    // void setDownRightLegServoPositions(int L, int servo1, int servo2);
    // void moveLeftLegServoPositions(int L, int servo1, int servo2);
    // void moveRightLegServoPositions(int L, int servo1, int servo2);
    // void liftUpLeftLegServoPositions(int L, int servo1, int servo2);
    // void liftUpRightLegServoPositions(int L, int servo1, int servo2);

    double getAlpha(int L, int servoLift);
    double getBeta(int L, int servoLift);
};

#endif