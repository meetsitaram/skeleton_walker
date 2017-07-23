#ifndef WALKING_STYLE_2_INCLUDE
#define WALKING_STYLE_2_INCLUDE

class WalkingStyle2 {

    public:
    WalkingStyle2();

    const int maxNumServos = 32;
    bool servosInAction[32];
    //int servoN0 = 0
    int servo1Alpha;
    int servo2Alpha;

    void startWalking();
    void continueWalking(int speed);
    void stopWalking();

    void setStandUpPosition();
    void standUp();
    void liftMiddleLegs();
    void riseMiddleLegs();
    void liftFrontLegs();
    void moveFrontRightLeg();
    void moveFrontLeftLeg();

    void moveMiddleRightLeg();
    void moveMiddleLeftLeg();

    void moveRareRightLeg();
    void moveRareLeftLeg();        

    void setDownLeftLegServoPositions(int L, int servo1, int servo2);
    void setDownRightLegServoPositions(int L, int servo1, int servo2);
    void moveLeftLegServoPositions(int L, int servo1, int servo2);
    void moveRightLegServoPositions(int L, int servo1, int servo2);
    void liftUpLeftLegServoPositions(int L, int servo1, int servo2);
    void liftUpRightLegServoPositions(int L, int servo1, int servo2);
};

#endif