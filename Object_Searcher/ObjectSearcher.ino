#include <Servo.h>
int echo = 8;
int trig = 9;
int servo = 10;
int turnCounter = 0;
boolean flip = false;
Servo robot;

void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(servo, INPUT);
  robot.attach(servo);
  robot.write(0);
  
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  digitalWrite(trig,LOW);
  long duration = pulseIn(echo,HIGH);
  int distance = (int) duration * 0.017;

  Serial.println(distance);

  if(distance < 2 || distance > 100){
    if(flip == false) {
    turnCounter ++;
    }
    else {
      turnCounter --;
    }

    if (turnCounter > 149) {
      flip = true;
    }
    else if (turnCounter < 2) {
      flip = false;
    }
    robot.write(turnCounter);
    Serial.println("turnCounter: ");
    Serial.print(turnCounter);
    
  }
    
 

}
