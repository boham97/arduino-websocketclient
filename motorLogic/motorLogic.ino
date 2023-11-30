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
  pinMode(2, OUTPUT);        //12, 13 오른쪽 d6,d7
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);        //14, 15 왼쪽 d5,d10
  pinMode(5, OUTPUT);
  //pinMode(4, OUTPUT);         //서브모터 제어용
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  //digitalWrite(4, LOW);
}

void goStraight(){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void goRight(){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void goLeft(){
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void stop(){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
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
        //digitalWrite(4, HIGH);
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
    digitalWrite(2, LOW);
  }

  if(left <= turn){
    digitalWrite(3, LOW);
  }
    if(go <= turn && left <= turn){
    digitalWrite(4, LOW);
  }
  if(right <= turn){
    digitalWrite(5, LOW);
  }
  if(up <= turn){
    //digitalWrite(4, LOW);
  }

}