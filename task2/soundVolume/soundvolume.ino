int veri;
void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
}

void loop() {
 int deger;
deger  = analogRead(A0);
veri = map(deger,0,1023,-96,0);
Serial.println(veri);

}