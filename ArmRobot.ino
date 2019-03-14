#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <SoftwareSerial.h>

//Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
// Set the speed to start, from 0 (off) to 255 (max speed)
Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
SoftwareSerial Bluetooth(10, 11); // RX, TX
int Data; // the data received

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
  AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

int verticalSpeed = 100;
int horizontalSpeed = 110;

int delayInterval = 25;
void loop() {
  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    if(Data=='F'){  
      leftMotor->setSpeed(verticalSpeed);
      leftMotor->run(FORWARD);
      rightMotor->setSpeed(verticalSpeed);
      rightMotor->run(FORWARD);

      delay(delayInterval);
      leftMotor->run(RELEASE);
      rightMotor->run(RELEASE);
      
      Bluetooth.println("front");
    }
    else if(Data=='B'){
      leftMotor->setSpeed(verticalSpeed);
      leftMotor->run(BACKWARD);
      rightMotor->setSpeed(verticalSpeed);
      rightMotor->run(BACKWARD);
      
      delay(delayInterval);
      leftMotor->run(RELEASE);
      rightMotor->run(RELEASE);

      Bluetooth.println("backwards");
      
    }else if(Data=='L'){
      leftMotor->setSpeed(horizontalSpeed);
      leftMotor->run(FORWARD);

      delay(delayInterval);
      leftMotor->run(RELEASE);
            
      Bluetooth.println("left");
    }else if(Data=='R'){
      rightMotor->setSpeed(horizontalSpeed);
      rightMotor->run(FORWARD);
      
      delay(delayInterval);
      rightMotor->run(RELEASE);
      
      Bluetooth.println("right");
    }
    else{;}
  }
}



//
//SoftwareSerial BTSerial(10,11); // RX, TX
//
//// Create the motor shield object with the default I2C address
//Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
//
//// Select which 'port' M1, M2, M3 or M4. In this case, M1
//// Set the speed to start, from 0 (off) to 255 (max speed)
//Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
//Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
//
//void setup() {
//  String setName = String("AT+NAME=MyBTBee\r\n"); //Setting name as 'MyBTBee'
//
//  Serial.begin(9600);
//  Serial.print("AT");                              //  SET Module to " Program Mode "
//  delay(1000);
//  Serial.print("AT+NAME");                          //  SET Module to " Program New Name "
//  Serial.print("HC-orange");                       //  SET "  New Name "
//  Serial.print("\r\n");
//
//   erial.print("AT+BAUD:");                           //  SET Baud SPEED  "to Comm with Module "
//  Serial.print("9600");                                //  SET Baud SPEED   
//  Serial.print("\r\n");
//  delay(1000);
//
//  delay(1000);  
//  BTSerial.begin(9600);
//        
//  // AFMS.begin();  // create with the default frequency 1.6KHz
//  AFMS.begin(1000);  // OR with a different frequency, say 1KHz
//}
//
//char data = 0; // stores incoming character from other device
//void loop() {
//   if(Serial.available() > 0) {      // Send data only when you receive data:
//      data = Serial.read();            //Read the incoming data & store into data
//      Serial.print(data);              //Print Value inside data in Serial monitor
//      Serial.print("\n");        
//      leftMotor->setSpeed(10);
//      leftMotor->run(FORWARD);
//      
//      rightMotor->setSpeed(10);
//      rightMotor->run(FORWARD);
//      delay(100);
//    
//      rightMotor->run(RELEASE);
//      rightMotor->run(RELEASE);
//      delay(100);//If value is 0 then LED turns OFF
//   }
//}
