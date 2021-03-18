void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);//13번을 출력으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  for (;;) {
    digitalWrite(13, HIGH); //LED를 켜겠다
    delay(100); //LED켜진상태로 0.1초동안 쉼(1/1000 *100(1/1000*값으로 계산))
    digitalWrite(13, LOW); //LED 끔
    delay(100); //LED꺼진상태로 0.1초동안 쉼(1/1000 *100)
  }
}
