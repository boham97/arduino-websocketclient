void setup() {


  pinMode(12, OUTPUT);             // 10번핀을 출력모드로 설정합니다.
  pinMode(13, OUTPUT);            // 11번핀을 출력모드로 설정합니다.

}

void loop() {
  analogWrite(12, 2000);                  // 9번핀에 0(0V)의 신호를 출력합니다.
  digitalWrite(13, LOW);           // 10번핀에 150(약 3V)의 신호를 출력합니다.
  delay(3000);                           // 3초간 대기
  digitalWrite(12, LOW);            // 9번핀에 150(약 3V)의 신호를 출력합니다.
  analogWrite(13, 500);              // 10번핀에 0(0V)의 신호를 출력합니다.
  delay(3000);                         // 3초간 대기

}