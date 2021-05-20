#define TRIG_PIN 3
#define ECHO_PIN 5
unsigned long int duration;
float cm;
void setup() {
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 Serial.begin(9600); // 시리얼 모니터 사용. 속도는 1초에 9600 개 비트 전송
}
void loop() {
 digitalWrite(TRIG_PIN, HIGH); // 거리측정을 위해 TRIG_PIN을 HIGH로 설정
 delayMicroseconds(10); // 일정 시간(10 us) 동안 HIGH 상태 유지
 digitalWrite(TRIG_PIN, LOW); // TRIG_PIN을 LOW로 설정,
 duration = pulseIn(ECHO_PIN, HIGH, 18000);// 센서의 출력(ECHO_PIN)시간 측정
 cm = 0.017 * duration; // 수식에 따라 거리로 환산, 상수항은 미리 계산
 Serial.print(duration); // 시리얼 모니터에 측정 시간 표시
 Serial.print("us, "); // 시간 단위의 글자 us 표시
 Serial.print(cm); // 환산한 거리 표시
 Serial.println("cm"); // 거리 단위 cm 표시 후 줄 바꿈(다음줄 첫 번째 칸으로
 delay(100); // 표시위치를 이동함
}
