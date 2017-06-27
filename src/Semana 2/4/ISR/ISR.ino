/*

* Esta experiencia muestra el uso de ISR. Consiste en que al presionar el boton, sin importar en que momento se haga,

* el led cambiara su estado: si esta en su fase encendida, se apagara, y viceversa.

*/

int Btn0 = 2; // Pin ligado a int.0

int Btn1 = 3; // Pin ligado a int.1

int pinLed = 11;

void setup() {

pinMode(Btn0, INPUT);

pinMode(Btn1, INPUT);

pinMode(pinLed, OUTPUT);

attachInterrupt(0,apaga_led, RISING);

attachInterrupt(1,prende_led, RISING);

Serial.begin(9600);

delay(2000);

}

void loop() {

delay(2500);

Serial.print("Han pasado ");

delay(2500);

Serial.println("5 segundos");

}

/* La funcion de interrupcion cambia el estado actual del led */

void apaga_led() {

digitalWrite(pinLed, 0);

}

void prende_led() {

digitalWrite(pinLed, 1);

}
