/* Manejando un Motor DC! */

/* En esta experiencia vamos a manejar la velocidad de giro de un motor DC con la ayuda de un potenciómetro

* El elemento distintivo y que nos permite hacer esto fácilmente es un transistor (el BJT más común... el 2N2222)

* En esta configuración usamos a este elemento activo en región de saturación, lo que nos permite hacerlo funcionar

* como una resistencia controlada por voltaje, de manera tal que al aplicar más voltaje (en su base) obtendremos una

* mayor corriente en el colector del transistor (donde va el motor y este hacia el riel superior) lo que nos permite

* manejar y controlar la velocidad de giro del motor aplicando más o menos corriente.

* El papel que desempeña el potenciómentro es "decirle" al Arduino que tiene un determinado voltaje en su patita del medio

* hablamos de un divisor de tensión este terminal, el Arduino procesa este valor y envia una PWM con un ciclo de trabajo proporcional

* al valor de voltaje que le envió el potenciómetro.

* El ckt también es capaz de decirnos cual es el ciclo de trabajo cuando este varía de a 10%, contando desde 0 y además posee

* un botón que al ser presionado permite conocer el ciclo de trabajo de la PWM de forma instantánea.

*/

int motorPin = 6; // Pin que enviará la PWM al motor DC

int potPin = 0; // Entrada analogica que lee el voltaje del divisor de tensión que forma el potenciómetro

int button_pin = 7; // Pin donde se conecta el botón

int led_pin = 13; // Pin que avisará estados

int button_read; //Botón que nos permitirá conocer el ciclo de trabajo de forma instantánea

int potVal; // Iniciamos la variable que controla el Duty Cycle de la PWM

boolean apagar = true; // Variable para apagar o no el motor

void setup() {

pinMode(motorPin,OUTPUT); //Este pin enviará la PWM

pinMode(led_pin, OUTPUT); //Este pin tiene que ver con el led de aviso integrado en la placa

pinMode(button_pin, INPUT); //Led que lee el botón

}

void loop() {

button_read = digitalRead(button_pin); //Leemos el estado del botón

if (button_read == LOW){

apagar = !apagar; //Cambia el estado encendido/apagado del motor

potVal = 0; //Esto permitirá enviar una PWM con ciclo de trabajo 0 y apagará el motor

digitalWrite(led_pin, !apagar);

/* Recuerda bajar el nivel del pot al mínimo para que al volver a encender el motor no comience a girar de "golpe" */

delay(250); //Un pequeño delay para que no se active muchas veces el botón

}

if (apagar == false){

potVal = analogRead(potPin)/4; // Dividimos en 4 dada la salida de analogRead() (lo preparamos para analogWrite(), se puede utilizar la función "map()" también)

}

analogWrite(motorPin,potVal); // Enviamos la señal para controlar el motor

}
