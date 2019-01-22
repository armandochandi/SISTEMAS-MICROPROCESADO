#include <EEPROM.h>
#include<avr/wdt.h>

/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM 
 * SISTEMAS MICROPROCESADOS
 * Nombre: Chandi Brayan
 * Prueba1-2do Bimestre
 * EMULADOR DE FUNCIONAMIENTO DE CONTROL DE CHEVYSTAR
 */
 /*
  * Para poder ingresar de nuevo la clave se debe presionar el master 
  */
 int pulsador1=4; //pulsadores
 int pulsador2=5;
 int pulsador3=6;
 int estado=0; //variable que guarda las posiciones en la secuancia de los pulsadores
 int tiempo[]={100,100,100,100,100}; //nombre del vector que guarda los datos ingresados por los pulsadores
 int clave[]={0,0,0,0,0};//clave de acceso 0=A;1=B;2=C //clave original establecida previamente
 int nuevaclave[4];//nueva clave tiene 5 digitos
 int i=0,j=0;//contadores
 int X,Y,Z; //variables que guardan los valores de lectura de los pulsadores 
 int valor=0; //estado de la interrupcion
 int intentos=0;//contador de intentos
void setup() {
Serial.begin(9600); //inicializacion de la comunicacion serial
attachInterrupt(0,master,LOW);//interrupcion
pinMode(pulsador1,INPUT); //pulsadores declarados como entrada
pinMode(pulsador2,INPUT);
pinMode(pulsador3,INPUT);
//EEPROM.write(0,clave[0]); //se graba la contraseña predefinida 
//EEPROM.write(1,clave[1]);
//EEPROM.write(2,clave[2]);
//EEPROM.write(3,clave[3]);
//EEPROM.write(4,clave[4]);
}
void loop() {
  if(valor==HIGH){ //si la contraseña es correcta se enciende el carro
    leerp();//metodo leer contraseña
    }
}
void master(){ //metodo master
  valor=1-valor; // cada que se ejecuta la interrupcion cambia el valor
  if(valor==HIGH){ //si se ejecuta la interrupcion
    Serial.println("ACTIVADO"); //el sistema esta activado y se le puede ingresar la clave
    }else{
    Serial.println("DESACTIVADO"); //si es sistema esta desactivado no valida la contraseña
      }
  }
void leerp(){ //metodo para validar la contraseña
  X=digitalRead(pulsador1); //valor del pulsador X
  Y=digitalRead(pulsador2); //valor del pulsador Y
  Z=digitalRead(pulsador3); //valor del pulsador z
    if(X){ //si se lee el pulsador x
    tiempo[estado]=0; //se guarda en la posicion 0 del vector tiempo
    estado++;//es estado se incrementa
    delay(500); //delay para que refrescar el sistema
      }
      if(Y){ //si se lee el pulsador y
    tiempo[estado]=1; //se guarda el valor en la posicion 1 del vector
    estado++;//el estado se incrementa
    delay(500);
      }
      if(Z){ // si se lee el pulsador z
    tiempo[estado]=2; //se guarda el valor en la posicion 2 del vector
    estado++;//aumenta el estado es decir la posicion del vector
    delay(500);
      }
    if(estado==5){ //si se llenan las 5 posiciones 
    if(tiempo[0]==EEPROM.read(0) && tiempo[1]==EEPROM.read(1) && tiempo[2]==EEPROM.read(2) && tiempo[3]==EEPROM.read(3) && tiempo[4]==EEPROM.read(4)){
        Serial.println("Se puede encender el carro"); //la contraseña es valida
        delay(200);
        }else{
          Serial.println("INCORRECTO"); //la contraseña no es correcta
          delay(200);
          intentos++;//se incrementa el numero de intentos
          reinicio();//si intentos llega a 3 se ejecuta el metodo reinicio
          estado=0;
          valor=valor-1;
          }
        }
    }
    void reinicio(){ //metodo para reiniciar el sistema
    if (intentos == 3) { //si intentos =3
      generar();//se ejecuta el metodo generar contraseña
      Serial.println("Reinicio");//se imprime el aviso de reinicio
      delay(200);
      intentos = 0;//los intentos son igual a 0
      wdt_enable(WDTO_15MS); //se llama al perro guardian 
      Serial.println("***************");//se imprime para nuevo reinicio del sistema
    }
  }
  void generar(){ //metodo para generar nueva clave
    randomSeed(millis());
    nuevaclave[0]=random(3);
    nuevaclave[1]=random(3);
    nuevaclave[2]=random(3);
    nuevaclave[3]=random(3);
    nuevaclave[4]=random(3);
    EEPROM.write(0,nuevaclave[0]);//se sobreescribe la clave anterior
    EEPROM.write(1,nuevaclave[1]);
    EEPROM.write(2,nuevaclave[2]);
    EEPROM.write(3,nuevaclave[3]);
    EEPROM.write(4,nuevaclave[4]);
    Serial.print("Su nueva clave es:"); //se imprime la nueva clave para dar aviso al usuario
    Serial.print(nuevaclave[0]);
    Serial.print(nuevaclave[1]);
    Serial.print(nuevaclave[2]);
    Serial.print(nuevaclave[3]);
    Serial.println(nuevaclave[4]);
    }
