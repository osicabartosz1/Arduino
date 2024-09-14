#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 30; pos <= 120; pos += 10) { // dla pewnosci czy problem nie jest w zbyt duzym zakresie serwa mozesz zmienic np od 160 do 20  
    myservo.write(pos);              
       delay(150);               //zwiekszajac opoznienie np na 70-100 ms oraz wyzej "+= 10" na np 5 lub 3 jak bedzie ok to raczej brak mu 
  }
  for (pos = 180; pos >= 0; pos -= 10) { // dla pewnosci czy problem nie jest w zbyt duzym zakresie ruchu serwa mozesz zmienic np od 160 do 20 
    									//wtedy nie dojdzie do konca tylko bedzie działac w zakresie od 20-160 i wyeliminujesz jedna z przyczyn.
    myservo.write(pos);              
       delay(150);                
  }
}
