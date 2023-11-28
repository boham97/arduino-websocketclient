void setup() {


  pinMode(12, OUTPUT);             // right wheel1
  pinMode(13, OUTPUT);            // rightwheel2
  pinMode(5, OUTPUT);             // leftwheel1
  pinMode(4, OUTPUT);             //leftwheel2
}
void goHard(){
  analogWrite(12, 2000);
  digitalWrite(13, LOW);
  analogWrite(4, 2000);
  digitalWrite(5, LOW);
}

void goNormal(){
  analogWrite(12, 500);
  digitalWrite(13, LOW);
  analogWrite(4, 500);
  digitalWrite(5, LOW);
}
void loop() {
  goHard();           // 10번핀에 150(약 3V)의 신호를 출력합니다.
  delay(3000);                           // 3초간 대기
  goNormal();
  delay(3000);                         // 3초간 대기

}
 LSSSS