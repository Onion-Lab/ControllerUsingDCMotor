#define LEFT true
#define RIGHT false

#define Action 10
#define Move 30

int ActionDistance = 0; // 거리값을 저장할 변수
int MoveDistance = 0;

int ActionVolt = 0;
int MoveVolt = 0;


void setup() {

  Serial.begin(9600); // PC와의 시리얼 통신속도를 9600bps로 설정

  for(int i=5;i<9;i++) pinMode(i,OUTPUT);
  for(int i=5;i<9;i++) digitalWrite(i,LOW);

  motorON(true);
}

void loop() {

  // put your main code here, to run repeatedly

  ActionVolt = map(analogRead(A0), 0, 1023, 0, 5000);
  ActionDistance = (27.61 / (ActionVolt - 0.1696)) * 1000;
  if(ActionDistance > Action){
    while(MoveVolt == 30){
      MoveVolt = map(analogRead(A1), 0, 1023, 0, 5000);
      MotorControll(LEFT,50);
    }
    
    delay(3000);

    while(MoveVolt == 3){
      MoveVolt = map(analogRead(A1), 0, 1023, 0, 5000);
      MotorControll(LEFT,50);
    }
  }
  else{
    delay(500);
  }

  // Serial.print(ActionDistance);  //거리값을 시리얼모니터로 출력해줍니다.
 

  // Serial.print(" cm");
  // Serial.println(" ");
}



void MotorControll(boolean a,int mspeed){

  if(a == true){

    digitalWrite(5,LOW);

    analogWrite(6,mspeed);
  }

  else{

    digitalWrite(6,LOW);

    analogWrite(5,mspeed);

  }

}

void motorON(boolean a){

  if(a == true)  {

    digitalWrite(7,HIGH);

    digitalWrite(8,HIGH);

  }
  else  {
    digitalWrite(7,LOW);

    digitalWrite(8,LOW);

  }

}
