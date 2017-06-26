void setup() {
  // put your setup code here, to run once:
// Asignación de entradas y salidas
pinMode(11, OUTPUT); // el led es la salida
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(11, HIGH);

delay(1000);

digitalWrite(11, LOW);

delay(1000);
}
