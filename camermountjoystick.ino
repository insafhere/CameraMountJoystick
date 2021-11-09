#include <Servo.h>

const int servo2 = 11;       // Base Servo (X axis)
const int servo1 = 10;       // Top Servo (Y Axis)
const int joyX = A4;        // L/R Parallax Thumbstick
const int joyY = A3;        // U/D Parallax Thumbstick

int servoVal;           // variable to read the value from the analog pin

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

void setup() {

  // Servo  
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo

  // Inizialize Serial
  Serial.begin(9600);
}


void loop(){

    // Display Joystick values using the serial monitor
    outputJoystick();

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal = analogRead(joyX);          
    servoVal = map(servoVal, 0, 1023, 180, 0);     // scale it to use it with the servo (result  between 0 and 180)

    myservo2.write(servoVal);                         // sets the servo position according to the scaled value    

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal = analogRead(joyY);           
    servoVal = map(servoVal, 0, 1023, 180, 0);     // scale it to use it with the servo (result between 70 and 180)

    myservo1.write(servoVal);                           // sets the servo position according to the scaled value

    delay(15);                                       // waits for the servo to get there

}

/**
* Display joystick values
*/
void outputJoystick(){

    Serial.print(analogRead(joyX));
    Serial.print ("---"); 
    Serial.print(analogRead(joyY));
    Serial.println ("----------------");
}
