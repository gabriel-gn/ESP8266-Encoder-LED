//Encoder
#include <Encoder.h>
Encoder myEnc(D1, D2);
long encoderOldPosition  = -999;
long encoderNewPosition;
boolean isEncoderButtonPressed = false;
long lastUpdateEncoderMillis = 0;

//
#define ledR D6;
#define ledG D7;
#define ledB D8;
int ledHueValue = 0;
