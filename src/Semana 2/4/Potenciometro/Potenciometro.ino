/*

* Esta experiencia muestra el uso de la funcion analogRead(). Con esta funcion se mide el voltaje de un divisor de tension

* entre un resistor y un potenciometro en serie. Luego, a traves de operaciones matematicas, se muestra en la serial, el

* valor aproximado de la resistencia en la posicion del potenciometro.

*/

int btn1 = 2;

int AnInput = 0;

int lectura = 0;

void setup() {

Serial.begin(9600);

delay(1000);

}

void loop() {

//valor entero entre 0 y 1023 correspondiente al valor digitalizado
// de le entrada analogica
lectura = analogRead(AnInput);

if (digitalRead(btn1) == LOW) {

//Imprime el valor digital

Serial.println(lectura);

}

else {

//Imprime el equivalente en voltaje

Serial.println(lectura * 0.0049);

}

delay(1000);

}
