int triggerPin=12;
int echoPin=13;
int ledPin=8;
int buzzerPin=7;
float time;
float distance;
bool ledState=LOW;
unsigned long previousMillis=0;
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

  unsigned long currentMillis=millis();

  
  if (distance<=30.00 && distance>=10.00){
    if(currentMillis-previousMillis>=5000){
      previousMillis=currentMillis;
      ledState=!ledState;
      digitalWrite(ledPin,ledState);
      digitalWrite(buzzerPin,ledState);
    }
  } 
  
  else if (distance<10.00 and distance>=5.00){
    if(currentMillis-previousMillis>=3000){
      previousMillis=currentMillis;
      ledState=!ledState;
      digitalWrite(ledPin,ledState);
      digitalWrite(buzzerPin,ledState);
    }
    
    
  }
  
  
  else if (distance<5.00){
    if(currentMillis-previousMillis>=1000){
      previousMillis=currentMillis;
      ledState=!ledState;
      digitalWrite(ledPin,ledState);
      digitalWrite(buzzerPin,ledState);
    }
  else{
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzerPin,LOW);
  }

  }
  
  
  
  

 
  
  


}
