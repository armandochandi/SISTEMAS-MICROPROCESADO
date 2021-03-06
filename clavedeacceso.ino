/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * INTERRUPCIONES Y COMUNICACION SERIAL
 * Nombres: Benavides Wilmer, Chandi Brayan, Chicaiza Fredy
 * Diseñar un sistema de clave de acceso que contenga 6 digitos, cuando la clave sea correcta se enciende el led verde, si es
 * incorrecta se enciende el led rojo, la clave se debe mostrar por comunicacion serial y se debe utilizar una interrupcion para apagar y encender el sistema 
 */
int ledverde=11; //pin declarado para conectar el led verde 
int ledrojo=12;  //pin declarado para conectar el led rojo
int pulsadorA=7; //pin declarado para el pulsador A
int pulsadorB=8; //pin declarado para el pulsador B
int pulsadorC=9; //pin declarado para el pulsador C
int pulsadorD=10; //pin declarado para el pulsador D
int valor=LOW; //  valor con el que inicia la interrupcion, el led rojo siempre va estar en high se apagara solo cuando 
int clave[]={0,0,1,2,3,2}; //vector de valores enteros correspondientes a la clave determinada como valida --> A=0,B=1,C=2,D=3 (clave=AABCDC)
int sec[]={100,100,100,100,100,100}; //tiempo desigando para la ejecucion de cada digito de la clave 
int estado = 0; //varibale estado en la que se almacenan los datos ingresados mediante la secuencia de pulsadores
void setup() {
   Serial.begin(9600); //inicializacion de la comunicacion serial 
  pinMode(ledverde, OUTPUT); //led verde modo de pin salida 
  pinMode(ledrojo,OUTPUT);   //led rojo modo de pin salida
  pinMode(pulsadorA,INPUT);  //pulsador A modo de pin entrada
  pinMode(pulsadorB,INPUT);  //pulsador B modo de pin entrada
  pinMode(pulsadorC,INPUT);  //pulsador C modo de pin entrada
  pinMode(pulsadorD,INPUT);  //pulsador D modo de pin entrada
  attachInterrupt(0,apagar,RISING); // la interrupcion esta declarada en el pin 2, RISISNG es un flanco de subida pasa de valor alto a valor bajo y visceversa 
  digitalWrite(ledrojo,valor); //inicialmente el led rojo esta apagado 
  digitalWrite(ledverde,valor); //inicialmente el led verde esta apagado
  Serial.println("Ingrese la clave mediante la secuencia de pulsadores (sistema apagado)"); //mensaje inicial
}
void apagar(){
 valor =! valor; //si el sistema esta apagado se enciende y si esta encendido se apaga 
   if (valor==HIGH){
    ejecutar();
    Serial.println("El sistema esta encendido");
    }
  else {
    Serial.println("El sistema apagado");
    }
}
void loop() { 
  ejecutar();
  }
void ejecutar(){ 
int  A=digitalRead(pulsadorA); //lectura del pulsador A
int  B=digitalRead(pulsadorB); //lectura del pulsador B
int  C=digitalRead(pulsadorC); //lectura del pulsador C
int  D=digitalRead(pulsadorD); //lectura del pulsador D
  if(A){ //si se lee el pulsador A
     sec[estado]=0; //se guarda el dato en la posicion 0 del vector sec
    estado++; //la variable estado incrementa una posicion en el vector 
    delay(500); //tiempo requerido para que se pueda leer el siguiente digito 
    }
  if(B){ //si se lee el pulsador B
    sec[estado]=1; //se guarda el dato en la posicion 1 del vector sec
    estado++; //la variable estado incrementa una posicion en el vector 
    delay(500); //tiempo requerido para que se pueda leer el siguiente digito 
    }
    if(C){ //si se lee el pulsador C
    sec[estado]=2; //se guarda el dato en la posicion 2 del vector sec
    estado++; //la variable estado incrementa una posicion en el vector 
    delay(500);//tiempo requerido para que se pueda leer el siguiente digito 
    }
    if(D){ //si se lee el pulsador D
    sec[estado]=3; //se guarda el dato en la posicion 3 del vector sec
    estado++; //la variable estado incrementa una posicion en el vector 
    delay(500); //tiempo requerido para que se pueda leer el siguiente digito 
    }
    if(estado==6){ //la variable estado se incrementa hasta 6 que es la cantidad de digitos que tiene la contraseña
    if((sec[0]==clave[0])&&(sec[1]==clave[1])&&(sec[2]==clave[2])&&(sec[3]==clave[3])&&(sec[4]==clave[4])&&(sec[5]==clave[5])){ //se compara los datos del vector sec (datos ingresados) con los datos de la contraseña guaradada
      digitalWrite(ledverde,valor); //si son iguales se prende el led verde 
      Serial.print("");
      Serial.println("clave correcta"); //se muestra el mensaje de clave correcta
      delay(2000); //tiempo que permanece encendido el led verde 
    }
    else { // en caso de no coincidir la clave ingresa
      digitalWrite(ledrojo,valor); //se enciende el led rojo
      Serial.println("");
      Serial.println("clave incorrecta"); //se imprime el mensaje de clave incorrecta
      delay(2000); //tiempo que permanece encendido el led rojo 
      estado=0; //el contador estado del array vuelve a 0 para volver a leer otra secuencia de datos
      valor=valor-1;
    }
  } 
}
