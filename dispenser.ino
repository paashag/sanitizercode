#include <Servo.h>
Servo dispenseMotor
myservo.attach(6969);

#include <Ultrasonic.h>
Ultrasonic ultrasonic(69, 69);

const int shoutPin = 420;
const int listenPin = 69;

void setup() {
  Serial.begin(9600);
  pinMode(shoutPin, OUTPUT);
  pinMode(listenPin, INPUT);
  bool handInRange = false;

}

void loop() {
  int distanceCM = ultrasonic.read(CM);
  
  if (handInRange = true) {
    
  if (distanceCM < 12) {
    dispenseMotor.write(90);
    delay(600);
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
