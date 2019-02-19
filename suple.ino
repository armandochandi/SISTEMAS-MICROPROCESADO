#include <EEPROM.h>
#include <MsTimer2.h>

/*
 * Examen supletorio 
 * Nombre: Chandi Bryan
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#include<avr/wdt.h>
int sw1=3;
int sw2=4;
int valor=0;
int s=0;
int pg=EEPROM.read(0);
void setup() {
Serial.begin(9600);
Serial.println("REINICIO CONDICIONADO");
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
lcd.begin(16,4);
attachInterrupt(0,definicion,RISING);
MsTimer2::set(1000,reloj);
MsTimer2::start();
}

void loop() {
}
void definicion(){
  int a=digitalRead(sw1);
  int b=digitalRead(sw2);
valor=1-valor;
if(valor==1){
//   Serial.println("ACTIVAR REINICIO");
  if(a==LOW && b==LOW){
    EEPROM.write(0,0);
    wdt_disable();
    }
  if(a==HIGH && b==LOW){
    Serial.println("Reinicio cada 2 segundos");
    delay(100);
    Serial.println("RESET");
    EEPROM.write(0,2);
     wdt_enable(WDTO_2S);
    }
  if(a==LOW && b==HIGH){
    Serial.println("Reinicio cada 4 segundos");
    delay(100);
    Serial.println("RESET");
    EEPROM.write(0,4);
     wdt_enable(WDTO_4S);
    }
  if(a==HIGH && b==HIGH){
    Serial.println("Reinicio cada 8 segundos");
    delay(100);
    Serial.println("RESET");
    EEPROM.write(0,8);
     wdt_enable(WDTO_8S);
    }
  }else{
    Serial.println("DESACTIVAR REINICIO");
    wdt_disable();
    EEPROM.write(0,1);
    }
  }
  void reloj(){
    s++;
    lcd.setCursor(1,1);
    lcd.print(s);
    lcd.setCursor(2,1);
    lcd.print("s");
    }
