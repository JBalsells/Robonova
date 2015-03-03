#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/*
|Servo No | Valor PWM |    Grados   |VariablePWM|PCA9685| Freq=60Hz
|Servo 01 | 250 a 450 | 040º a 120º | PLPWM[00] | 15    |
|Servo 02 | 250 a 375 | 040º a 090º | PLPWM[01] | 00    |    
|Servo 03 | 150 a 600 | 000º a 180º | PLPWM[02] | 14    |
|Servo 04 | 150 a 600 | 000º a 180º | PLPWM[03] | 01    |
|Servo 05 | 150 a 600 | 000º a 180º | PLPWM[04] | 13    |
|Servo 06 | 150 a 600 | 000º a 180º | PLPWM[05] | 02    |
|Servo 07 | 150 a 600 | 000º a 180º | PLPWM[06] | 12    |
|Servo 08 | 150 a 600 | 000º a 180º | PLPWM[07] | 03    |
|Servo 09 | 300 a 600 | 060º a 180º | PLPWM[08] | 11    |
|Servo 10 | 150 a 450 | 000º a 120º | PLPWM[09] | 04    |
|Servo 11 | 150 a 600 | 000º a 180º | PLPWM[10] | 10    |
|Servo 12 | 150 a 600 | 000º a 180º | PLPWM[11] | 05    |
|Servo 13 | 150 a 600 | 000º a 180º | PLPWM[12] | 09    |
|Servo 14 | 150 a 600 | 000º a 180º | PLPWM[13] | 06    |
|Servo 15 | 150 a 600 | 000º a 180º | PLPWM[14] | 08    |
|Servo 16 | 150 a 600 | 000º a 180º | PLPWM[15] | 07    |
*/

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SMin  150  // << 4095, 150 Min
#define SMax  600  // >> 4095, 600 Max

int ServoPWM[17]={0,15,0,14,1,13,2,12,3,11,4,10,5,9,6,8,7};
int PLPWM[17]={0,350,350,350,400,500,250,330,420,350,350,550,330,480,250,420,330};

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60); // 60Hz
}

void loop() {
  for (int i=1; i<=16 ; i++)
  {
    pwm.setPWM(ServoPWM[i],0,PLPWM[i]);
  }
  while (true)
  {
    //Añadir programa personalizado
  }
}
