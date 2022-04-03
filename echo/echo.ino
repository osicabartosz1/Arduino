
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    digitalWrite(LED_BUILTIN, HIGH); 

    // read the incoming byte:

    // say what you got:
    Serial.print("I received: ");
    Serial.print(Serial.readString());
    digitalWrite(LED_BUILTIN, LOW); 

  }
}
