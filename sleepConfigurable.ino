/*
 * UNIVERSIDAD T'ECNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: Chandi Brayan 
 * Realizar un sistema que permita configurar por comunicación 
 * serial o por pulsadores el modo sleep cada 25 segundos.
 */
 #include <MsTimer2.h>
 #include <avr/sleep.h>
 #include <LowPower.h> //libreria low power
 int s=0;
 String dato;
 int valor;
void setup() {
  Serial.begin(9600);
 MsTimer2::set(300,reloj);
 MsTimer2::start();
 set_sleep_mode(SLEEP_MODE_IDLE); //modo sleep
 sleep_mode();  
}

void loop() {

}
void reloj(){
  if(s<25){
  s++;
  Serial.println(s);
  }
  else{
    Serial.println("Configurar Sleep");
    Serial.println("Escriba el tiempo para dormir al sistema (8s-4s-2s-1s)");
    delay(12000);
    if(Serial.available()>0){
       dato=Serial.read();
       valor=dato.toInt();
      }
              if(valor==1){
              sleep_enable();
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
        }
              if(valor==2){
              sleep_enable();
        LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
        }
              if(valor==4){
              sleep_enable();
        LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
        }
              if(valor==8){
              sleep_enable();  
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
        }else{
          sleep_disable();
          }
   
    }
      s=0;
  }
