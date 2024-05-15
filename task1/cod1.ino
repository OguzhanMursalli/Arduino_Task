#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C ekran(0x27,16,2);
int ilk=-1;
byte ohm[8] = {B00000,
B00000,
B01110,
B10001,
B10001,
B01010,
B11011};

void setup() {
ekran.createChar(1,ohm);
ekran.begin(16,2);
pinMode(5, INPUT);

}

void loop() {
int deger = analogRead(A0);
if(ilk != deger){
ekran.clear();
ekran.print(deger);
ekran.write(1);
ilk = analogRead(A0);
}
}