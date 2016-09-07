int SERVOPIN = 4;
int servoPos=90;

void initServo() {
  servo.attach(SERVOPIN);
  servo.write(servoPos);
}

void btControlServo(String cmd) {
  int value = (cmd.substring(2,cmd.length())).toInt();
  if((value>=0)&&(value<=180)){
     Serial.print("servopos ");
     Serial.print(value);
     Serial.println();
     servo.write(value);
  }
}
