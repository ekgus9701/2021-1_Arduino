//1971055 한다현 finalproject

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>
Servo myservo;
#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define TRIG_PIN 4
#define ECHO_PIN 7

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11

unsigned long int duration;
float cm;
float temperature;
float humidity;

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
int pos = 0;
int count = 0;
int count2 = 0;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  myservo.attach(9);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {
  // Delay between measurements.
  delay(1000);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  temperature=event.temperature;
  Serial.print(temperature); //온도 출력
  Serial.print(F("°C  "));
  dht.humidity().getEvent(&event);
  humidity=event.relative_humidity;
  Serial.print(humidity); //습도 출력
  Serial.print(F("%  "));
  digitalWrite(TRIG_PIN, HIGH); // 거리측정을 위해 TRIG_PIN을 HIGH로 설정
  delayMicroseconds(10); // 일정 시간(10 us) 동안 HIGH 상태 유지
  digitalWrite(TRIG_PIN, LOW); // TRIG_PIN을 LOW로 설정,
  duration = pulseIn(ECHO_PIN, HIGH, 18000);// 센서의 출력(ECHO_PIN)시간 측정
  cm = 0.017 * duration; // 수식에 따라 거리로 환산, 상수항은 미리 계산
  Serial.print(cm); // 환산한 거리 표시
  Serial.println("cm"); // 거리 단위 cm 표시 후 줄 바꿈(다음줄 첫 번째 칸으로
  delay(100); // 표시위치를 이동함

 
  if (humidity > 50) { //습도가 50% 이상이라면
    tone(8, 330); //습도가 너무 높아 제습기 실행-> 우웅 소리 들림
    digitalWrite(3, HIGH); //노란 led 불 들어옴
  }
  else {
    noTone(8); //소리 꺼짐
    digitalWrite(3, LOW); //노란 led 불꺼짐
  }



  if (cm < 5) { //들짐승이 왔다면
    tone(8, 523); delay(500); //사람에게 알리는 소리
    tone(8, 440); delay(500);
    digitalWrite(12, HIGH); delay(100); //빨간 led 켜졌다 꺼졌다함
    digitalWrite(12, LOW); delay(100);

  }
  else {
    noTone(10); //소리 꺼짐
    digitalWrite(12, LOW); //빨간 led 꺼짐
  }

  if (temperature >= 35) { //온도가 35도 이상이면
    if (count2 == 0) { //켜지는 알림 한번만 들리게하기위해
      tone(8, 262); delay(500); //알림 소리 들림
      tone(8, 294); delay(500);
      tone(8, 330); delay(500);
      noTone(8);
    }
    count2++;
    digitalWrite(6, HIGH); //파란 led 켜짐
    for (pos = 0; pos <= 180; pos += 1) { //모터 돌아감
      // in steps of 1 degree
      myservo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);

    }
  }
  else { //온도가 35도 이하면
    if (count == 0) { //꺼지는 알람 한번만 들리게하기위해
      tone(8, 330); delay(500);
      tone(8, 294); delay(500);
      tone(8, 262); delay(500);
      noTone(8);
    }
    count++;
    digitalWrite(6, LOW); //파란 led꺼짐
  }





}
