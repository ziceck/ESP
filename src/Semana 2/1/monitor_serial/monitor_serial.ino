/**
 * Este es un ejemplo básico para aprender a usar comunicación serial.
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(5000);
  Serial.println("Hola");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  Serial.print("Ha pasado");
  delay(500);
  Serial.println("Un segundo");
}
