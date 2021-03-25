void setup() {
  // put your setup code here, to run once: //시작할때 한번만 동작
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(10,0); //밝기자리에 0 255 128등을 넣으며 비교해보기
  delay(500);
  analogWrite(10,5); 
  delay(500);
  analogWrite(10,50); 
  delay(500);
  analogWrite(10,128); 
  delay(500);
  analogWrite(10,255); 
  delay(500);
  
}
