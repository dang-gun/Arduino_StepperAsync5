#include <StepperMulti.h>

StepperMulti stepper(200, 8, 9, 10, 11);
StepperMulti stepper2(200, 4, 5, 6, 7);
 
 
void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(30);
  stepper2.setSpeed(60);
}
 
void loop()
{
  if (Serial.available())
  {
    Serial.read();
    stepper.setStep(200);
    stepper2.setStep(200);
  }
  
  stepper.moveStep();
  stepper2.moveStep();
}
