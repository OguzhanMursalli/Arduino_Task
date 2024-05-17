char veri;
byte durum;
void setup() {
Serial.begin(9600);
pinMode(8,OUTPUT);
}

void loop() {
if(Serial.available()>0){
  veri= Serial.read();
  if(veri=='a'){
    durum = !durum ;
  }
}
digitalWrite(8, durum);
}
