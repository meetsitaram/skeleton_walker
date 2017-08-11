#ifndef CORE_UTILS_INCLUDE
#define CORE_UTILS_INCLUDE

bool isTaskAborted(); 

void setupPwm();

int getServoName(int servoNum);

double getAlpha(int L, int servoLift);

double getBeta(int L, int servoLift) ;

void setServoPosition(int servoNum, int theta);


#endif