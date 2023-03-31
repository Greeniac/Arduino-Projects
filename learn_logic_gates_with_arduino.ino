/* Github: https://github.com/Greeniac
Beware that this code is very inefficient and im stil pretty much a begginer.

Pins:
16x2 I2C LCD to your i2c pins, if you dont know your i2c pin you can just google it, and make sure that you have the LiquidCrystal_I2C library installed.
Led to pin 2, this led will show the state of the output as 1 = lit, 0 = off.
"A" Button to pin 3.
"B" Button to pin 4.
"C" Button to pin 5.

The buttons should output Low (Ground) when pressed and High (5v) when depressed.
The A & B buttons are inputs (YES & NOT will only use the A button because it only needs 1).

The C button is used to switch logic gates.

*/

#include <LiquidCrystal_I2C.h>
int Load = 0;
int a;
int b;
int s;
int Select = 0;
LiquidCrystal_I2C lcd(0x27,16,2);  

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      
  pinMode(2,OUTPUT);
  
  lcd.setCursor(2,0);   
  lcd.print("Logic Gates");
  lcd.setCursor(0,1);   
  lcd.print("Github: Greeniac");
delay(1500);

Select = 1;
}

void loop() {

lcd.setCursor(2,0);    
if ( digitalRead(5) == 0 && Select < 8){
  Select = Select + 1;
  digitalWrite(2,LOW);
  {delay(1);} while (digitalRead(5) == 0);
}
if ( digitalRead(5) == 0 && Select == 8){

 digitalWrite(2,LOW);
 Select = 0;
}
if (Select == 1){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("1: YES");
  delay(100);

}
else if (Select == 2){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("2: NOT");
  delay(100);
}
else if (Select == 3){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("3: AND");
  delay(100);
}
else if (Select == 4){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("4: OR");
  delay(100);
}
else if (Select == 5){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("5: XOR");
  delay(100);
}
else if (Select == 6){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("6: NAND");
  delay(100);
}
else if (Select == 7){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("7: NOR");
  delay(100);
}
else if (Select == 8){
    lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("8: XNOR");
  delay(100);
}
if (Select == 1 && digitalRead(3) == 0){
  digitalWrite(2,HIGH);
}
 else if (Select == 1 && digitalRead(3) == 1){
  digitalWrite(2,LOW);
}
 else if (Select == 2 && digitalRead(3) == 0){
  digitalWrite(2,LOW);
}
 else if (Select == 2 && digitalRead(3) == 1){
  digitalWrite(2,HIGH);
}
 else if (Select == 3 && digitalRead(3) == 0 && digitalRead(4) == 0){
  digitalWrite(2,HIGH);
}
 else if (Select == 3 && digitalRead(3) == 1 || digitalRead(4) == 1){
  digitalWrite(2,LOW);
}
if (Select == 4 && digitalRead(3) == 0){
  digitalWrite(2,HIGH);
}
 else if (Select == 4 && digitalRead(4) == 0){
digitalWrite(2,HIGH);
}
if (Select == 4 && digitalRead(3) == 1 && digitalRead(4) == 1){
  digitalWrite(2,LOW);
}
if (Select == 5 && digitalRead(3) == 0 && digitalRead(4) == 1){
  digitalWrite(2,HIGH);
}
 if (Select == 5 && digitalRead(4) == 0 && digitalRead(3) == 1){
digitalWrite(2,HIGH);
}
 if (Select == 5 && digitalRead(3) == 1 && digitalRead(4) == 1){
  digitalWrite(2,LOW);
}
 if (Select == 5 && digitalRead(3) == 0 && digitalRead(4) == 0){
  digitalWrite(2,LOW);
}
if (Select == 6 && digitalRead(3) == 1 && digitalRead(4) == 0 ){
  digitalWrite(2,HIGH);
}
if (Select == 6 && digitalRead(3) == 0 && digitalRead(4) == 1 ){
  digitalWrite(2,HIGH);
}
 if (Select == 6 && digitalRead(3) == 1 && digitalRead(4) == 1 ){
  digitalWrite(2,HIGH);
 }
if (Select == 6 && digitalRead(3) == 0 && digitalRead(4) == 0){
  digitalWrite(2,LOW);
}
 else if (Select == 7 && digitalRead(4) == 0){
digitalWrite(2,LOW);
}
if (Select == 7 && digitalRead(3) == 1 && digitalRead(4) == 1){
  digitalWrite(2,HIGH);
}
if (Select == 8 && digitalRead(3) == 0 && digitalRead(4) == 1){
  digitalWrite(2,LOW);
}
 if (Select == 8 && digitalRead(4) == 0 && digitalRead(3) == 1){
digitalWrite(2,LOW);
}
 if (Select == 8 && digitalRead(3) == 1 && digitalRead(4) == 1){
  digitalWrite(2,HIGH);
}
 if (Select == 8 && digitalRead(3) == 0 && digitalRead(4) == 0){
  digitalWrite(2,HIGH);
}
}
