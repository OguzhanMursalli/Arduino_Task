int a=3, b=4, c=5,
d=6, e=7,f=8,g= 9,
dig1=10, dig2=11,
dig3=12, dig4=13;
int buton2=A0;
int buton1=2;

byte sayilar[10][7]={
{1,1,1,1,1,1,0},
{0,1,1,0,0,0,0},
{1,1,0,1,1,0,1},
{1,1,1,1,0,0,1},
{0,1,1,0,0,1,1},
{1,0,1,1,0,1,1},
{1,0,1,1,1,1,1},
{1,1,1,0,0,0,0},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}};

int sayi = 0;
int birler;
int onlar;
int yuzler;
int binler;

int zaman=0;
int gecikme=100;

void setup() {
Serial.begin(9600);

for(int a=3;a<=13;a++){
pinMode(a, OUTPUT);
}
pinMode(buton1, INPUT);
pinMode(buton2, INPUT);
}


void loop()
 {

//pin ayarlama
digitalWrite(dig1, HIGH);
digitalWrite(dig2, HIGH);
digitalWrite(dig3, HIGH);
digitalWrite(dig4, HIGH);


//sayı sınırlama
  if(sayi<=0){
   sayi=0;
  }
  if(sayi>=9999){
   sayi=9999;
  }


//sayı ayrıştırma
birler = sayi%10;
onlar = (sayi%100)/10;
yuzler = (sayi%1000)/100;
binler =sayi/1000;
 

//buton kontrol
  if(millis()-zaman>gecikme){
 if(digitalRead(buton1)==1)
  {
    while(digitalRead(buton1)){
     delay(10);
    }
    sayi ++;
    Serial.println(sayi);
  }
  if(digitalRead(buton2)==1)
  {
    while(digitalRead(buton2)){
     delay(10);
    }
    sayi--;
     Serial.println(sayi);
  }
  zaman=millis();
  }


//döngüler
if(birler>=0 && digitalRead(dig1)==1){
   for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[birler][i-3]);
   }
digitalWrite(dig4, LOW);
  delay(5);
digitalWrite(dig4, HIGH); 
}


if(sayi>=10 && digitalRead(dig4)==1){
   for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[onlar][i-3]);
   }
digitalWrite(dig3, LOW);
  delay(5);
digitalWrite(dig3, HIGH);

}


if((yuzler>=1 || binler>=1) && digitalRead(dig3)==1){
  for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[yuzler][i-3]);
   }
digitalWrite(dig2, LOW);
  delay(5);
digitalWrite(dig2, HIGH);
}


if(binler>=1 && digitalRead(dig2)==1){

   for(int i=3;i<=9;i++){
digitalWrite(i,sayilar[binler][i-3]);
   }
digitalWrite(dig1, LOW);
  delay(5);
digitalWrite(dig1, HIGH);
}

}
 