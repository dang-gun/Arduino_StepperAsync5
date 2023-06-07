# Stepper Async 5 (Library for Arduino)

아두이노 'Stepper' 라이브러리를 수정하여 스텝 모터를 비동기식으로 구동할 수 있게 해주는 라이브러입니다.

상세한 설명 (Korean) : [[Arduino] StepperAsync5 - 비동기 스탭 모터 라이브러리](https://blog.danggun.net/7268)

<br />
기존의 'Stepper' 라이브러리는 동기식으로 동작하기 때문에 스테퍼 모터가 동작하는 동안에는 다른 동작을 할 수 없습니다.<br/>
이 라이브러리는 이러한 단점을 수정하고 스테퍼 모터가 실행되는 동안 다른 작업을 할 수 있게 해줍니다.


## Index
  - [주요 기능](#overview) 
  - [시작 하기](#getting-started)
  - [테스트 해보기](#running-the-tests)
  - [문서](#문서)
  - [수정 이력](#update-history)
  - [기여 방법](#contributing)
  - [저자 및 기여자](#authors)
  - [라이선스](#license)


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

![StepperAsync5_001](https://github.com/dang-gun/Arduino_StepperAsync5/assets/22692763/6cd33ce6-0697-4799-ab8d-5741e268e29a)

'Arduino IDE'를 실행하고 다음 코드를 추가하여 'StepperAsync5'를 사용할 수 있습니다.


```
#include <StepperAsync5.h>
```


## 테스트 해보기

아래 코드를 스케치에 넣어 테스트하십시오.

```
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
```

![StepperAsync5_002](https://github.com/dang-gun/Arduino_StepperAsync5/assets/22692763/ffb3d3ce-9080-45de-96bb-59cd4db5b231)



## 문서

Name|Description
---|---|
StepperAsync5(int number_of_steps, int motor_pin_1, int motor_pin_2)|2선식 스텝모터에 사용하는 생성자<br />@param number_of_steps 모터가 1회전 하는데 필요한 스탭 숫자<br />@param motor_pin_1 모터에 연결된 핀 번호1<br />@param motor_pin_2 모터에 연결된 핀 번호2
StepperAsync5(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)|4선, 6선식 스텝모터에 사용하는 생성자<br />@param number_of_steps 모터가 1회전 하는데 필요한 스탭 숫자<br />@param motor_pin_1 모터에 연결된 핀 번호1<br />@param motor_pin_2 모터에 연결된 핀 번호2<br />@param motor_pin_3 모터에 연결된 핀 번호3<br />@param motor_pin_4 모터에 연결된 핀 번호4
StepperAsync5(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4, int motor_pin_5)|8선식 스텝모터에 사용하는 생성자<br />@param number_of_steps 모터가 1회전 하는데 필요한 스탭 숫자<br />@param motor_pin_1 모터에 연결된 핀 번호1<br />@param motor_pin_2 모터에 연결된 핀 번호2<br />@param motor_pin_3 모터에 연결된 핀 번호3<br />@param motor_pin_4 모터에 연결된 핀 번호4<br />@param motor_pin_5 모터에 연결된 핀 번호5
&nbsp;|&nbsp; 
void setSpeed(long whatSpeed)|모터의 분당 회전수(RPM)을 설정함.<br />@param whatSpeed 모터가 분당 회전해야 하는 속도
void setStep(int number_of_steps)|모터를 설정된 단계 수(steps) 만큼 돌리라고 명령한다.<br />'Stepper'라이브러리의 'stop()'에 대응하는 함수지만 직접 회전시키진 안습니다.<br />'moveStep()'가 호출되어야 회전합니다.<br />@param number_of_steps 모터를 돌리는 단계 수. 정반향으로 돌리려면 양수, 반대방향으로 돌리려면 음수를 넣는다.
void moveStep()|설정된 단계 수(steps)만큼 회전시킨다.<br />반듯이 'loop()'안에서 이 메소드를 호출해야 한다.
void version()|이 라이브러리의 기준 버전을 출력한다.<br />기준버전에 따라 라이브러리를 분리하고 있어서 이 라이브러리는 '5'고정입니다.
MoveOnIs|지금 모터가 진행 중인지 여부<br />동작 중=true, 동작 중이 아니면=false

## 수정 이력

#### 2023-06-04 : 
- 이름을 '[StepperMulti5](https://blog.danggun.net/7645)'에서 'StepperAsync5'로 변경함


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
