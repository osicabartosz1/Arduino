#include <Servo.h>
#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

double kat1, kat2;
int servoPin = 2; // pin sterujący Arduino
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


Servo servo;

int servoAngle = 0; // pozycja startowa serwa w stopniach
int a = 340;
int b = 2500;

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin,a,b);
  inputString.reserve(200);
  
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);

}

void loop()
{
  //Serial.println("inputString:" + inputString); 
  getGyroValues();
  //ask();
  int pos = 0;
  servo.writeMicroseconds(350);              // tell servo to go to position in variable 'pos' 
  delay(5000);     

  for(pos = a; pos <= b; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos' 
    delay(1000);     
    getGyroValues();
    printStatus();    // waits 15ms for the servo to reach the position 
  } 
//  Serial.print("kat1: ");Serial.println(kat1);
//  Serial.print("kat2: ");Serial.println(kat2);
//  Serial.print("zakres: ");Serial.println(kat2 - kat1);
//  servo.detach();
//  b=b+10;
//  servo.attach(servoPin,a,b);

  serialEvent();
  //delay(10000);
}

void printStatus()
{ 
    Serial.print(servo.read());
    Serial.print("  ;");Serial.print(servo.readMicroseconds());
    //Serial.print("  Z = ");Serial.print(AcZ);
    double katz = asin((double)AcZ/16384.0)*180.0/3.14;//17528  lub 16384
    double katy = asin((double)AcY/16384.0)*180.0/3.14;//17528  lub 16384
    double katx = asin((double)AcX/16384.0)*180.0/3.14;//17528  lub 16384

    if(servo.read()==0)
    {
      kat1 = katz;
    }
    if(servo.read()==180)
    {
      kat2 = katz;
    }
    //Serial.print("  katz = ");Serial.print(AcZ);
    Serial.print("  ; ");Serial.print(AcX);
    Serial.print("  ; ");Serial.println(AcY);

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
    if (stringComplete) {
    Serial.println(inputString); 
    // clear the string:
    int value = inputString.toInt();
    if(value>=0 && value<=180)
    {
      run(value);
    }
    inputString = "";
    stringComplete = false;   

  }
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

void getGyroValues()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read(); 
}

void printGyroValues()
{

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ); 
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
}
