int sensor_value;
int led_brightness;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value=analogRead(A0);
  led_brightness=map(sensor_value,0,1023,0,255);
  //0~1023
  analogWrite(9,led_brightness);
  //        pin#,0~255
  Serial.print(led_brightness);
  Serial.print(", ");
  Serial.println(sensor_value);
  
}
