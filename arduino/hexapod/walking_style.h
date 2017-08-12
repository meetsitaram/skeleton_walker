#ifndef WALKING_STYLE_INCLUDE
#define WALKING_STYLE_INCLUDE

class WalkingStyle {

    private:
    const double INIT_H = 22;
    const double INIT_V = -1;
    double h = INIT_H;  //horizontal distance from center
    double f = 0; // forward or backward distance
    int v = INIT_V; // height of center above ground

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

    void executeSequenceSS(); // stand, sit
    void executeSequenceSH(); // stand, say hai, sit

    double getAlpha(double h, double f, double v);
    double getBeta(double h, double f, double v);
    double getGamma(double h, double f);
    void setArmPosition(int leg, double h, double f, double v, bool downFirst=false);

    double getAlpha(int L, int servoLift);
    double getBeta(int L, int servoLift);
};

#endif