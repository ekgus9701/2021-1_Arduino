int temperature; //아두이노는 2byte
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);//13번을 출력으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
    temperature=get_temperature();
    //조건에 따른 동작
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    if(temperature<22){
      //난방 켜기, 냉방끄기
      digitalWrite(8,HIGH);
      
    }
    else if(temperature>24){
      //냉방 켜기, 난방 끄기
      digitalWrite(10,HIGH);
      
    }
    else{
      //모두 끄기
      digitalWrite(8,LOW);
      digitalWrite(10,LOW);
    }
}
