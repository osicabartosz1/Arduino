const int gasSensor =0;
const int beep= 13;
int maximum = 0;
int minimum = 1024;

void setup(){
  Serial.begin(9600);      // sets the serial port to 9600
  pinMode(beep, OUTPUT);   
  digitalWrite(beep, HIGH);  

}
void loop(){
  int voltage;
  voltage = getVoltage(gasSensor);
  if(maximum<voltage){maximum = voltage;}
  if(minimum>voltage){minimum = voltage;}
  
  String output;
  
  output = String(voltage) + "; minimum = " + minimum + "; maximum = " + maximum + "; avarage = ";

  Serial.print(output);
  Serial.println(GetAverage((float)voltage));

  delay(1000);
}
 
int getVoltage(int pin){
  return (analogRead(pin));
}

float GetAverage(float vol)
{
  static int n = 0;
  static float avr = 0;

  n++;
  float d = (vol-avr);
  avr+=d/n;
  
  if(d>2){digitalWrite(beep, LOW);}
  else{digitalWrite(beep, HIGH);}
  
  return avr;
}

