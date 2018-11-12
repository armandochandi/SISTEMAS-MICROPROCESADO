
/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 * FICA.CIERCOM 
 * SISTEMAS MICROPROCESADOS 
 * Comunicacion serial 
 * Nombre: Brayan Chandi
 * Realizar un sistema que permite determinar el número de vocales dentro de una palabra. 
 * Este dato es ingresado por comunicación serial y la respuesta del mismo de igual manera
 */

#include<stdlib.h> //libreria genera del lenguaje C
int j,c=0; //crear variables, la variable j es para el analisis de palabras y la variable c es el contador de vocales por palabra 
String str; // variable string 
int tam; //variable tam donde se guardara el tamaño de la palabra 
char palabra; //char palabra donde se almacenara el vector palabra como tal 
int a=0,e=0,i=0,o=0,u=0; //inicializacion de las vocales (no muy necesaria)
void setup() {
  Serial.begin(9600); //inicia la comunicacion serial 
}

void loop() {
if(Serial.available()>0){ //se valida la comunicacion serial 
       str=Serial.readString(); // el serial lee el dato ingreado
       tam=str.length(); //determina la longitud del string y lo guarda en la variable tam
       char vector [tam];//el valor tam corresponde al vector (cadena char)
       str.toCharArray(vector,tam+1); //conversion de string a char con el tamaño 
       palabra=vector[1]; // vector palabra con el vector inicializado en la posicion 1 
       delay(500);// delay- tiempo que le toma al sistemainicial con el proceso de analisis 
 for (j=0;j<50;j++){ //ciclo for recorre cada palabra en busca de vocales -analisis de cada vocal 
if (vector[j]=='a' || vector[j]=='e' || vector[j]=='i' || vector[j]=='o' || vector[j]== 'u' ||vector[j]=='A' || vector[j]=='E' || vector[j]=='I' || vector[j]=='O' || vector[j]== 'U' ){//si en el vector se encuentra una vocal mayuscula o minuscula 
c++; // se almacena en la variable c y el contador aumenta 
}
  } 
Serial.println("vocales: ");//se imprime el texto vocales en la terminal
Serial.println(c-1); //se imprime el numero de vocales que hay en la palabra 
c=0;//el contador de vocales vuelve a 0 para que se pueda analizar otra palabra 
}}
 
