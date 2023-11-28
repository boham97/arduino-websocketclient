long startTurn = 10L;
long turn = 0L;
long go = 0L;
long right = 0L;
long left = 0L;
long up = 0L;
String order = "SSSSSSSRULSSSSS";
String status = "";
int l, r;
void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void unGo(){
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
void unRight(){
  digitalWrite(12, LOW);
}
void unLeft(){
  digitalWrite(13, LOW);
}
void unUp(){
  digitalWrite(4, LOW);
}


void readOrder(){
  if(turn - startTurn >= 0 && turn - startTurn < order.length()){
    char now = order[turn - startTurn];
    Serial.print(now);
    Serial.print("\n");
    switch(now){
      case 'S':
        go = turn + 1;
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        Serial.print(turn);
        Serial.println("go!");
        break;
      case 'R':
        right = turn + 1;
        digitalWrite(12, HIGH);
        break;
      case 'L':
        left = turn + 1;
        digitalWrite(13, HIGH);
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
    unRight();
  }

  if(go <= turn && left <= turn){
    unLeft();
  }
  if(up <= turn){
    unUp();
  }

}