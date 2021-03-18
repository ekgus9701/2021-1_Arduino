kwjsdp /*
  제목:Blink
  동작:
  Turns an LED on for one second, then off for one second, repeatedly.
  설명:
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
short int led_pin=13;
short int button_pin=3;
short int button_state;

//식별자 32글자까지
//영문대/소문자,숫자,_ 가능
//첫글자는 숫자안됨
//영문대/소문자,_로 시작 가능
//_로 시작 안하는게 좋음
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led_pin, OUTPUT); //13번을 아웃풋으로 설정
  //pinMode(button_pin,INPUT); //손으로 건드리면 켜지고 꺼짐
  pinMode(button_pin,INPUT_PULLUP); //3번에 신호 없으면 항상 high
  //INPUT_PULLUP은 연결된 핀에 신호가 없을 때 항상 HIGH가 되도록 강제함. 
  //-->버튼 눌러야만 꺼짐
  
  //브레드보드 이용할때 버튼 넣고 대각선으로 흰색 전선 연결해서 
  //한 줄은 3번 한줄은 GND에 연결
  
  //gnd가 연결이 안됐으면 들어오는 값의 신호가 LOW인지 HIGH인지
  //구분이 안됨 -> 그래서 LOW라고 알려주려고 gnd에 연결 
  //--> 버튼누르면 gnd랑 3이랑 연결되니까 3이 low가 됨
}

// the loop function runs over and over again forever
void loop() {
  button_state=digitalRead(button_pin);//button_pin 상태를 읽어서 button_state에 저장
  digitalWrite(led_pin,button_state); // 13번에 button_state를 통해 high인지 low인지 알려줌
}
