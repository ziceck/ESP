/**
 * Este ejemplo pretender mostar el uso de las variables char
 */
 char tab=9;
 char indice=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Esperando");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print((int)indice);
  Serial.print(tab);
  Serial.print(":");
  Serial.print(tab);
  Serial.println(indice);
  delay(500);
  indice=indice+1;
}
