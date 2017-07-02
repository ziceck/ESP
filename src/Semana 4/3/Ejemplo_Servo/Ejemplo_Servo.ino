/* Control de un Servomotor con Potenciómetro */

#include <Servo.h>

/* En general podemos controlar el motor sin llamar

* a una librería específica. Sin embargo, utilizar la librería

* que viene incluida en el programa nos entrega más prestaciones

* y facilidad a la hora de controlar el motor.

* Puedes consultar las funciones de esta librería en el siguiente link:

* https://www.arduino.cc/en/pmwiki.php?n=Reference/Servo

*/

/* En este ejemplo usaremos un potenciómetro para controlar

* el ángulo en que queremos que entregue el motor

*/

int potPin = 0; //Pin del potenciómetro

int button_pin = 7; // Pin donde se conecta el botón que permite Encendido/Apagado

int led_pin = 13; // Pin de la luz led que avisará estados

int servoPin = 6; //Pin donde va conectado el servo

int button_read; // Variable para la lectura del botón

int potVal; //Variable para el valor del divisor de tensión del pot

int ang = 90; //Variable en la que guardaremos el ángulo según potVal para el motor

boolean apagar = true; // Variable que enciende/apaga el motor

Servo miServo; //Le ponemos nombre al motor ("miServo" corresponde a un objeto de la clase Servo)

void setup() {

pinMode(led_pin, OUTPUT);

pinMode(servoPin, OUTPUT);

pinMode(button_pin, INPUT);

miServo.attach(servoPin); //Le damos el pin de Arduino al que va conectado el motor

}

void loop() {

button_read = digitalRead(button_pin); //Leemos el estado del botón

//Si el botón se presiona, entonces se enciende el led del board para avisar y regresa el motor a 90°

if (button_read == LOW) {

apagar = !apagar; //cambio de estado del circuito

digitalWrite(led_pin, !apagar); //Se enciende si apagar es false(es decir está encendido) y viceversa

ang = 91; //Dejamos el motor en 90° (estado reposo).

delay(250); //Para que el programa evite apagar/encender continuamente

}

if (apagar == false) { //Es decir, si el sistema está encendido...

potVal = analogRead(potPin); //Leemos el valor del divisor de tensión

ang = map(potVal, 0, 1023, 0, 180);

}

miServo.write(ang);

// Esta función recibe el ángulo que queremos se mantenga el motor

// Darle 90 como valor significa que dejamos al Servo justo al medio

// (Suponiendo que describe 180)

}


