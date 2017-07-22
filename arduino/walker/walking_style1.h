#ifndef WALKING_STYLE_1_INCLUDE
#define WALKING_STYLE_1_INCLUDE

class WalkingStyle1 {

    public:
    void startWalking();
    void continueWalking(int speed);
    void stopWalking();

    void setDownLegServoPositions(int L);
    void moveLegServoPositions(int L);
    void liftUpLegServoPositions(int L);
};

#endif