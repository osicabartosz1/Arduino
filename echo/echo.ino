#define BAUD_RATE 9600

// Setup, initialize 
void setup() 
{
  Serial.begin(BAUD_RATE);  

  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// Loop forever
void loop() 
{
  // Serial data is pending
  if (Serial.available()) 
  { 
    // Turn built in LED on
    digitalWrite(LED_BUILTIN, HIGH); 

    // Echo serial data on serial device
    Serial.write( Serial.read() );

  // Turn built in LED off
    digitalWrite(LED_BUILTIN, LOW); 
  }  
}
