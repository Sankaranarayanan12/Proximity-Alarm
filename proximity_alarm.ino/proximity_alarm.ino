int triggerPin=12;
int echoPin=13;
int ledPin=8;
int buzzerPin=7;
float time;
float distance;
void setup() {
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(2000000);

}

void loop() {

  digitalWrite(triggerPin,LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);

  
  time=pulseIn(echoPin,HIGH);
  distance=(765.*5280.*12.*time)/(3600.*1000000.);
  Serial.println(distance);

  
  if (distance<=30.00 && distance>=10.00){
    digitalWrite(ledPin,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(5000);
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzerPin,LOW);
    delay(5000);
    
  } 
  
  if (distance<10.00 and distance>=5.00){
    digitalWrite(ledPin,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(3000);
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzerPin,LOW);
    delay(3000);
    
  }
  
  
  else if (distance<5.00){
    digitalWrite(ledPin,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzerPin,LOW);
    delay(1000);

  }
  
  
  
  

 
  
  


}
