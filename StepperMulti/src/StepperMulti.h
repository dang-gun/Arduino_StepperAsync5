/*
  StepperMulti.h

  이 라이브러리는 아두이노의 'Stepper.h'를 개조한 라이브러리입니다.

  모든 내용은 'Stepper.h'와 거의 동일합니다.
  (0.4버전 기준)

  http://arduino.cc/en/reference/stepper
*/

// ensure this library description is only included once
#ifndef StepperMulti_h
#define StepperMulti_h

// library interface description
class StepperMulti 
{
  public:
    // constructors:
    StepperMulti(int number_of_steps, int motor_pin_1, int motor_pin_2);
    StepperMulti(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void setStep(int number_of_steps);

	//'loop()'안에서 이 메소드를 호출해야 한다.
	void moveStep();

  private:
    void stepMotor(int this_step);
    
    int direction;        // Direction of rotation
    int speed;          // Speed in RPMs
    unsigned long step_delay;    // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int pin_count;        // whether you're driving the motor with 2 or 4 pins
    int step_number;        // which step the motor is on
    
    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
    
    long last_step_time;      // time stamp in ms of when the last step was taken

	//스텝 저장
	int steps_left;
};

#endif

