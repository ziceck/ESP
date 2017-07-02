/* Sensor de Distancia */

/* En esta experiencia vamos a leer los datos del sensor y vamos

* a estimar la distancia en cm que el sensor "ve"

* Hoja de datos del sensor: http://www.sharpsma.com/webfm_send/1208

*/

/*

Definimos una variable para la entrada del sensor.

El sensor utiliza la entrada analogica 0

*/

int sensorPin = 0;

// Definimos una variable para la lectura del sensor

int sensorRead=0;

// Definimos una variable para la conversion a distancia

double dist=0;

void setup() {

Serial.begin(9600);

delay(3000);

}

void loop() {

sensorRead = analogRead(sensorPin);

/*

La fórmula de conversión aproximada a la curva mostrada en la hoja de datos

es la siguiente:

distancia = (3027.4/Vo)^1.2134

En la fórmula, Vo es el voltaje que entrega el sensor (lo que mide)

En este caso, la distancia medida estará en centímetros

*/

//Aplicamos la fórmula para calcular la distancia

dist = pow(3027.4/sensorRead, 1.2134);

// El procedimiento interno está listo, ahora queda mostrar en pantalla

Serial.print("Distancia: ");

Serial.print(dist);

Serial.println(" cm.");

delay(1000);

}

/* Nota 1 (ruido en la medición del sensor):

* A veces, según la topología del circuito, puede haber "ruido" en la medición del sensor de distancia.

* En estos casos se utilizan ciertas técnicas y configuraciones circuitales (filtro pasabajos, etc.)

* para tratar de "limpiar" la señal que nos envía el sensor. Esas técnicas no están mostradas en el

* presente código, pero deben tenerse en cuenta en el armado del circuito para resultados más precisos

*/

/* Nota 2 (fórmula de conversión a distancia):

* Al ver la curva proporcionada por el fabricante del sensor, notamos que la fórmula de conversión deja

* de ser válida para distancias pequeñas. No hay que olvidar que la fórmula presentada se trata de una aproximación

* de la curva para distancias entre 10 y 80 cm, donde la curva tiene forma de hipérbola. Los parámetros de la

* fórmula pueden cambiarse si se estima conveniente para mejorar la exactitud de los resultados obtenidos

*/
