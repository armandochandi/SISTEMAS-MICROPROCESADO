/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOR
 * COMUNICACION SERIAL 
 * Nombre: Brayan Chandi 
 *  Realizar un programa que permita ingresar el número de cédula con el guión y posteriormente validarlo
 */
#include<stdlib.h> //libreria genera del lenguaje C
int cedula; //cedula ingresada como int 
int a,b,c,d,e,f,g,h,i,j,k; //nombre de cada digito de la cedula 
int pares,impares,total,dec=0; //operadores para los coparadores entre los digitos 
void setup() {
 Serial.begin(9600); //se inicia la comunicacion serial 
}
void loop() {
Serial.println("Ingrese su Cedula");//se muestra el mensaje para ingresar el numero de cedula 
Serial.println(cedula);// se ingresa la cedula 
delay(4000); //delay para que se pueda ingresar el dato y pueda ser leido 
if(Serial.available()>0){ //validacion del dato ingresado
cedula=Serial.read(); //se lee el dato ingresado 
delay(1000);// delay para poder utilizar el dato-numero de cedula 
        a=cedula/1000000000; // obtencion del primer digito de la cedula de izquierda a derecha
        cedula=cedula-(a*1000000000);
        b=cedula/100000000;// obtencion del segundo digito de la cedula de izquierda a derecha
        cedula=cedula-(b*100000000);
        c=cedula/10000000;// obtencion del tercer digito de la cedula de izquierda a derecha
        cedula=cedula-(c*10000000);
        d=cedula/1000000;// obtencion del cuarto digito de la cedula de izquierda a derecha
        cedula=cedula-(d*1000000);
        e=cedula/100000;// obtencion del quinto digito de la cedula de izquierda a derecha
        cedula=cedula-(e*100000);
        f=cedula/10000;// obtencion del sexto digito de la cedula de izquierda a derecha
        cedula=cedula-(f*10000);
        g=cedula/1000;// obtencion del septimo digito de la cedula de izquierda a derecha
        cedula=cedula-(g*1000);
        h=cedula/100;// obtencion del octavo digito de la cedula de izquierda a derecha
        cedula=cedula-(h*100);
        i=cedula/10;// obtencion del noveno digito de la cedula de izquierda a derecha
        cedula=cedula-(i*10);
        j=cedula/1; // obtencion del decimo digito de la cedula de izquierda a derecha
        cedula=cedula-(j*1);
       if(cedula>2400000000){ // si los 2 primeros digotos de la cedula son mayores a 24 la cedula es invalida 
       Serial.println("cedula invalida");// se imprime el mensaje de cedula invalida 
        }else {
                pares=b+d+f+h; //suma de digitos pares para verificar estos digitos se multiplican por uno 
               
                a=a*2; // los digitos impares se multiplican por 2 y luego se suman 
                if (a>9){
                        a=a%10+a/10;
                }
               
                c=c*2;
                if (c>9){
                        c=c%10+c/10;
                }
               
                e=e*2;
                if (e>9){
                        e=e%10+e/10;
                }
               
                g=g*2;
                if (g>9){
                        g=g%10+g/10;
                }
               
                i=i*2;
                if (i>9){
                        i=i%10+i/10;
                }
                impares=a+c+e+g+i; //suma de digitos imapares 
                total=pares+impares; //suma de resultados 
                while (dec-total!=j && dec<total+10){ //resta de todos los resultados por la decena superior 
                        dec=dec+10;
                }
               
                if (dec-total==j){ //debe ser igual al ultimo digito(digito verificador)
                        Serial.println("cedula valida"); // si la resta es igual al digito verificador se imprime el mensaje cedula valida 
                }else {
                        Serial.println("Cedula invalida"); // si la resta no es igual al digito verificador se imprime el mensaje cedula invalida 
                }
              
        }
        return 0;// el proceso termina y regresa a 0 
       
  }}
