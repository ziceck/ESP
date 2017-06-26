/**
 * El siguiente código usa el ejemplo del push button y ademas ahora
 * se mostrará en el serial, el estado de los pines.
 */
 int btn=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("El boton tiene e valor ");
  btn=digitalRead(8);
  Serial.println(btn);
  digitalWrite(13,btn);
  delay(500);
}
