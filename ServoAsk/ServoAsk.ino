#include <Servo.h>

int servoPin = 2; // pin sterujący Arduino
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


Servo servo;

int servoAngle = 0; // pozycja startowa serwa w stopniach

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin,404,2404);
  inputString.reserve(200);
}

void loop()
{
  Serial.println("inputString;" + inputString); 

  if (stringComplete) {
    Serial.println(inputString); 
    // clear the string:
    int value = inputString.toInt();
    //if(value>=0 && value<=180)
    {
      run(value);
    }
    inputString = "";
    stringComplete = false;   

  }
  serialEvent();
  delay(1000);
}

void run(int value)
{
    Serial.println("Servomechanizm zmienil pozycje");
    servo.write(value);
    Serial.println(value);
    delay(1000);
    Serial.println(servo.read());
    Serial.println(servo.readMicroseconds());


}

int ask()
{
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
