#include <Servo.h>

int servoPin = 2; // pin sterujący Arduino

Servo servo;

int servoAngle = 0; // pozycja startowa serwa w stopniach

int a = 1000;
int b = 2000;

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin,a,b);
}

void loop()
{
// kontrola kierunku serwomechanizmu i pozycję
  
//  run(90); // Przekrec serwo SG90 w lewo do 90 stopni
//
//  delay(1000); // czekaj 1 sek
//  run(70); // Cofnij serwo SG90 na 70 stopni
//  delay(1000); // czekaj 1 sek
//  run(40); // Przekrec serwo SG90 40 stopni
//  delay(1000); // czekaj 1 sek
//  run(120); // Przekrec serwo SG9 na 120 stopni
//  delay(1000); // czekaj 1 sek
//  
  //end
  
  // kontrola predkosc serwomechanizmu
  servo.detach();
  a=a-100;
  b=b+100;
  Serial.println("nowe parametry");
  Serial.println(a);
  Serial.println(b);
  servo.attach(servoPin,a,b);
  delay(5000);

  // jeśli zmienisz wartość opóźnienia (z przykładowej wartości 100 na 50), prędkość serwomechanizmu się zmieni na wybraną wartosc
  for(servoAngle = 0; servoAngle <= 180; servoAngle++) //przekręć serwo od 0 stopni do 180 stopni
  {
  run(servoAngle);
  delay(100);
  }
  
  for(servoAngle = 180; servoAngle >= 0; servoAngle--) //teraz cofnij mikro serwo od 0 stopni do 180 stopni
  {
  run(servoAngle);
  delay(50);
  }
  
  
//koniec
}

void run(int value)
{
    Serial.println("Servomechanizm zmienil pozycje");
    servo.write(value);
    Serial.println(value);
}
