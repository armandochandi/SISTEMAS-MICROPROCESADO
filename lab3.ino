/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * PRACTICA DE LABORATORIO #3
 * Nombres: Benavides Wilmer-Chandi Brayan-Chicaiza Fredy
 * Desarrolle un sistema que permita la visualización en dos 
 * display multiplexados el valor de voltaje en decimales. 
 * Con interrupciones de encendido y apagado. El límite se lo ingresa por Cx serial.
 */
int A=7; //pin de salida para 7447 menos significativo 
int B=6;
int C=5;
int D=4; //pin de salida para 7447 mas significativo
int i=0;//contador para opciones que se ejecutan de acuerdo al pulsador
float conversor,conversion;//valores float conversor=valor de entrada del potenciometro, conversion=valor que seingresa como limite
int dec=9; //pin de salida para el comun del display que muestra el valor decimal 
int entero=10; //pin de salida para el display que muestra el valor entero
int ent; //valor entero
int decimal;// valor decimal, despues de la coma
int indicador=11; //pin de salida para el led indicador en caso de que la entrada de voltaje sobrepase el valor ingresado como limite
String dato;//dato ingresado por serial como limite
void setup() {
  Serial.begin(9600); //inicializacion de la comunicacion serial
  attachInterrupt(0,off,LOW); //interrupcion declarada en bajo
  Serial.println("SISTEMA APAGADO"); //mensaje inicial del sistema
  pinMode(A,OUTPUT); //pin A declarado como salida
  pinMode(B,OUTPUT); //pin B declarado como salida
  pinMode(C,OUTPUT); //pin C declarado como salida
  pinMode(D,OUTPUT); //pin D declarado como salida
  pinMode(dec,OUTPUT); //pin de alimentacion para el display decimal declarado como salida
  pinMode(entero,OUTPUT); //pin de alimentacion para el desplay numerico declarado como salida
  pinMode(indicador,OUTPUT); //pin para led indicador declarado como salida
  digitalWrite(entero,LOW); //display entero inicia en bajo
  digitalWrite(dec,LOW); //display decimal inicia en bajo 
}

void loop() {
  if(i==2){ //si el metodo de interrupcion solicita que se ingrese el dato limite de entrada
    if(Serial.available()>0){ //se valida el dato serial 
    dato=Serial.readString(); //se lee el dato serial como String
    conversion=dato.toFloat(); //el dato limite se convierte de String a Float para la posterior comparacion
    Serial.println();// espacio despues de ingresar el dato a comparar
    if(conversion<=5){
    Serial.println("Se realiza la comparacion"); //se muestra el mensaje de que la comparacion es posible
      }else{
        Serial.println("No se puede comparar el dato ya que es mayor a 5v");//la comparacion con el dato de entrada no es posible y se muestra el mensaje
      }
      }
    }
  if(i==3){
  conversor=(analogRead(0)*5.00)/1023.00; //si se ejecuta de nuevo el pulsador se muestra el valor de entrada del potenciometro convertido a valor de voltaje 
  Serial.print(conversor); // se imprime el valor
  Serial.println("v"); // se imprime el simbolo correspondiente al valor 
  delay(100); //delay para que el sistema pueda imprimir el siguiente valor 
  ent=conversor; //valorentero del voltaje 
  decimal=(conversor-ent)*10; //valor decimal del voltaje 
  /*Serial.print("Parte entera:");
  Serial.println(ent);
  Serial.print("Parte decimal:");
  Serial.println(decimal);
  */
  digitalWrite(entero,HIGH); //habilitacion del display que muestra el valor entero
  digitalWrite(dec,LOW);
  mostrar(ent); //metodo para mostrar el valor entero en el display
  delay(100); //delay para el refrescamiento de datos
  digitalWrite(entero,LOW); 
  digitalWrite(dec,HIGH); //habilitacion del display decimal
  mostrar(decimal); //metodo para mostrar el valor decimal en el display correspondiente
  delay(10); //delay para refrescamiento de datos 
  if(conversor>conversion){ //comparacion del dato que entra como analogico (voltaje) y el dato ingresado como limite, si el dato ingresado es menor que el dato de entrada analogico
  Serial.println("ALARMA"); //se imprime el mensaje ALARMA
  digitalWrite(indicador,HIGH); //el led indicador esta activo
  delay(300);}else{ //tiempo para el sistema 
  digitalWrite(indicador,LOW);  // caso contrario el led esta en bajo 
    }
    }else{ 
  digitalWrite(entero,LOW); //si no se ejecuta esta opcion de la interrupcion los displays estan apagados 
  digitalWrite(dec,LOW);
      }
}
  void off(){ //void interrupcion proceso en el que se ejecutan las ordenes 
    switch(i){
    case 0:
    Serial.println("SISTEMA ENCENDIDO");
    delay(120000);
    i++;
    break;
    case 1:
    Serial.println("INGRESE DATO:");
    delay(120000);
    i++;
    break;
    case 2:
    Serial.println("SISTEMA COMPARA");
    delay(120000);
    i++;
    break;
    case 3:
    Serial.println("SISTEMA APAGADO");
    delay(120000);
    i=0;
    break;
    }
  }
void mostrar (int numero){ 
      switch(numero){
    //0
    case 0:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
    //1
    case 1:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
     //2
     case 2:
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break; 
     //3
     case 3:
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
     //4
     case 4:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
     //5
     case 5:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
     //6
     case 6:
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
     //7
     case 7:
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
     //8
     case 8:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    break;
     //9
     case 9:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    break;
    }}
