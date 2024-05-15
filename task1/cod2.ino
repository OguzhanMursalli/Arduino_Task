int a=3, b=4, c=5, d=6, e=7,
 f=8,  g= 9, pd=10, sayac=0,buton=12;
int zaman=0;
int gecikme=100;
byte sayilar[16][8]={
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
{1,1,1,1,1,1,0,1},
{1,0,0,1,1,1,1,1},
{1,0,0,0,1,1,1,1}};


void setup() {
  Serial.begin(9600);

  for(int a= 3;a<=10;a++){
pinMode(a, OUTPUT);
}
pinMode(12, INPUT);
}


void loop()
 {
  if(digitalRead(buton)==1 && millis()-zaman>gecikme)
  {
    while(digitalRead(buton)){
     delay(10);
    }
     sayac++; 
    zaman=millis();
     Serial.println(sayac);
  }
  for(int i=3;i<=10;i++){
digitalWrite(i,sayilar[sayac][i-3]);
   }
   if(sayac>=16)
   {
    sayac =0;
   }
}