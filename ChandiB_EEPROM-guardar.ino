#include <EEPROM.h>
/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: Chandi Brayan 
 * Realice un sistema que guarde en una posición de la memoria 
 * EEPROM solo cuando su valor exceda a la anterior lectura.
 */
 int guardado,valor,f=0;
 String dato;
 void setup() {
  // en la memoria solo se pueden guardar numeros entre 0 y 255
Serial.begin(9600);
attachInterrupt(0,ejecutar,LOW);
guardado=EEPROM.read(0);
}

void loop() { 
}
void ejecutar(){
  switch(f){
    case 0:
    Serial.println("El dato actual grabado es");
    delay(500);
    Serial.println(guardado=EEPROM.read(0));
    delay(500);
    Serial.println("Ingrese el valor a guardar");
    delay(500);
    if(Serial.available()>0)
     {
    dato=Serial.readString();
    valor=dato.toInt();
    delay(100);
     }
    f++;
    break;
    case 1:
    Serial.println("Ud Ingreso:");
    Serial.println(valor);
    delay(500);
        if(valor>guardado){
        Serial.println("EL VALOR ES MAYOR AL ANTERIOR");
        EEPROM.put(0,valor);
        delay(100);
        }
        else{
        Serial.println("El valor no es mayor al anterior");
        delay(100);
     }
    f=0;
    break;
      }
      EEPROM.update(0,guardado);
      }
