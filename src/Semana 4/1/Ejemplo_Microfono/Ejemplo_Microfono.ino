int micPin = 8;

int ledPin = 7;

boolean micRead;

boolean state = LOW ;

void setup() {

pinMode(ledPin,OUTPUT);

pinMode(micPin,INPUT);

}

void loop() {

micRead = digitalRead(micPin);

if (micRead == HIGH){

state = !state;

digitalWrite(ledPin,state);

delay(500);

}

}
