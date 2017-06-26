void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 delay(2000);
 Serial.println(min(1,2));
 Serial.println(max(1,2));
 Serial.println(abs(-5));
 Serial.println(constrain(10,5,11));
 Serial.println(map(1,10,20,40,50));
 Serial.println(pow(2,5));
 Serial.println(sqrt(20));
 Serial.println(sin(2));
 Serial.println(cos(2));
 Serial.println(tan(2));
}

void loop() {
  // put your main code here, to run repeatedly:

}
