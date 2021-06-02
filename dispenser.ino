#include <Servo.h>
Servo dispenseMotor
myservo.attach(6969);

const int shoutPin = 420;
const int listenPin = 69;

void setup() {
  Serial.begin(9600);
  pinMode(shoutPin, OUTPUT);
  pinMode(listenPin, INPUT);
  bool handInRange = false;

}

void loop() {

  digitalWrite(shoutPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(shoutPin, LOW);
  duration = pulseIn(listenPin, HIGH)
  distanceCM = microsecondsToCentimeters(duration);

  if (handInRange = true) {
    
  if (distanceCM < 12) {
    dispenseMotor.write(90);
    delay(350);
    dispenseMotor.write(0);
    bool handInRange = true;
  } else if (distanceCM > 12) { 
    bool handInRange = false;
    } else {
      cout << "Error: Value not found" << endl;
      return 0;
    }
    
} else { }

  delay(125); 
}
