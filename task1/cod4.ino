#include <Keypad.h>

char tus_dizi[4][4] = {{'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}};
byte satir_pin[4] = {1,2,A0,A1};
byte sutun_pin[4]={A2,A3,A4,A5};
Keypad kumanda = Keypad(makeKeymap(tus_dizi),satir_pin,sutun_pin,4,4);

int a=3, b=4, c=5,
d=6, e=7,f=8,g= 9,
dig1=10, dig2=11,
dig3=12, dig4=13;

byte sayilar[14][8]={
{1,1,1,1,1,1,0,0},
{0,1,1,0,0,0,0,0},
{1,1,0,1,1,0,1,0},
{1,1,1,1,0,0,1,0},
{0,1,1,0,0,1,1,0},
{1,0,1,1,0,1,1,0},
{1,0,1,1,1,1,1,0},
{1,1,1,0,0,0,0,0},
{1,1,1,1,1,1,1,0},
{1,1,1,1,0,1,1,0},
{1,1,1,0,1,1,1,1},
{1,1,1,1,1,1,1,1},
{1,0,0,1,1,1,0,1},
{1,1,1,1,1,1,0,1}};

char birler;
char onlar;
char yuzler;
char binler;

char tus;
String tam;
void setup() {

Serial.begin(9600);

for(int a=3;a<=13;a++){
pinMode(a, OUTPUT);
}


}

void loop() {
 
digitalWrite(dig1, HIGH);
digitalWrite(dig2, HIGH);
digitalWrite(dig3, HIGH);
digitalWrite(dig4, HIGH);


birler = tam[tam.length()-1];
onlar = tam[tam.length()-2];
yuzler = tam[tam.length()-3];
binler = tam[tam.length()-4];

tus = kumanda.getKey();

if(tus){
 if(tus =='#'){
tam = tam.substring(0,tam.length()-1);
}
else if(tus == '*'){
  tam = "";
}
else{
tam =tam + tus;
}

Serial.println(tus);
Serial.println(tam);

}

//display yazdırma

if(birler){
  yazdirma(birler);
digitalWrite(dig4, LOW);
delay(5);
digitalWrite(dig4, HIGH);
}

if(onlar){
  yazdirma(onlar);
digitalWrite(dig3, LOW);
delay(5);
digitalWrite(dig3, HIGH);
}

if(yuzler){
  yazdirma(yuzler);
digitalWrite(dig2, LOW);
delay(5);
digitalWrite(dig2, HIGH);
}

if(binler){
  yazdirma(binler);
digitalWrite(dig1, LOW);
delay(5);
digitalWrite(dig1, HIGH);
}
}

//char-int dönüşüm ve atama
void yazdirma(char x){

switch(x){

case '0': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[0][i-3]);
}
break;

case '1': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[1][i-3]);
}
break;

case '2': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[2][i-3]);
}
break;

case '3': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[3][i-3]);
}
break;

case '4': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[4][i-3]);
}
break;

case '5': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[5][i-3]);
}
break;

case '6': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[6][i-3]);
}
break;

case '7': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[7][i-3]);
}
break;

case '8': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[8][i-3]);
}
break;

case '9': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[9][i-3]);
}
break;

case 'A': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[10][i-3]);
}
break;

case 'B': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[11][i-3]);
}
break;

case 'C': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[12][i-3]);
}
break;

case 'D': 
for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[13][i-3]);
}
break;

default:break;
}
}


