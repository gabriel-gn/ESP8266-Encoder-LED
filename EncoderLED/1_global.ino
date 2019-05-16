//Encoder
#include <Encoder.h>
Encoder myEnc(D1, D2);
double encoderOldPosition  = -999;
double encoderNewPosition;
boolean isEncoderButtonPressed = false;
double lastUpdateEncoderMillis = 0;

//Led
#define ledR D7
#define ledG D8
#define ledB D6
#define hueFactor 1023 //esse valor é a multiplicação do valor da matiz, que retorna de 0 a 1.
#define brightnessFactor 0.2; //valor de decaimento fixo (subtraído) ao apertar o botão

//Cores
double r = 0;
double g = 0;
double b = 0;
double h = 0;
double s = 1;
double v = 0.6;
