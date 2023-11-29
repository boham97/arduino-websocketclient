const int pinIRa = A0;
int IRvalueA = 0;


void setup()
{
  unsigned long time;
  Serial.begin(9600);
  pinMode(0, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(pinIRa,INPUT);
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);

}

void loop()
{
  unsigned long time = millis();   
  if((time/100)%2 == 0){
    Serial.print(time);
    Serial.print(", sensor1: ");
    Serial.println(IRvalueA);
    digitalWrite(0, LOW);
    digitalWrite(5, HIGH);
  }else{
    Serial.print(time);
    Serial.print(", sensor2: ");
    Serial.println(IRvalueA);
    digitalWrite(0, HIGH);
    digitalWrite(5, LOW);
  }                                                                                                                                 
  
  
  IRvalueA = analogRead(pinIRa);
}


