#include <StepperAsync5.h>
 
int LED1 = A0;
 
StepperAsync5 stepper(200, 12, 11, 10, 9);
StepperAsync5 stepper2(200, 7, 6, 5, 4);
 
void setup() 
{
  Serial.begin(9600);
 
  pinMode(LED1, OUTPUT);
  
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
      digitalWrite(LED1, HIGH);
      stepper.setStep(steps);
      digitalWrite(LED1, LOW);
      stepper2.setStep(steps);
      digitalWrite(LED1, HIGH);
      //stepper.setStep(200);
      //stepper2.setStep(200);
 
      Serial.print("steps : ");
      Serial.println(steps); 
      delay(100);
      digitalWrite(LED1, LOW);
    }
 
  }
  
  stepper.moveStep();
  stepper2.moveStep();
  //Serial.print("Is Move - stepper : ");
  //Serial.print(stepper.MoveOnIs);
  //Serial.print(", stepper2 : ");
  //Serial.println(stepper2.MoveOnIs);
}
