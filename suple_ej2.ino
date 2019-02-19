#include <EEPROM.h>

#include <MsTimer2.h>

/*
 * EJERCICIO 2 
 */
 #include<avr/wdt.h>
 #include <avr/sleep.h>
 #include <avr/power.h>
 #include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int dato;
String lecturai,lecturas; 
int valinferior;
int valsuperior;
int led1=6;
int led2=7;
int s=0;
void setup() {
  lcd.clear();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
Serial.begin(9600);
Serial.println("Ingrese el valor inferior de lectura");
delay(10);
if(Serial.available()>0){
  lecturai=Serial.readString();
  valinferior=lecturai.toInt();
  }
  delay(2500);
Serial.println("Ingrese el valor superior de lectura");
delay(10);
if(Serial.available()>0){
  lecturas=Serial.readString();
  valsuperior=lecturas.toInt();
  }
 delay(2000);
 Serial.println(valinferior);
 Serial.println(valsuperior);
 MsTimer2::set(2000,reloj);
 MsTimer2::start();
 attachInterrupt(0,configurar,LOW);
 set_sleep_mode(SLEEP_MODE_ADC);
 
}

void loop() {
  
}
void reloj(){
  EEPROM.read(8);
  s++;
  int i=valinferior;
  int h=valsuperior;
   dato=analogRead(0); 
   Serial.println(dato);
   if(dato<i || dato>h){
    EEPROM.write(8,s);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    if(s==EEPROM.read(8)+5){
      sleep_enable();
      }
    }
      if(dato>i && dato<h){
        digitalWrite(led2,LOW);
        digitalWrite(led1,LOW);
        }
  }
  void configurar(){
     wdt_enable(WDTO_2S);
    }
