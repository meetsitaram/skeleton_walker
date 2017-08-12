#ifndef WALKER_INCLUDE
#define WALKER_INCLUDE
const double femur = 7.5; // length of shoulder (in cm)
const double tibia = 14.0; // length of arm 
const double coxa = 6.5; // shoulder distance from center
double Z_OFFSET = 4.5; // heigth of shoulder joint from ground

const int L_MIN = 10;
const int L_MAX = 20;

const int FREQ_MG996R = 50;

const int THETA_MIN_FOR_MAP = 60;
const int THETA_MAX_FOR_MAP = 120;

const int SHIELD1_PULSE_OFFSET = -25; // Unbelievable. Needed this as
                                      // same pulse has different behaviour on different shields. 
                                      // Servos caliberated using sheild 0 works different on shield1

const int SERVO_THETA_DIFFERENTIAL = 20; // before the angle hold kicks in, we have close to
                                         // +/- 20 degree error.. this is a lot.. :( 

const int sn30_pin = 4;      // 0 + 0 (shield_offset, pin_num)
const int sn30_pos60 = 236;
const int sn30_pos120 = 354;
const int sn30_theta_offset = -5;

const int sn31_pin = 5;      // 0 + 0 (shield_offset, pin_num)
const int sn31_pos60 = 195;
const int sn31_pos120 = 305;
const int sn31_theta_offset = 0;

const int sn32_pin = 6;     // 0 + 0 (shield_offset, pin_num)
const int sn32_pos60 = 204;
const int sn32_pos120 = 324;
const int sn32_theta_offset = 0;


const int sn40_pin = 8;      // 0 + 0 (shield_offset, pin_num)
const int sn40_pos60 = 196;
const int sn40_pos120 = 316;
const int sn40_theta_offset = -5;

const int sn41_pin = 9;      // 0 + 0 (shield_offset, pin_num)
const int sn41_pos60 = 189;
const int sn41_pos120 = 303;
const int sn41_theta_offset = 0;

const int sn42_pin = 10;      // 0 + 0 (shield_offset, pin_num)
const int sn42_pos60 = 198;
const int sn42_pos120 = 318;
const int sn42_theta_offset = 0;

const int sn10_pin = 16;      // 16 + 0 (shield_offset, pin_num)
const int sn10_pos60 = 256;
const int sn10_pos120 = 376;
const int sn10_theta_offset = 0;

const int sn11_pin = 17;      // 16 + 1 (shield_offset, pin_num)
const int sn11_pos60 = 162;
const int sn11_pos120 = 274;
const int sn11_theta_offset = 10;

const int sn12_pin = 18;      // 16 + 2 (shield_offset, pin_num)
const int sn12_pos60 = 200;
const int sn12_pos120 = 322;
const int sn12_theta_offset = -5;

const int sn20_pin = 20;      // 16 + 4 (shield_offset, pin_num)
const int sn20_pos60 = 168;
const int sn20_pos120 = 288;
const int sn20_theta_offset = 5;

const int sn21_pin = 21;      // 16 + 5 (shield_offset, pin_num)
const int sn21_pos60 = 275;
const int sn21_pos120 = 377;
const int sn21_theta_offset = -2;

const int sn22_pin = 22;      // 16 + 6 (shield_offset, pin_num)
const int sn22_pos60 = 220;
const int sn22_pos120 = 342;
const int sn22_theta_offset = 5;

const int sn50_pin = 24;      // 16 + 8 (shield_offset, pin_num)
const int sn50_pos60 = 218;
const int sn50_pos120 = 345;
const int sn50_theta_offset = -3;

const int sn51_pin = 25;      // 16 + 9 (shield_offset, pin_num)
const int sn51_pos60 = 209;
const int sn51_pos120 = 314;
const int sn51_theta_offset = 0;

const int sn52_pin = 26;      // 16 + 10 (shield_offset, pin_num)
const int sn52_pos60 = 214;
const int sn52_pos120 = 334;
const int sn52_theta_offset = 2;

const int sn60_pin = 28;      // 16 + 12 (shield_offset, pin_num)
const int sn60_pos60 = 265;
const int sn60_pos120 = 389;
const int sn60_theta_offset = 0;


const int sn61_pin = 29;      // 16 + 13 (shield_offset, pin_num)
const int sn61_pos60 = 163;
const int sn61_pos120 = 267;
const int sn61_theta_offset = 10;

const int sn62_pin = 30;      // 16 + 14 (shield_offset, pin_num)
const int sn62_pos60 = 234;
const int sn62_pos120 = 333;
const int sn62_theta_offset = 0;

const int s0_min = 60;
const int s0_max = 120;
const int s1_min = 15;
const int s1_max = 120;
const int s2_min = 45;
const int s2_max = 135;

const int initThetaN10 = 90;
const int initThetaN20 = 90;
const int initThetaN30 = 90;
const int initThetaN40 = 90;
const int initThetaN50 = 90;
const int initThetaN60 = 90;

const int initThetaN11 = 30;
const int initThetaN21 = 30;
const int initThetaN31 = 30;
const int initThetaN41 = 30;
const int initThetaN51 = 30;
const int initThetaN61 = 30;

const int initThetaN12 = 90;
const int initThetaN22 = 90;
const int initThetaN32 = 90;
const int initThetaN42 = 90;
const int initThetaN52 = 90;
const int initThetaN62 = 90;

// // Depending on your servo make, the pulse width min and max may vary, you 
// // want these to be as small/large as possible without hitting the hard stop
// // for max range. You'll have to tweak them as necessary to match the servos you
// // have!
// #define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

#endif