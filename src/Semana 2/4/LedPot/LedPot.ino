/*

Esta experiencia muestra el uso de la funcion analogRead() y

analogWrite() para controlar la intensidad de un led con

un potenciometro.

3,5,6,9,10,11 pueden generar una salida pseudo analogica

*/

int AnInput = 0;

int ledPin = 11; //Este pin tiene PWM

int lectura = 0;

int aux = 0;

void setup() {

Serial.begin(9600);

delay(1000);

pinMode(11,OUTPUT);

}

void loop() {

lectura = analogRead(AnInput);

//Mapea el valor del ADC entre 0 y 255

aux = map(lectura, 0, 1023, 0, 255);

analogWrite(ledPin,aux);

}
