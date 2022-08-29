#include <Servo.h>. 

const int trigPin = 4;
const int echoPin = 3;
const int buzzer = 10;

long duration;
int distance;
Servo myServo;


void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(9); 
  pinMode(buzzer, OUTPUT);
  
}


void loop() {
  if (distance <= 50){
digitalWrite(buzzer , HIGH);
delay(100);
digitalWrite(buzzer,LOW);

}

else{

digitalWrite(buzzer , LOW);

  
}
  
  
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance);
  Serial.print(".");
  }

  
 
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}



int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;

}
