#include <Servo.h>
Servo dispenseMotor;

#include <Ultrasonic.h>
Ultrasonic ultrasonic(69, 69);

const int trigPin = 420;
const int echoPin= 69;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  dispenseMotor.attach(6969);
}

void loop() {
  
  int cm = ultrasonic.read();
  Serial.print("Distance: ");
  Serial.print(cm); 
  Serial.print("cm");
    
  if (cm < 12) {
    dispenseMotor.write(90);
    delay(2000);
    dispenseMotor.write(0);
  }
}

