// Motor 1
int dir1PinA = 5;
int dir2PinA = 6;
int speedPinA = 12; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 10;
int dir2PinB = 11;
int speedPinB = 13; // Needs to be a PWM pin to be able to control motor speed

void initMotors() {
  // define motor controller pins
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
}

void btControlMotor(String cmd) {
  int speed; // Local variable
  int value = (cmd.substring(2,cmd.length())).toInt();
  Serial.print("motor ");
   Serial.print(value);
   Serial.println();
  switch (value) {
    
      //______________Motor 1______________
      
      case 1: // Motors Forward
      analogWrite(dir1PinA, 0);
      analogWrite(dir2PinA, 255);
      analogWrite(dir1PinB, 0);
      analogWrite(dir2PinB, 255);
      Serial.println("Motors Forward"); // Prints out “Motor 1 Forward” on the serial monitor
      break;
      
      case 2: // Motors Reverse
      analogWrite(dir1PinA, 255);
      analogWrite(dir2PinA, 0);
      analogWrite(dir1PinB, 255);
      analogWrite(dir2PinB, 0);
      Serial.println("Motors Reverse");
      break;
      
      case 3: // Motors Stop
      analogWrite(dir1PinA, 0);
      analogWrite(dir2PinA, 0);
      analogWrite(dir1PinB, 0);
      analogWrite(dir2PinB, 0);
      Serial.println("Motors Stops");
      break;
      
      case 4: // Simulate Left Turn
      analogWrite(dir1PinA, 0);
      analogWrite(dir2PinA, 200);
      analogWrite(dir1PinB, 0);
      analogWrite(dir2PinB, 50);
      Serial.println("Simulate Left Turn");
      break;
      
      case 5: // Simulate Right Turn
      analogWrite(dir1PinA, 0);
      analogWrite(dir2PinA, 50);
      analogWrite(dir1PinB, 0);
      analogWrite(dir2PinB, 200);
      Serial.println("Simulate Right Turn");
      break;
      
      case 6: // Simulate Left Reverse
      analogWrite(dir1PinA, 200);
      analogWrite(dir2PinA, 0);
      analogWrite(dir1PinB, 50);
      analogWrite(dir2PinB, 0);
      Serial.println("Simulate Left Reverse");
      break;
      
      case 7: // Simulate RIGHT Reverse
      analogWrite(dir1PinA, 50);
      analogWrite(dir2PinA, 0);
      digitalWrite(dir1PinB, HIGH);
      analogWrite(dir2PinB, 0);
      Serial.println("Simulate Right Reverse");
      break;
      
      default: break;
  }
}
