/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: Chandi Brayan 
 * Realizar un reloj que permita ingresar una alarma por comunicacion serial 
 */
#include <LiquidCrystal.h> //libreria que permite el funcionamiento de la lcd
#include <MsTimer2.h> //libreria timer 
LiquidCrystal lcd(13,12,11,10,9,8);//RS-E-D4-D5-D6-D7 //distribucion de pides de la lcd en el arduino
int hor=0,minut=0,seg=0; //variables iniciales
int f=0;
int h,m; 
int ha,ma;
int zumb=5;
void setup() {
  pinMode(zumb,OUTPUT);
  attachInterrupt(0,alarma,LOW);
  Serial.begin(9600); //inicializacion de la comunicacion serial
  MsTimer2::set(200,tiempo); //inicializacion del timer 
  MsTimer2::start(); //metodo start permite el arranque del timer 
  lcd.begin(16,2); // lcd de 16x2
  lcd.setCursor(2, 0); // ubicacion del cursor dentrol de la lcd-columna,fila
  lcd.print(":"); //impresion que se desea mostrar en la lcd 
  lcd.setCursor(5, 0);
  lcd.print(":");
  lcd.setCursor(0, 0);
  lcd.print('0');
  lcd.setCursor(1, 0);
  lcd.print('0');
  lcd.setCursor(3, 0);
  lcd.print('0');
  lcd.setCursor(4, 0);
  lcd.print('0');
  lcd.setCursor(6, 0);
  lcd.print('0');
  lcd.setCursor(7, 0);
  lcd.print('0');
  lcd.setCursor(0,1);
  lcd.print("ALARMA: ");
}

void loop() {
}
void tiempo(){ //timer
  seg++; //incremento de segundos, variable inicial 
  if(seg<10){ //si segundos es menor a 10
  lcd.setCursor(7,0); //se muestra el conteo en la columna 7 de la fila 0
  lcd.print(seg); //se imprime el valor del conteo
  lcd.setCursor(6,0); //en la columna 6 y fila 0
  lcd.print('0'); //se imprime cero 
    }else{ //caso contrario los valores
  lcd.setCursor(6,0); //se imprimen en la columna 6 fila 0
  lcd.print(seg);} //valores que tiene el conteo de segundos 
  if(seg==60){ //si el conteo de la variable seg llega a 60
  seg=0; //la variable seg vuelve a ser 0 y se reinicia el conteo 
  lcd.setCursor(6,0); //en la columna 6 fila 0
  lcd.print(seg); //se vuelve a imprimir los valores dela variable seg 
  seg++; //incrementos de valores en la variable
  minut++; //la variable minut empieza su incremento
  if(minut<10){ //si minut es menor que 10
  lcd.setCursor(4,0); //el cursor se ubica en la columna 4 fila 0
  lcd.print(minut); //se imprime el valor dela variable minut 
  lcd.setCursor(3,0); // y en la posicion columna 3 fila 0
  lcd.print('0');}// se imprime 0
  else{ //caso contrario
   lcd.setCursor(3,0); //en la posicion columna 3 fila 0
  lcd.print(minut); //se imprime el valor de conteo de la variable minut
    }
 if(minut==60){//si minut llega a 60
  minut=0; //minut toma el valor de 0
  lcd.setCursor(4,0); //el cursor en la posicion columna 4 fila 0
  lcd.print(minut); //se imprime el valor de la variable minut
  lcd.setCursor(3,0); //el cursor esta en la posicion columna 3 fila 0
  lcd.print('0');  //se imprime el valor de 0
  hor++; //se incrementa la variable hor
  lcd.setCursor(0, 0); //cursor se ubica en la columna 0 fila 0
  lcd.print('0'); //se imprime el valor 0
  lcd.setCursor(1, 0); //en la columna 1 fila 0
  lcd.print('0'); // se imprime el valor 0
  if(hor<10){ // si hor es menor a 10 
  lcd.setCursor(1,0); //en la columna 1 fila 0
  lcd.print(hor); // se imprime el valor de hor
  lcd.setCursor(0,0); //en la columna 0 fila 0
  lcd.print('0'); //se imprime el valor 0
  }else{ //caso contrario
  lcd.setCursor(0,0); //en la columna 0 de la fila 0
  lcd.print(hor); //se imprime el valor de la variable hor 
    }
  }
  if(seg==60 && minut==60 && hor==24){ //si hora,minutos y segundos llegan a sus limites
  hor=0;
  minut=0; //las variables se reestablecen a 0
  hor=0;
  lcd.setCursor(1,0); // y se repite el ciclo 
  lcd.print(hor); 
  lcd.setCursor(4,0);
  lcd.print(minut); 
  lcd.setCursor(7,0);
  lcd.print(seg); 
  lcd.setCursor(0, 0);
  lcd.print('0');
  lcd.setCursor(3, 0);
  lcd.print('0');
  lcd.setCursor(6, 0);
  lcd.print('0');} 
  }  }
  void alarma(){
    switch(f){
      case 0:
      Serial.println("Establecer alarma");
      f++;
      break;
      case 1:
      Serial.println("Hora");
      Serial.println();
      if(Serial.available()>0){
      String valorh=Serial.readString();
      h=valorh.toInt();
      delay(1200);}
      f++;
      break;
      case 2:
      Serial.println("Minutos");
      Serial.println();
      if(Serial.available()>0){
      String valorm=Serial.readString();
      m=valorm.toInt();
      delay(1200);}
      f++;
      break;
      case 3:
      h=ha;
      m=ma;
      Serial.println("ALARMA CREADA"); 
      lcd.setCursor(8,1);
      lcd.print('0');
      lcd.setCursor(9,1);
      lcd.print(h);
      lcd.setCursor(10,1);
      lcd.print(':');
      lcd.setCursor(11,1);
      lcd.print('0');
      lcd.setCursor(12,1);
      lcd.print(m);
      lcd.setCursor(13,1);
      if(hor==ha && minut==ma){
      digitalWrite(zumb,HIGH);
    }
      f=0;
      break;
      }
    }
