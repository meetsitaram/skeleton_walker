#include "hexapod.h"
#include "walking_style.h"

WalkingStyle::WalkingStyle() {
    for(int i=0; i<maxNumServos; ++i) {
        servosInAction[i] = false;
    }
}

double WalkingStyle::getAlpha(double h, double f, double v) {
  double L1 = sqrt(pow(h,2)+ pow(f,2));
  double z = Z_OFFSET + v;
  double L = sqrt(pow(z,2) + pow(L1-coxa,2)); // L is radial dist from servo 2
                                                              // L1 is horizontal distance from center
  double alpha1 = acos(z/L);
  double alpha2 = acos( (pow(femur,2) + pow(L,2) - pow(tibia,2)) / (2.0*femur*L) );

  double alpha = 180*(alpha1 + alpha2) / M_PI;
  if (alpha == NAN)  {
    Serial.print("NAN alpha:"); Serial.print(alpha);
    Serial.print(" for h:"); Serial.print(h);
    Serial.print(", f:"); Serial.print(f);
    Serial.print(", v:"); Serial.println(v);
    abortTask(-1);
    return 0;
  }
  return alpha;
}

double WalkingStyle::getBeta(double h, double f, double v) {
  double L1 = sqrt(pow(h,2)+ pow(f,2));
  double z = Z_OFFSET + v;
  double L = sqrt(pow(z,2) + pow(L1-coxa,2)); // L is radial dist from servo 2
                                                              // L1 is horizontal distance from center  
  if (L > femur + tibia) {
    Serial.print("L:"); Serial.print(L); Serial.print(" > femur + tibia");
    abortTask(-1);
    return 0;
  }
  Serial.print("in beta, l:"); Serial.println(L);
  double beta = (180.0/M_PI)*acos( ( pow(femur,2) + pow(tibia, 2) - pow(L,2) )/(2.0*femur*tibia) );
  return beta;
}

double WalkingStyle::getGamma(double h, double f) {
  double L1 = sqrt(pow(h,2)+ pow(f,2));

  double gamma = 180.0*(acos( h / L1)) / M_PI;
  Serial.print("gamma val:"); Serial.println(gamma);
  if (gamma == NAN)  {
    return 90;
  }

  if(gamma > 180 || gamma < 0) {
    return 90;
  }

  if(f < 0) {
    gamma = 0 - gamma;
  }
  return gamma;
}

void WalkingStyle::setArmPosition(int leg_num, double h, double f, double v, bool downFirst) {
  Serial.print(" in serArmPosition: h:"); Serial.print(h);
  Serial.print(", f:"); Serial.print(f);
  Serial.print(", v:"); Serial.println(v);

  int s0 = 0;
  int s1 = 0;
  int s2 = 0;
  switch(leg_num) {
    case 1:
      s0 = sn10_pin;
      s1 = sn11_pin;
      s2 = sn12_pin;
      break;
    case 2:
      s0 = sn20_pin;
      s1 = sn21_pin;
      s2 = sn22_pin;
      break;
    case 3:
      s0 = sn30_pin;
      s1 = sn31_pin;
      s2 = sn32_pin;
      break;
    case 4:
      s0 = sn40_pin;
      s1 = sn41_pin;
      s2 = sn42_pin;
      break;
    case 5:
      s0 = sn50_pin;
      s1 = sn51_pin;
      s2 = sn52_pin;
      break;
    case 6:
      s0 = sn60_pin;
      s1 = sn61_pin;
      s2 = sn62_pin;
      break;
    default:
      Serial.print("Found invalid leg:"); Serial.println(leg_num);
      abortTask(-1);
      return;
  }

  double gamma = getGamma(h, f);
  Serial.print("gamma:"); Serial.print(gamma);
  Serial.print(", 90 - gamma:"); Serial.println(90 - gamma);
  
  double alpha = getAlpha(h, f, v);
  Serial.print("180 - alpha:"); Serial.println(180 - alpha);

  double beta = getBeta(h, f, v);
  Serial.print("beta:"); Serial.println(beta);

  double finalGamma = 90 - gamma;
  double finalAlpha = 180 - alpha;

  setServoPosition(s0, finalGamma);
  if(downFirst) {
    setServoPosition(s2, beta);
    setServoPosition(s1, finalAlpha);
  } else {
    setServoPosition(s1, finalAlpha);
    setServoPosition(s2, beta);
  }
}

void WalkingStyle::stand() {
  // ---- all s0 motors will stay in 90 deg thought out this entire seq.

  // start in resting mode
  h = INIT_H;
  for(int lg=1; lg<=6; ++lg) {
    setArmPosition(lg, h, f, v); // leg_number, sideway distance, forward distance, height
  }

  Serial.println("task position at zero height");
  Serial.print("h,f,v:"); Serial.print(h); Serial.print(",");
  Serial.print(f); Serial.print(","); Serial.println(v);
  v = 0;
  for(int lg=1; lg<=6; ++lg) {
    setArmPosition(lg, h, f, v); 
  }
  delay(300);

  Serial.println("move all shoulders up a little bit");
  Serial.print("h,f,v:"); Serial.print(h); Serial.print(",");
  Serial.print(f); Serial.print(","); Serial.println(v);
  for(; v<-6; --v) {
    for(int lg=1; lg<=6; ++lg) {
      setArmPosition(lg, h, f, v); 
    }
    //delay(100);
  }
  delay(300);

  Serial.println("position each leg one bit closer to final position, one after another");
  Serial.print("h,f,v:"); Serial.print(h); Serial.print(",");
  Serial.print(f); Serial.print(","); Serial.println(v);
  h = h - 5;
  v = 0;
  for(int lg=1; lg<=6; ++lg) {
    setArmPosition(lg, h, f, v); 
    delay(100);
  }
  delay(500);

  for(; v<10; v = v + 2) {
    for(int lg=1; lg<=6; ++lg) {
      setArmPosition(lg, h, f, v); 
    }
    delay(50);
  }

  // stand up in desired final position
  Serial.println("Hello! I can stand now!");
  delay(500);

}

void WalkingStyle::sit() {
  // set to resting position
  for(; v > 0; v = v - 2) {
    for(int lg=1; lg<=6; ++lg) {
      setArmPosition(lg, h, f, v);
    }
    delay(50);
  }
  h = INIT_H;
  v = -1;
  for(int lg=1; lg<=6; ++lg) {
    setArmPosition(lg, h, f, v);
  }
  delay(500);

}

void WalkingStyle::raiseLeg(int lg) {
  Serial.print("raiseLeg:"); Serial.println(lg);

  setArmPosition(lg, h, f, 0);
}

void WalkingStyle::lowerLegSeq1(int lg) {
  Serial.print("lowerLegSeq1:"); Serial.println(lg);

  setArmPosition(lg, h, f, v/2, true);
}

void WalkingStyle::lowerLegSeq2(int lg) {
  Serial.print("lowerLegSeq1:"); Serial.println(lg);

  setArmPosition(lg, h-2, f, v, true);

}

void WalkingStyle::executeSequenceSS() {
  // stand, sit
  stand();
  delay(2000);
  sit();
  delay(2000);
}

void WalkingStyle::executeSequenceSH() {
  // stand, say hai, sit
  stand();
  delay(2000);
  
  for(int i=1; i<=3; ++i) {
    raiseLeg(3);
    raiseLeg(2);
    raiseLeg(6);
    delay(300);

    lowerLegSeq1(3);
    lowerLegSeq1(2);
    lowerLegSeq1(6);
    delay(300);

    lowerLegSeq2(3);
    lowerLegSeq2(2);
    lowerLegSeq2(6);
    delay(300);

    delay(500);

    raiseLeg(1);
    raiseLeg(4);
    raiseLeg(5);
    delay(300);

    lowerLegSeq1(1);
    lowerLegSeq1(4);
    lowerLegSeq1(5);
    delay(300);

    lowerLegSeq2(1);
    lowerLegSeq2(4);
    lowerLegSeq2(5);
    delay(300);

    delay(500);
  }
  delay(2000);
  sit();
  delay(2000);
}

void WalkingStyle::go() {
  while(true) {
    //executeSequenceSS();
    executeSequenceSH();
  }
}