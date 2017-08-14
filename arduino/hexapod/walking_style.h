#ifndef WALKING_STYLE_INCLUDE
#define WALKING_STYLE_INCLUDE

class WalkingStyle {

    private:
    const double INIT_H = 22;
    const double INIT_V = -1;
    double h = INIT_H;  //horizontal distance from center
    int v = INIT_V; // height of center above ground
    double fSet1 = 0; // forward or backward distance for leg set 1
    double fSet2 = 0; // forward or backward distance for leg set 2

    public:
    WalkingStyle();

    const int maxNumServos = 32;
    bool servosInAction[32];
    int currServoPositions[32];
    
    void go();
    void stand();
    void sit();
    
    void raiseLeg(int lg);
    void lowerLegSeq1(int lg);
    void lowerLegSeq2(int lg);
    void moveLegForward(int lg, double df);
    void moveLegBack(int lg, double df);

    bool isLeftLeg(int lg);
    double getLegF(int lg);
    void setLegF(int lg, double f);

    void moveForwardLegSet(int setNum);
    void moveBackwardLegSet(int setNum);
    void lowerLegSet(int setNum);
    void raiseLegSet(int setNum);


    void executeSequenceSS(); // stand, sit
    void executeSequenceSH(); // stand, say hai, sit
    void executeSequenceWalk(); // stand, walk, sit

    double getAlpha(double h, double f, double v);
    double getBeta(double h, double f, double v);
    double getGamma(double h, double f);
    void setArmPosition(int leg, double h, double f, double v, bool downFirst=false);

    double getAlpha(int L, int servoLift);
    double getBeta(int L, int servoLift);
};

#endif