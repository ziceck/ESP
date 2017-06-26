/*
Este ejemplo encience y apaga el led que trae por defecto la tarjeta arduino.
*/


void setup() {
  // put your setup code here, to run once:
 // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level) //pin d13
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
