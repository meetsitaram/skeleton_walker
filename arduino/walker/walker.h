#ifndef WALKER_INCLUDE
#define WALKER_INCLUDE
const double femur = 11.0; // in cm
const double tibia = 11.0;
const double coxa = 2.0; 
double Z_OFFSET = 3.5;

const int L_MIN = 4;
const int L_MAX = 12;


const int servoN10 = 15;
const int servoN10Min = 165;
const int servoN10Max = 570;


const int servoN20 = 11;
const int servoN20Min = 125;
const int servoN20Max = 550;

const int servoN11 = 14;
const int servoN11Min = 170;
const int servoN11Max = 565;


const int servoN21 = 10;
const int servoN21Min = 140;
const int servoN21Max = 545;

const int servoN12 = 13;
const int servoN12Min = 180;
const int servoN12Max = 585;

const int servoN22 = 9;
const int servoN22Min = 150;
const int servoN22Max = 555;

const int servoN30 = 16; // 1-0
const int servoN30Min = 115;
const int servoN30Max = 520;

const int servoN31 = 17; // 1-1
const int servoN31Min = 125;
const int servoN31Max = 520;

const int servoN32 = 18;  // 1-2
const int servoN32Min = 120;
const int servoN32Max = 560;

const int servoN40 = 20; // 1-4
const int servoN40Min = 125;
const int servoN40Max = 545;

const int servoN41 = 21; // 1-5
const int servoN41Min = 115;
const int servoN41Max = 500;

const int servoN42 = 22; // 1-6
const int servoN42Min = 110;
const int servoN42Max = 510;

const int servoN50 = 24; // 1-8
const int servoN50Min = 120;
const int servoN50Max = 535;

const int servoN51 = 25; // 1-9
const int servoN51Min = 125;
const int servoN51Max = 535;

const int servoN52 = 26; // 1-10
const int servoN52Min = 125;
const int servoN52Max = 560;

const int servoN60 = 28; // 1-12
const int servoN60Min = 105;
const int servoN60Max = 500;

const int servoN61 = 29; // 1-13
const int servoN61Min = 125;
const int servoN61Max = 535;

const int servoN62 = 30; // 1-14
const int servoN62Min = 120;
const int servoN62Max = 535;

const int initThetaN10 = 90;
const int initThetaN11 = 180;
const int initThetaN12 = 0;

const int initThetaN20 = 90;
const int initThetaN21 = 0;
const int initThetaN22 = 180;

const int initThetaN30 = 90;
const int initThetaN31 = 180;
const int initThetaN32 = 0;

const int initThetaN40 = 90;
const int initThetaN41 = 0;
const int initThetaN42 = 180;

const int initThetaN50 = 90;
const int initThetaN51 = 180;
const int initThetaN52 = 0;

const int initThetaN60 = 90;
const int initThetaN61 = 0;
const int initThetaN62 = 180;

// // Depending on your servo make, the pulse width min and max may vary, you 
// // want these to be as small/large as possible without hitting the hard stop
// // for max range. You'll have to tweak them as necessary to match the servos you
// // have!
// #define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

#endif