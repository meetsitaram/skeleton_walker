#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>

#include "hexapod.h"
#include "core_servo_utils.h"

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

bool taskAborted = false;
int taskAbortCode = -1;

void setupPwm() {
  pwm.begin();
  pwm2.begin();
  
  pwm.setPWMFreq(FREQ_MG996R);  
  pwm2.setPWMFreq(FREQ_MG996R);    
}

void setServoPosition(int servoNum, int theta) {

  if (theta < 0 || theta > 180) {
    Serial.println("invalid theta:" + theta);
    abortTask(-1);
    return;
  }

  int sheildNum = servoNum / 16;

  int servoMin = -1;
  int servoMax = -1;
  int thetaMin = -1;
  int thetaMax = -1;
  int pos60 = -1;
  int pos120 = -1;
  switch(servoNum) {
    case sn10_pin:
      servoMin = sn10_pos60;
      servoMax = sn10_pos120;
      thetaMin = s0_min;
      thetaMax = s0_max;
      break;  
    case sn20_pin:
      servoMin = sn20_pos60;
      servoMax = sn20_pos120;
      thetaMin = s0_min;
      thetaMax = s0_max;
      break;
    case sn30_pin:
      servoMin = sn30_pos60;
      servoMax = sn30_pos120;
      thetaMin = s0_min;
      thetaMax = s0_max;
      break;
    case sn40_pin:
      servoMin = sn40_pos60;
      servoMax = sn40_pos120;
      thetaMin = s0_min;
      thetaMax = s0_max;
      break;
    case sn50_pin:
      servoMin = sn50_pos60;
      servoMax = sn50_pos120;
      thetaMin = s0_min;
      thetaMax = s0_max;
      break;
    case sn60_pin:
      servoMin = sn60_pos60;
      servoMax = sn60_pos120;
      thetaMin = s0_min;
      thetaMax = s0_max;
      break;
    case sn11_pin:
      servoMin = sn11_pos60;
      servoMax = sn11_pos120;
      thetaMin = s1_min;
      thetaMax = s1_max;
      break;  
    case sn21_pin:
      servoMin = sn21_pos60;
      servoMax = sn21_pos120;
      thetaMin = s1_min;
      thetaMax = s1_max;
      break;
    case sn31_pin:
      servoMin = sn31_pos60;
      servoMax = sn31_pos120;
      thetaMin = s1_min;
      thetaMax = s1_max;
      break;
    case sn41_pin:
      servoMin = sn41_pos60;
      servoMax = sn41_pos120;
      thetaMin = s1_min;
      thetaMax = s1_max;
      break;
    case sn51_pin:
      servoMin = sn51_pos60;
      servoMax = sn51_pos120;
      thetaMin = s1_min;
      thetaMax = s1_max;
      break;
    case sn61_pin:
      servoMin = sn61_pos60;
      servoMax = sn61_pos120;
      thetaMin = s1_min;
      thetaMax = s1_max;
      break;
    case sn12_pin:
      servoMin = sn12_pos60;
      servoMax = sn12_pos120;
      thetaMin = s2_min;
      thetaMax = s2_max;
      break;  
    case sn22_pin:
      servoMin = sn22_pos60;
      servoMax = sn22_pos120;
      thetaMin = s2_min;
      thetaMax = s2_max;
      break;
    case sn32_pin:
      servoMin = sn32_pos60;
      servoMax = sn32_pos120;
      thetaMin = s2_min;
      thetaMax = s2_max;
      break;
    case sn42_pin:
      servoMin = sn42_pos60;
      servoMax = sn42_pos120;
      thetaMin = s2_min;
      thetaMax = s2_max;
      break;
    case sn52_pin:
      servoMin = sn52_pos60;
      servoMax = sn52_pos120;
      thetaMin = s2_min;
      thetaMax = s2_max;
      break;
    case sn62_pin:
      servoMin = sn62_pos60;
      servoMax = sn62_pos120;
      thetaMin = s2_min;
      thetaMax = s2_max;
      break;
    default:
      Serial.println("invalid servo:" + getServoName(servoNum) );
      abortTask(-1);
      return;       // raise exception
  }
                               
  if (servoMin < 0 || servoMax < 0) {
    Serial.println("invalid servo min/max for servo:" + getServoName(servoNum));
    abortTask(-1);
    return; // raise exception
  }

  if (theta < thetaMin || theta > thetaMax) {
    Serial.print("Theta:"); Serial.print(theta); 
    Serial.print(" not in limits:"); 
    Serial.print(" ThetaMin:"); Serial.print(thetaMin);
    Serial.print(", ThetaMax:"); Serial.print(thetaMax);
    Serial.print(" for servo:"); Serial.println(getServoName(servoNum));
    abortTask(-1);
    return; //raise exception
  }

  double pulseLength = map(theta, THETA_MIN_FOR_MAP, THETA_MAX_FOR_MAP, servoMin, servoMax);

  Serial.print("Theta:"); Serial.print(theta);
  Serial.print(", Pulse:");Serial.print(pulseLength);
  Serial.print(", servo:"); Serial.println(getServoName(servoNum));
    
  if(isTaskAborted()) {
    Serial.print("Task aborted");
    return; // do not more actions
  }

  if(servoNum/16 == 0) {
    pwm.setPWM(servoNum, 0, pulseLength);
  } else {
    pulseLength = pulseLength + SHIELD1_PULSE_OFFSET; 
    pwm2.setPWM(servoNum%16, 0, pulseLength);
  }

}

int getServoName(int servoNum) {
    switch(servoNum) {
      case sn10_pin:
        return 10;
      case sn20_pin:
        return 20;
      case sn30_pin:
        return 30;
      case sn40_pin:
        return 40;
      case sn50_pin:
        return 50;
      case sn60_pin:
        return 60;     
      case sn11_pin:
        return 11;
      case sn21_pin:
        return 21;
      case sn31_pin:
        return 31;
      case sn41_pin:
        return 41;
      case sn51_pin:
        return 51;
      case sn61_pin:
        return 61;
      case sn12_pin:
        return 12;
      case sn22_pin:
        return 22;
      case sn32_pin:
        return 32;
      case sn42_pin:
        return 42;
      case sn52_pin:
        return 52;
      case sn62_pin:
        return 62;                                                   
      default:
        Serial.print("Invalid servo num:"); Serial.println(servoNum);
        abortTask(-1);
        break;
    }
    return 0;

}

void abortTask(int code) {
  Serial.print("Task Aborted with code:"); Serial.println(code);
  taskAbortCode = code;
  taskAborted = true;

}
bool isTaskAborted() {
  if(taskAborted) {
    Serial.print("Task aborted with code:"); Serial.println(taskAbortCode);
  }
  return taskAborted;
}

void setInitialServoPositions() {

  setServoPosition(sn10_pin, initThetaN10);
  setServoPosition(sn20_pin, initThetaN20);

  setServoPosition(sn11_pin, initThetaN11);
  setServoPosition(sn21_pin, initThetaN21);

  setServoPosition(sn12_pin, initThetaN12);
  setServoPosition(sn22_pin, initThetaN22);
  
  setServoPosition(sn30_pin, initThetaN30);
  setServoPosition(sn40_pin, initThetaN40);

  setServoPosition(sn31_pin, initThetaN31);
  setServoPosition(sn41_pin, initThetaN41);

  setServoPosition(sn32_pin, initThetaN32);
  setServoPosition(sn42_pin, initThetaN42);

  setServoPosition(sn50_pin, initThetaN50);
  setServoPosition(sn60_pin, initThetaN60);

  setServoPosition(sn51_pin, initThetaN51);
  setServoPosition(sn61_pin, initThetaN61);

  setServoPosition(sn52_pin, initThetaN52);
  setServoPosition(sn62_pin, initThetaN62);
}
