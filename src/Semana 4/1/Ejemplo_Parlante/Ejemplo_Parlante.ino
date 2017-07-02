int AnInput = 0;

int buzzPin = 11; //Este pin tiene PWM

int lectura = 0;

int aux = 0;

void setup() {

pinMode(11,OUTPUT);

}

void loop() {

lectura = analogRead(AnInput);

//Mapea el valor del ADC entre 0 y 255

aux = map(lectura, 0, 1023, 0, 255);

analogWrite(buzzPin,aux);

}
