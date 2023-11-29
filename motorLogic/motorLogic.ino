long startTurn = 3L;
long turn = 0L;
long go = 0L;
long right = 0L;
long left = 0L;
long up = 0L;
String order = "SRULSRUL";
String status = "";
int l, r;
void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT);        //12, 13 오른쪽 d6,d7
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);        //14, 15 왼쪽 d5,d10
  pinMode(15, OUTPUT);
  pinMode(4, OUTPUT);         //서브모터 제어용
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(4, LOW);
}

void goStraight(){
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}

void goRight(){
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}

void goLeft(){
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}

void stop(){
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}



void readOrder(){
  if(turn - startTurn >= 0 && turn - startTurn < order.length()){
    char now = order[turn - startTurn];
    Serial.print(now);
    Serial.print("\n");
    switch(now){
      case 'S':
        go = turn + 1;
        goStraight();
        break;
      case 'R':
        right = turn + 1;
        goRight();
        break;
      case 'L':
        left = turn + 1;
        goLeft();
        break;
      case 'U':
        up = turn + 1;
        digitalWrite(4, HIGH);
        break;
      default:
        Serial.print("readOrder Fail!");
    }
  }
}

void loop(){
  unsigned long millisTime = millis();
  if(turn < (millisTime/2000)){
    turn = (millisTime/2000);
    Serial.println(turn);

    readOrder();
  }

  if(go <= turn && right <= turn){
    digitalWrite(12, LOW);
  }

  if(left <= turn){
    digitalWrite(13, LOW);
  }
    if(go <= turn && left <= turn){
    digitalWrite(14, LOW);
  }
  if(right <= turn){
    digitalWrite(15, LOW);
  }
  if(up <= turn){
    digitalWrite(4, LOW);
  }

}