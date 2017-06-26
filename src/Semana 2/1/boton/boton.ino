/***
 * 
 * Este codigo enciende un led usando un push boton
 */

int btn=0;

void setup(){
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
}

void loop(){
  btn=digitalRead(8);
  digitalWrite(13,btn);
}

