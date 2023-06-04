# Stepper Async 5 (Library for Arduino)

This is a library that modifies the Arduino 'Stepper' library to drive a step motor asynchronously.

Detailed explanation (Korean) : [[Arduino] StepperAsync5 - 비동기 스탭 모터 라이브러리](https://blog.danggun.net/7268)

<br />
The existing 'Stepper' library operates synchronously, so other operations cannot be performed while the stepper motor is operating. This library corrects these disadvantages and allows other operations while the stepper motor is running.

[![설명영상](https://img.youtube.com/vi/fQSO-O-tE_c/0.jpg)](https://youtu.be/fQSO-O-tE_c?t=0s)

## Index
  - [Overview](#overview) 
  - [Getting Started](#getting-started)
  - [Running the tests](#running-the-tests)
  - [Document](#document)
  - [Update history](#update-history)
  - [Contributing](#contributing)
  - [Authors](#authors)
  - [License](#license)


## Overview

- Same declaration structure as 'Stepper' library
- Same usage as 'Stepper' library
- Operate asynchronously by operating without stopping the main 'loop'
- Multiple stepper motors or other operations can be performed simultaneously


## Getting Started

- Download the file from [Releases](https://github.com/dang-gun/Arduino_StepperAsync5/releases)  or
- Create 'StepperAsync5.h' and 'StepperAsync5.cpp' and copy the source.
- (Arduino IDE 2.x or later) Select 'Sketch > Include Library > Manage Libraries...' in 'Arduino IDE' to open 'Library Manager' and install 'Stepper Async 5'.

Follow the instructions below to install.

### Prerequisites

Tested on Arduino 1.8.19

### Installing

(This process is unnecessary if you have installed with 'Library Manager'.)

Create 'StepperAsync5' folder in 'libraries' folder of Arduino IDE

Insert 'StepperAsync5.h', 'StepperAsync5.cpp'.

![StepperAsync5_001](https://github.com/dang-gun/Arduino_StepperAsync5/assets/22692763/6cd33ce6-0697-4799-ab8d-5741e268e29a)

You can use 'StepperAsync5' by running 'Arduino IDE' and adding the following code.


```
#include <StepperAsync5.h>
```


## Running the tests

Put the code below in your sketch to test it.

```
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
```

![ButtonClickCheck_001_001](https://github.com/dang-gun/Arduino_ButtonClickCheck/assets/22692763/7b9c1dce-d523-4f1e-81da-683c7d5de399)  

![ButtonClickCheck_001_003](https://github.com/dang-gun/Arduino_ButtonClickCheck/assets/22692763/6ed0a0a9-4a79-429b-91c5-dd5e76fbfb1b)

## Document

Name|Description
---|---|
StepperAsync5(int number_of_steps, int motor_pin_1, int motor_pin_2)|Generator used for 2-wire stepper motor<br />@param number_of_steps  the number of steps in one revolution of your motor.<br />@param motor_pin_1 Pin number 1 connected to the motor<br />@param motor_pin_2 Pin number 2 connected to the motor
StepperAsync5(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)|Generator used for 4-wire and 6-wire stepper motors<br />@param number_of_steps  the number of steps in one revolution of your motor.<br />@param motor_pin_1 Pin number 1 connected to the motor<br />@param motor_pin_2 Pin number 2 connected to the motor<br />@param motor_pin_3 Pin number 3 connected to the motor<br />@param motor_pin_4 Pin number 4 connected to the motor
StepperAsync5(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4, int motor_pin_5)|Generator used for 8-wire stepper motor<br />@param number_of_steps  the number of steps in one revolution of your motor.<br />@param motor_pin_1 Pin number 1 connected to the motor<br />@param motor_pin_2 Pin number 2 connected to the motor<br />@param motor_pin_3 Pin number 3 connected to the motor<br />@param motor_pin_4 Pin number 4 connected to the motor<br />@param motor_pin_5 Pin number 5 connected to the motor
&nbsp;|&nbsp; 
void setSpeed(long whatSpeed)|This function sets the motor speed in rotations per minute (RPMs).<br />@param whatSpeed the speed at which the motor should turn in rotations per minute
void setStep(int number_of_steps)|Commands the motor to turn by a set number of steps.<br />A function that corresponds to 'stop()' in the 'Stepper' library, but does not rotate directly.<br />'moveStep()' must be called to rotate.<br />@param number_of_steps the number of steps to turn the motor. Positive integer to turn one direction, negative integer to turn the other.
void moveStep()|Rotate by the set number of steps.<br />You must call this method inside 'loop()'.
void version()|Print the baseline version of this library.<br />Libraries are separated according to the standard version, so this library is fixed to '5'.

## Update history

#### 2023-06-04 : 
- Renamed '[StepperMulti5](https://blog.danggun.net/7645)' to 'StepperAsync5'


## Contributing

'Fork' the project to create a 'new branch' and then 'pull request'.

## Authors
  - [dang-gun](https://github.com/dang-gun)

A list of non-updating contributors can be found at [contributors](https://github.com/dang-gun/Arduino_StepperAsync5/contributors).


## License
[GNU LESSER GENERAL PUBLIC LICENSE](https://github.com/dang-gun/Arduino_StepperAsync5/blob/main/LICENSE)
<br />
<br />


== 'Stepper' library ==

Copyright (c) Arduino LLC. All right reserved.<br />
Copyright (c) Sebastian Gassner. All right reserved.<br />
Copyright (c) Noah Shibley. All right reserved.<br />

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
