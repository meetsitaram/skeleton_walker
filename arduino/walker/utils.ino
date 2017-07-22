#include "walker.h"
#include "utils.h"
#include <math.h>

//const int degreeStepSize = 2.25;

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

void setupPwm() {
  pwm.begin();
  pwm2.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm2.setPWMFreq(60);    
}

void initialCallibrate(int servoNum) {


  Serial.print("Calliberating servo:"); Serial.println(servoNum);
  for(int v=160; v>=80; v=v-5) {
      Serial.print("v:"); Serial.println(v);
      pwm2.setPWM(servoNum%16, 0, v); 
      delay(5000);
  }
  // for(int v=460; v<=600; v=v+5) {
  //     Serial.print("v:"); Serial.println(v);
  //     pwm2.setPWM(servoNum%16, 0, v); 
  //     delay(5000);
  // }

   delay(2000);     
}

double getAlpha(int L, int servoLift) {
  double z = Z_OFFSET + servoLift;
  double alpha1 = acos(z/L);
  double alpha2 = acos( (pow(femur,2) + pow(L,2) - pow(tibia,2)) / (2.0*femur*L) );

  double alpha = 180*(alpha1 + alpha2) / M_PI;
  if (alpha == NAN)  {
    return 0;
  }
  return alpha;
}

double getBeta(int L, int servoLift) {
  if (L > femur + tibia) {
    return 0;
  }
  double beta = (180.0/M_PI)*acos( ( pow(L,2) - pow(femur,2) - pow(tibia, 2) )/(2.0*femur*tibia) );
  return beta;
}


void setServoPosition(int servoNum, int theta) {

  if (theta < 0 || theta > 180) {
    Serial.println("invalid theta:" + theta);
    return;
  }

  int servoMin = -1;
  int servoMax = -1;
  int sheildNum = servoNum / 16;

  switch(servoNum) {
    case servoN10:
      servoMin = servoN10Min;
      servoMax = servoN10Max;
      break;  
    case servoN11:
      servoMin = servoN11Min;
      servoMax = servoN11Max;
      break;  
    case servoN12:
      servoMin = servoN12Min;
      servoMax = servoN12Max;
      break;  
    case servoN20:
      servoMin = servoN20Min;
      servoMax = servoN20Max;
      break;  
    case servoN21:
      servoMin = servoN21Min;
      servoMax = servoN21Max;
      break; 
    case servoN22:
      servoMin = servoN22Min;
      servoMax = servoN22Max;
      break;   
    case servoN30:
      servoMin = servoN30Min;
      servoMax = servoN30Max;
      break;   
    case servoN31:
      servoMin = servoN31Min;
      servoMax = servoN31Max;
      break; 
    case servoN32:
      servoMin = servoN32Min;
      servoMax = servoN32Max;
      break; 
    case servoN40:
      servoMin = servoN40Min;
      servoMax = servoN40Max;
      break; 
    case servoN41:
      servoMin = servoN41Min;
      servoMax = servoN41Max;
      break; 
    case servoN42:
      servoMin = servoN42Min;
      servoMax = servoN42Max;
      break; 
    case servoN50:
      servoMin = servoN50Min;
      servoMax = servoN50Max;
      break; 
    case servoN51:
      servoMin = servoN51Min;
      servoMax = servoN51Max;
      break; 
    case servoN52:
      servoMin = servoN52Min;
      servoMax = servoN52Max;
      break; 
    case servoN60:
      servoMin = servoN60Min;
      servoMax = servoN60Max;
      break; 
    case servoN61:
      servoMin = servoN61Min;
      servoMax = servoN61Max;
      break; 
    case servoN62:
      servoMin = servoN62Min;
      servoMax = servoN62Max;
      break;                                                                        
    default:
      Serial.println("invalid servo:" + servoNum );
      return;       
  }
                               

  if (servoMin < 0 || servoMax < 0) {
    Serial.println("invalid servo:" + servoNum);
    return;
  }

  double degreeStepSize = (servoMax - servoMin ) / 180.0;
  double pulseLength = servoMin + degreeStepSize*theta;
  if(servoNum/16 == 0) {
    pwm.setPWM(servoNum, 0, pulseLength);
  } else {
    pwm2.setPWM(servoNum%16, 0, pulseLength);
  }
  
}
