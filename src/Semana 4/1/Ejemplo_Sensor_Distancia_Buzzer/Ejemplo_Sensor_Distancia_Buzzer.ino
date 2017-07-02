/* Sensor de Proximidad con Buzzer (como el de los autos!) */

/* En esta oportunidad vamos a crear un arreglo circuital que nos avisará

* con frecuencias de un determinado tono si estamos cerca o no de un obstáculo

* Hoja de datos del sensor de distancia: http://www.sharpsma.com/webfm_send/1208

*/

#include <math.h> //Librería de funciones matemáticas

// Definimos el pin del buzzer

int buzzPin = 8;

/*

Definimos una variable para la entrada del sensor.

El sensor utiliza la entrada analogica 0

*/

int sensorPin = 0;

// Definimos una variable para la lectura del sensor

int sensorRead = 0;

// Definimos una variable para la conversion a distancia

double dist = 0;

long tiempo_previo = 0; // Variable para medir tiempo (inicial)

int intervalo; // Variable

void setup() {

pinMode(buzzPin, OUTPUT);

Serial.begin(9600);

delay(3000);

}

void loop() {

sensorRead = analogRead(sensorPin); //Lectura de voltaje del sensor (lo que mide)

// La fórmula de conversión aproximada a la curva mostrada en la hoja de datos

// es la siguiente:

// distancia = (3027.4/Vo)^1.2134

// En la fórmula, Vo es el voltaje que entrega el sensor (lo que mide)

// En este caso, la distancia medida estará en centímetros

dist = pow(3027.4 / sensorRead, 1.2134); //Fórmula vista en ejemplo anterior

//Ahora pensaremos en una función tal que al aproximarnos al obstáculo suene más rápido

//tal como los sensores que utilizan algunos autos para estacionarse

// La lógica es entonces, a menor distancia, más rápido suenan los tonos

// La función que usaremos será f(x)= 36x - 320 . Lo explicaremos más adelante

unsigned long tiempo_actual = millis(); //millis() mide el tiempo de ejecución del programa

intervalo = 36 * dist - 320 ; //nuestra función f(x)

if (intervalo <= 50) { //Condición para evitar números negativos y el siseo del buzzer en pequeñas distancias

intervalo = 50;

}

if (intervalo > 2500) { //Condición para evitar largos períodos de tiempo entre sonidos

intervalo = 2500;

}

/* Esta condición if tiene la siguiente lógica:

* Mientras más cerca esté el sensor,"dist" será más pequeño y por ello "intervalo" será más pequeño también,

* por lo tanto, se requerirá menos diferencia de tiempo(condición del if) para que el buzzer emita un sonido.

* Esto es, mientras más cerca está el sensor del obstáculo, más veces por segundo se emitirá un sonido.

*/

if (tiempo_actual - tiempo_previo >= intervalo) {

tiempo_previo = tiempo_actual;

/*

La función "tone" toma 3 parámetros

- Respectivamente pide: El pin de salida, la frecuencia de tono, duración de tono

- Esta función entrega una señal que siempre tiene el mismo ciclo de trabajo

y dado esto no cambia el volumen del buzzer

En este caso generamos un tono de 4 kHz durante 20 milisegundos en el pin del buzzer

*/

tone(buzzPin, 4000, 20);

//Ahora solo queda ver en pantalla la distancia medida por el sensor:

Serial.print("Distancia: ");

Serial.print(dist);

Serial.println(" cm.");

}

}

/* Nota 1 (acerca de la función f(x) utilizada para calcular delay):

/* Elegimos esa función para que cuando la distancia sea aprox 10 cm tengamos una diferencia de tiempo

* pequeña(40 ms) entre sonidos y para grandes distancias, como 80 cm, tengamos una diferencia de tiempo

* entre sonidos de aproximadamente 2.5 s

*/

/* Nota 2 (ruido en la medición del sensor):

* A veces, según la topología del circuito, puede haber "ruido" en la medición del sensor de distancia

* en estos casos. se utilizan ciertas técnicas y configuraciones circuitales (filtro pasabajos, etc.)

* para tratar de "limpiar" la señal que nos envía el sensor. Esas técnicas no están mostradas en el

* presente código, pero deben tenerse en cuenta en el armado del circuito para resultados más precisos

*/

/* Nota 3 (fórmula de conversión a distancia):

* Al ver la curva proporcionada por el fabricante del sensor, notamos que la fórmula de conversión deja

* de ser válida para distancias pequeñas. No hay que olvidar que la fórmula presentada se trata de una aproximación

* de la curva para distancias entre 10 y 80 cm, donde la curva tiene forma de hipérbola. Los parámetros de la

* fórmula pueden cambiarse si se estima conveniente para mejorar la exactitud de los resultados obtenidos

*/


