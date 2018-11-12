
#include<stdlib.h>
int j,c=0;
String str;
int tam;
char palabra;
int a=0,e=0,i=0,o=0,u=0;
void setup() {
  Serial.begin(9600);
}

void loop() {
if(Serial.available()>0){
       str=Serial.readString();
       tam=str.length(); 
       char vector [tam];//
       str.toCharArray(vector,tam+1); 
       palabra=vector[1]; 
       delay(500);
 for (j=0;j<50;j++){
if (vector[j]=='a' || vector[j]=='e' || vector[j]=='i' || vector[j]=='o' || vector[j]== 'u' ||vector[j]=='A' || vector[j]=='E' || vector[j]=='I' || vector[j]=='O' || vector[j]== 'U' ){
c++;
}
  } 
Serial.println("vocales: ");
Serial.println(c-1);
c=0;
}}
 
