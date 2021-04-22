/* 
For use with the Adafruit Motor Shield v2 
---->  http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
// Adafruit_StepperMotor *myMotor1 = AFMS.getStepper(200, 1);
 Adafruit_StepperMotor *myMotor2 = AFMS.getStepper(200, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
//  myMotor1->setSpeed(10);  // 10 rpm   
  myMotor2->setSpeed(10);
}

void loop() {
  // put your main code here, to run repeatedly:
 // myMotor1->step(80,FORWARD,DOUBLE);
  //Serial.println("motor 1 forward");
   // delay(1000);
  //myMotor1->step(80,BACKWARD,DOUBLE);
 // Serial.println("motor 1 backward");
    //delay(1000);
  
  myMotor2->step(80,FORWARD,DOUBLE);
  Serial.println("motor 2 forward");
    delay(1000);
  myMotor2->step(80,BACKWARD,DOUBLE);
  Serial.println("motor 2 backward");
    delay(1000);
}
