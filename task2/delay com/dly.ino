int gecikme = 0;
char veri;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}

void loop() {
if(Serial.available()>0){
  veri = Serial.read();
  if(veri == 'a'){
    gecikme = gecikme + 100;
    veri = '\0';
  }
}
  digitalWrite(8,HIGH);
  delay(gecikme);
  digitalWrite(8,LOW);
   delay(gecikme);
}
