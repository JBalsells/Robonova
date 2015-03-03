#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SMin  150  // << 4095, 150 Min
#define SMax  600  // >> 4095, 600 Max

uint8_t  ServoIzq = 6;
uint8_t  ServoDer = 9;
uint16_t AnchoPulso = 0;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60); // 60Hz
}

void loop() {
  for (AnchoPulso = SMin; AnchoPulso < SMax; AnchoPulso++) 
  {
    pwm.setPWM(ServoIzq, 0, AnchoPulso);
    pwm.setPWM(ServoDer, 0, SMax+SMin-AnchoPulso);
  }
  delay(400);
  
  for (AnchoPulso = SMax; AnchoPulso > SMin; AnchoPulso--)
  {
    pwm.setPWM(ServoIzq, 0, AnchoPulso);
    pwm.setPWM(ServoDer, 0, SMax+SMin-AnchoPulso);
  }
  delay(400);
}
