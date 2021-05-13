int i;

int a=7; //FND의 a를 아두이노 7번과 연결
int b=6; //FND의 b를 아두이노 6번과 연결
int c=5; //FND의 c를 아두이노 5번과 연결
int d=11; //FND의 d를 아두이노 11번과 연결
int e=10; //FND의 e를 아두이노 10번과 연결
int f=8; //FND의 f를 아두이노 8번과 연결
int g=9; //FND의 g를 아두이노 9번과 연결
int dp=4; //FND의 dp를 아두이노 4번과 연결
void digital_1(void) //숫자1 //1은 b, c가 HIGH
{
unsigned char j; //문자형 변수 j
digitalWrite(c,HIGH); //c HIGH
digitalWrite(b,HIGH); //b HIGH
for(j=7;j<=11;j++) //a,f,g,e,d에 대해
digitalWrite(j,LOW); //’0’ 출력
digitalWrite(dp,LOW); //dp에도 ‘0’ 출력
}
void digital_2(void) //숫자2 //2는 a, b, g, e, d가 HIGH
{
unsigned char j; //문자형 변수 J
digitalWrite(b,HIGH); //b HIGH
digitalWrite(a,HIGH); //a HIGH
for(j=9;j<=11;j++) //g, e, d에 대해
digitalWrite(j,HIGH); //’1’ 출력
digitalWrite(dp,LOW); //dp에는 ‘0’ 출력
digitalWrite(c,LOW); //c는 ‘0’
digitalWrite(f,LOW); //f는 ‘0’
}

void setup() {
  // put your setup code here, to run once:
  for(i=4;i<=11;i++){ 
    //비교
    pinMode(i,OUTPUT);
    //증가
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  digital_2();
  
}
