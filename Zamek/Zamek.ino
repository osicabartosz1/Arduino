int wypelnienie = 0 ;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  pinMode(5, OUTPUT); //Konfiguracja pinu 5 jako wyjście
  pinMode(6, OUTPUT); //Konfiguracja pinu 6 jako wyjście
  Serial.begin(9600);
  inputString.reserve(200);

}
 
void loop() {
  
    if (stringComplete) {
	wypelnienie = inputString.toInt(); //Jeśli wypełnienie większe od 100%, to wracamy na początek

  	if (wypelnienie >= 255) { //Jeśli wypełnienie mniejsze od 100%
          wypelnienie=0;
	}
    inputString = "";
    stringComplete = false; 
    }
        Serial.println(wypelnienie);

    
	analogWrite(5, wypelnienie); //Generujemy sygnał o zadanym wypełnieniu
 	analogWrite(6, 0); //Generujemy sygnał o zadanym wypełnieniu
        delay(1000);

	analogWrite(6, wypelnienie); //Generujemy sygnał o zadanym wypełnieniu
 	analogWrite(5, 0); //Generujemy sygnał o zadanym wypełnieniu
  delay(1000);
    serialEvent();

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
