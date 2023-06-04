# Stepper Async 5 (Library for Arduino)

This is a library that modifies the Arduino 'Stepper' library to drive a step motor asynchronously.

Detailed explanation (Korean) : [[Arduino] StepperAsync5 - 비동기 스탭 모터 라이브러리](https://blog.danggun.net/7268)

<br />
The existing 'Stepper' library operates synchronously, so other operations cannot be performed while the stepper motor is operating. This library corrects these disadvantages and allows other operations while the stepper motor is running.

[![설명영상](https://img.youtube.com/vi/fQSO-O-tE_c/0.jpg)](https://youtu.be/fQSO-O-tE_c?t=0s)

## Index
  - [주요 기능](#주요 기능) 
  - [시작 하기](#getting-started)
  - [테스트 해보기](#running-the-tests)
  - [문서](#문서)
  - [수정 이력](#update-history)
  - [기여 방법](#기여 방법)
  - [저자 및 기여자](#저자 및 기여자)
  - [라이선스](#라이선스)


## 주요 기능

- 'Stepper' 라이브러리와 동일한 선언 구조
- 'Stepper' 라이브러리와 동일한 사용 방법
- 메인 'loop'를 멈추지 않고 동작하여 비동기로 동작
- 여러 개의 스텝모터나 다른 동작을 동시에 할 수 있음


## 시작 하기

- [Releases](https://github.com/dang-gun/Arduino_StepperAsync5/releases) 에서 다운로드 하거나
- 'StepperAsync5.h' 및 'StepperAsync5.cpp' 파일을 생성하고 소스 코드를 복사합니다.
- (Arduino IDE 2.x 이상) 'Arduino IDE'에서 'Sketch > Include Library > Manage Libraries...'를 선택하여 'Library Manager'를 열어 'Stepper Async 5'를 설치해 줍니다.

아래 지침에 따라 설치해 주세요.

### Prerequisites

Arduino IDE 1.8.19에서 테스트 됩

### Installing

('Library Manager'로 설치하였으면 이 과정은 필요 없습니다.)

1. 'Arduino IDE'의 'libraries'폴더에 'StepperAsync5'폴더를 생성합니다.

2. 'StepperAsync5.h', 'StepperAsync5.cpp'를 넣어줍니다.

![Arduino_ButtonClickCheck_001](https://github.com/dang-gun/Arduino_ButtonClickCheck/assets/22692763/7f5401db-c170-4dd0-a4ab-208830573e62)

'Arduino IDE'를 실행하고 다음 코드를 추가합니다.


```
#include <StepperAsync5.h>
```


## 테스트 해보기

아래 코드를 스케치에 넣어 테스트하십시오.

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

## 문서

Name|Description
---|---|
ButtonClickCheck(int nButtonUpLevel)|A library for button judgment<br />@param nButtonUpLevel The judgment value when the button is not pressed. LOW or HIGH
ButtonClickCheck(uint8_t uintPin, int nButtonUpLevel)|Library for judging buttons (specifying which pins to use)<br />@param uintPin pre-assign pins.<br />@param nButtonUpLevel Judgment value when the button is not pressed. LOW or HIGH
&nbsp;|&nbsp; 
int ClickCheck()|Read the value of the stored pin number to determine the click information.<br />@return 1=Up, 2=Down, 3=First Down, 4=First Up<br /><br />1=Up : The button is not pressed  <br />2=Down: The button is pressed  <br />3=First Down: The state where the button changed from Up to Down (output only once when changed)  <br />4=First Up: The state where the button changed from Down to Up (output only once when changed)
int ClickCheck(int nDigitalRead)|Read the delivered value to determine the click information.<br />@param nDigitalRead Input digital value (passed value)<br />@return 1=Up, 2=Down, 3=First Down, 4=First Up<br /><br />1=Up : The button is not pressed  <br />2=Down: The button is pressed  <br />3=First Down: The state where the button changed from Up to Down (output only once when changed)  <br />4=First Up: The state where the button changed from Down to Up (output only once when changed)
BtnPush2Set(bool bBtnPush2Value)|Set the existing state value 'bBtnPush2' to a desired value.<br />@param bBtnPush2Value Data to store in the existing state value. on=true, off=false

## 수정 이력

#### 2023-06-04 : 
- 이름을 'StepperMulti5'에서 'StepperAsync5'로 변경함


## 기여 방법

프로젝트를 '포크(Fork)'하여 '새로운 벤치(new branch)'를 만든 후 '풀 리퀘스트(pull request)'해주세요.

## 저자 및 기여자
  - [dang-gun](https://github.com/dang-gun)

갱신되지 않는 기여자 목록은 [기여자](https://github.com/dang-gun/Arduino_StepperAsync5/contributors)에서 확인할 수 있습니다.


## 라이선스
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
