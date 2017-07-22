#ifndef UTILS_INCLUDE
#define UTILS_INCLUDE

void setupPwm();

void initialCallibrate(int servoNum);

double getAlpha(int L, int servoLift);

double getBeta(int L, int servoLift) ;

void setServoPosition(int servoNum, int theta);


#endif