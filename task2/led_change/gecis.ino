char veri;
int gecis=2;
void setup() {
 for(int i = 2; i<10; i++){
  pinMode(i,OUTPUT);
 }
Serial.begin(9600);

}

void loop() {
if(Serial.available()>0){
  veri = Serial.read();
  if(veri == '>'){
    gecis --;
  }
  if(veri == '<'){
    gecis ++;
  }
}

digitalWrite(gecis,HIGH);
digitalWrite(gecis-1,LOW);
digitalWrite(gecis+1,LOW);
if(gecis>9){
  digitalWrite(9,LOW);
  gecis = 2;
 }
 if(gecis<2){
  digitalWrite(2,LOW);
  gecis=9;
 }
veri = '\0';
}
