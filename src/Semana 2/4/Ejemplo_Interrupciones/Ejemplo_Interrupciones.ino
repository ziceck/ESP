/**
 * Este código es un ejemplo de interrupciones
 */
//Definimos el pin correspondinte al led

int ledPin = 13;

//Definimos el pin correspondiente a la interrupcion 0

int intPin = 2;

void setup()

{

//Configuramos los pines como salida

pinMode(2,OUTPUT);

pinMode(ledPin, OUTPUT);

digitalWrite(intPin, HIGH);

/*Configuramos la interrupcion 0 para activarse en el

flaco de bajada y ejecutar la funcion prende_led*/

attachInterrupt(0, prende_led, FALLING);

}

void loop()

{

digitalWrite(ledPin, LOW);

delay(500);

digitalWrite(intPin, LOW);

/* En este momento se activa la alerta, por lo que se

ejecuta la funcion prende_led */

delay(500);

}

void prende_led(){

digitalWrite(ledPin, HIGH);

digitalWrite(intPin, HIGH);

}

///función para desactivar una interrupcion >>> detachInterrupt(interrupcion);
/// detatchInterrupt(0); ó detatchInterrupt(0);
