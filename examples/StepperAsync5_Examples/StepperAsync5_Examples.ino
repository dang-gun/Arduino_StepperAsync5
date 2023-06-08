#include <StepperAsync5.h>

StepperAsync5 stepper(200, 12, 11, 10, 9);
StepperAsync5 stepper2(200, 7, 6, 5, 4);

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
    int steps = Serial.parseInt();

    if(steps != 0)
    {
      stepper.setStep(steps);
      stepper2.setStep(steps);
      //stepper.setStep(200);
      //stepper2.setStep(200);
  
      Serial.print("steps : ");
      Serial.println(steps); 
    }
    
  }
  
  stepper.moveStep();
  stepper2.moveStep();

}
