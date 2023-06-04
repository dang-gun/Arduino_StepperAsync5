:repository-owner: dang-gun
:repository-name: Arduino_StepperAsync5

# Button Click Check



= {repository-name} Library for Arduino =

image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-arduino.yml/badge.svg["Check Arduino status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-arduino.yml"]
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/compile-examples.yml/badge.svg["Compile Examples status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/compile-examples.yml"]
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/spell-check.yml/badge.svg["Spell Check status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/spell-check.yml"]

This is a library that modifies the Arduino 'Stepper' library to drive a step motor asynchronously. [Korean]아두이노 'Stepper'라이브러리를 개조하여 비동기로 스텝모터를 구동할 수 있게 해주는 라이브러리입니다.

Detailed explanation (Korean) : [[Arduino] 버튼 처리를 위한 라이브러리 - ButtonClickCheck](https://blog.danggun.net/7268)

<br />
Differentiate the output when the state does not change and when the state changes.  
Using this state, you can easily program it to act only once when the button's state changes.

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

- Save the last state of the button
- Detect state change of button


## Getting Started

- Download the file from [Releases](https://github.com/dang-gun/Arduino_ButtonClickCheck/releases)  or
- Create 'ButtonClickCheck.h' and 'ButtonClickCheck.cpp' and copy the source.

Follow the instructions below to install.

### Prerequisites

Tested on Arduino 1.8.19

### Installing

Create 'ButtonClickCheck' folder in 'libraries' folder of Arduino software

Insert 'ButtonClickCheck.h', 'ButtonClickCheck.cpp'.

![Arduino_ButtonClickCheck_001](https://github.com/dang-gun/Arduino_ButtonClickCheck/assets/22692763/7f5401db-c170-4dd0-a4ab-208830573e62)

Launch the Arduino software and add the following code.


```
#include <ButtonClickCheck.h>
```


## Running the tests

Put the code below in your sketch to test it.

```
#include <ButtonClickCheck.h>

#define Button01 2
#define Button02 4

//테스트 1
ButtonClickCheck BCC_1(HIGH);
//테스트 2
ButtonClickCheck BCC_2(LOW);

void setup() 
{
  Serial.begin(9600);
  
  pinMode(Button01, INPUT);
  pinMode(Button02, INPUT);
}

void loop() 
{
  
  //컴퓨터에 신호를 준다.
  int nBtnState01 = BCC_1.ClickCheck(digitalRead(Button01));
  int nBtnState02 = BCC_2.ClickCheck(digitalRead(Button02));
  
  Serial.print(nBtnState01);
  Serial.print(" : ");
  Serial.println(nBtnState02);
  
  delay(500);
}
```

![ButtonClickCheck_001_001](https://github.com/dang-gun/Arduino_ButtonClickCheck/assets/22692763/7b9c1dce-d523-4f1e-81da-683c7d5de399)  

![ButtonClickCheck_001_003](https://github.com/dang-gun/Arduino_ButtonClickCheck/assets/22692763/6ed0a0a9-4a79-429b-91c5-dd5e76fbfb1b)

## Document

Name|Description
---|---|
ButtonClickCheck(int nButtonUpLevel)|A library for button judgment<br />@param nButtonUpLevel The judgment value when the button is not pressed. LOW or HIGH
ButtonClickCheck(uint8_t uintPin, int nButtonUpLevel)|Library for judging buttons (specifying which pins to use)<br />@param uintPin pre-assign pins.<br />@param nButtonUpLevel Judgment value when the button is not pressed. LOW or HIGH
&nbsp;|&nbsp; 
int ClickCheck()|Read the value of the stored pin number to determine the click information.<br />@return 1=Up, 2=Down, 3=First Down, 4=First Up<br /><br />1=Up : The button is not pressed  <br />2=Down: The button is pressed  <br />3=First Down: The state where the button changed from Up to Down (output only once when changed)  <br />4=First Up: The state where the button changed from Down to Up (output only once when changed)
int ClickCheck(int nDigitalRead)|Read the delivered value to determine the click information.<br />@param nDigitalRead Input digital value (passed value)<br />@return 1=Up, 2=Down, 3=First Down, 4=First Up<br /><br />1=Up : The button is not pressed  <br />2=Down: The button is pressed  <br />3=First Down: The state where the button changed from Up to Down (output only once when changed)  <br />4=First Up: The state where the button changed from Down to Up (output only once when changed)
BtnPush2Set(bool bBtnPush2Value)|Set the existing state value 'bBtnPush2' to a desired value.<br />@param bBtnPush2Value Data to store in the existing state value. on=true, off=false

## Update history

#### 2023-05-17 : 
- Added 'BtnPush2Set' function
- storage separation

#### 2023-05-15 : 
- tidy up comments

#### 2023-05-11 : 
- Added '4=First Up' function

#### 2019-07-28 : 
- development completed

## Contributing

'Fork' the project to create a 'new branch' and then 'pull request'.

## Authors
  - [dang-gun](https://github.com/dang-gun)

A list of non-updating contributors can be found at [contributors](https://github.com/dang-gun/ArduinoSample/contributors).


## License
[MIT](https://github.com/dang-gun/Arduino_ButtonClickCheck/blob/main/LICENSE)
