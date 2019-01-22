/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM     
 * SISTEMA MICROPROCESADOS
 * Nombre: Chandi Brayan 
 * Realizar un programa que permita que el conversor análogo 
 * digital configure al perro guardían a 10,20,30 y 40 segundos. 
 * Este proceso se visualiza en una lcd.
 * EL SISTEMA FUNCIONA PREVIAMENTE ESTABLECIENDO EL RANGO CON EL POTENCIOMETRO, SE LEE ESTE VALOR Y 
 * SE EFECTUA EL CORRESPONDIENTE RESET LUEGO DE PRESIONAR LA INTERRUPCION. 
 */
#include <LiquidCrystal.h> //libreria para el funcionamiento de la lcd
#include <MsTimer2.h> //libreria para la ejecucion del timer 
#include<avr/wdt.h> //libreria para el funcionamiento del perro guardian
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //RS-E-D4-D5-D6-D7 //distribucion de pides de la lcd en el arduino
 int tiempo; //contador para el timer
 float dato; //variable que recoge el dato de la entrada analogica
 void setup() {
 lcd.begin(16, 2); // lcd de 16x2
 Serial.begin(9600);//inicializacion de la comunicacion serial
 Serial.println("Coloque el potenciometro en el rango en el que desee el tiempo de reseteo");
 Serial.println("Inicia el sistema con la interrupcion"); //mensaje inicial
 attachInterrupt(0,activar,LOW); //interrupcion que da inicio al conteo para la ejecucion del reset
 lcd.setCursor(0,1); //posicion del cursor del lcd
 lcd.print("Reset: "); //mensaje inicial lcd
 }
void loop() {
dato=(analogRead(0)*5)/1023.00; //valor de la entrada analogica en funcion de 5v(transformacion) 
delay(500); //tiempo
lcd.setCursor(0,0); //posicion del texto en lcd
lcd.print(dato); //se imprime el dato de entrada en la lcd
}
void activar(){ //interrupcion que permite iniciar el perro guardian bajo la condicion del potenciometro de entrada
 MsTimer2::set(500,conteo); //tiempo 500ms para efecto de prueba, nombre del metodo timer
 MsTimer2::start(); //inicializacion del timer
 if(dato>=1 && dato<2 ){ //compara rangos de datos de entrada
  Serial.println("RESET EN 10S"); //se muestra en cuanto tiempo se llevara a cabo el reset
  lcd.setCursor(6,1); //posicion en la lcd
  lcd.print("10S"); //texto que se muestra en la pocicion 6,1 de la lcd
  delay(100);//tiempo para refrescamiento del sistema
  }
   if(dato>=2 && dato<3){           // SE REALIZA LA MISMA COMPARATIVA Y PROCESO QUE LAS CONDICIONES ANTERIORES
  Serial.println("RESET EN 20S");
  lcd.setCursor(6,1);
  lcd.print("20S");
  delay(100);
    } 
   if(dato>=3 && dato<4){           // SE REALIZA LA MISMA COMPARATIVA Y PROCESO QUE LAS CONDICIONES ANTERIORES
  Serial.println("RESET EN 30S");
  lcd.setCursor(6,1);
  lcd.print("30S");
  delay(100);
    }
   if(dato>=4 && dato<5){           // SE REALIZA LA MISMA COMPARATIVA Y PROCESO QUE LAS CONDICIONES ANTERIORES
  Serial.println("RESET EN 40S");
  lcd.setCursor(6,1);
  lcd.print("40S");
  delay(100);
    }    
  }
void conteo(){ //metodo del timer que se activa con la interrupcion
tiempo++; //tiempo en aumento
Serial.println(tiempo); //se imprime el valor del contador
   if(dato>=1 && dato<2 ){ //condicion a la que tiene que estar el valor de entrada del potenciometro
    if(tiempo==10){ //el tiempo debe llegar a 10s
    lcd.setCursor(6,1); //se posiciona el texto en la lcd
    lcd.print("HECHO"); //se verifica que se ha hecho el reset
    delay(100); //tiempo
    Serial.println("RESET"); //se muestra por comunicacion serial el mensaje de que se a reseteado el sistema
    wdt_enable(WDTO_15MS); //perro guardian habilitado
      } 
    }
    if(dato>=2 && dato<3){  //MISMO PROCESO ANTERIOR
      if(tiempo==20){
    lcd.setCursor(6,1);
    lcd.print("HECHO");
    delay(100);
    Serial.println("RESET");
    wdt_enable(WDTO_15MS);  
        }
    }
      if(dato>=3 && dato<4){  //MISMO PROCESO ANTERIOR
        if(tiempo==30){
    lcd.setCursor(6,1);
    lcd.print("HECHO");
    delay(100);
    Serial.println("RESET");
    wdt_enable(WDTO_15MS);
        }
    }
      if(dato>=4 && dato<5){   //MISMO PROCESO ANTERIOR
        if(tiempo==40){
       lcd.setCursor(6,1);
       lcd.print("HECHO");
       delay(100);   
       Serial.println("RESET");
       wdt_enable(WDTO_15MS); 
          }
    }
}
