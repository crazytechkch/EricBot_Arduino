#include <pitches.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <U8glib.h>
#include <dht11.h>
#define DHT11_PIN A0

Servo servo;
dht11 dht;


long val = 0;
float temp = 0;
int potPin = DHT11_PIN;
long timerTemp = 0;
long timerServo = 0;
String string;
SoftwareSerial btSerial(2,3);

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  btSerial.begin(9600);
  
  // define motor,servo controller pins
  initMotors();
  initServo();
  initOled();
  //Song1(3);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(btSerial.available()>0){
    String string = "";
    while (btSerial.available()>0){
      char command = (byte)btSerial.read();
      string += command;
      delay(1);
    }
    if(string.startsWith("0:"))btControlServo(string);
    else if(string.startsWith("1:"))btControlMotor(string);
   }
   readTemp();
}

void readTemp(){
  if (millis()-timerTemp>=3000UL){
    timerTemp=millis();  
    int chk = dht.read(potPin);
    switch (chk)
    {
      case DHTLIB_OK: 
  		break;
      case DHTLIB_ERROR_CHECKSUM: 
  		break;
      case DHTLIB_ERROR_TIMEOUT: 
  		break;
      default: 
  		break;
    }
    
    temp = (float)dht.temperature;
     u8g.firstPage();  
    do {
      draw();
      String str = dht.humidity+"";
      u8g.setPrintPos(0,64);
      u8g.print((long)temp);
      u8g.print("\260C/");
      u8g.print(dht.humidity);
      u8g.print("%");
    } while( u8g.nextPage() );
  }
}
