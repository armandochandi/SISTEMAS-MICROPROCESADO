#include <LowPower.h> //libreria low power
/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: Chandi Brayan 
 * Realizar un programa que permita poner al sistema 19 segundos en modo sleep, 
 * se despierte, realice un lectura del conversor análogo digital, lo imprima 
 * por comunicación serial y vuelva a dormir 19 segundos.
 */

#include <MsTimer2.h> //libreria para el timer 2
#include <avr/sleep.h> //libreria sleep
#include <avr/power.h>//libreria para activar o desactivar perifericos
int cont; //contador
int i=0;//contador para las veces que se ejecutar el power sleep
void setup() {
  Serial.begin(9600); //inicializacion de comunicacion serial
  MsTimer2::set(1000,conteo); //metodo de timer2
  MsTimer2::start(); //inicializacion del timer
  Serial.println(analogRead(0));//se imprime el dato de entrada analogica
  set_sleep_mode(SLEEP_MODE_IDLE); //sleep mode
  sleep_mode();
  sleep_enable();//sleep habilitado
}

void loop() {

}
void conteo(){
  if(cont<20){
   cont++;
   for(;i<5;i++){
   LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);  //el sleep se ejecuta 3 veces dando como resultado un reinicio a los 20 segundos
    }
    i=0;
    }else
    if(cont==20){
     Serial.println(analogRead(0));
      }
       cont=0;
 }
