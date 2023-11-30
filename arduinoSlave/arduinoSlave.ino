#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  String receivedData = "";
  
  while (Serial.available()) {
    char c = Serial.read();
    receivedData += c;
  }
  DynamicJsonDocument jsonDoc(256);
  deserializeJson(jsonDoc, receivedData);
  
  // JSON 데이터에서 원하는 정보 추출
  int sensor1Value = jsonDoc["sensor1"];
  int sensor2Value = jsonDoc["sensor2"];
  
  // 수신된 데이터를 시리얼 모니터에 출력
  if(sensor1Value != 0)
  Serial.print("Sensor 1: ");
  Serial.println(sensor1Value);
  Serial.print("Sensor 2: ");
  Serial.println(sensor2Value);
}