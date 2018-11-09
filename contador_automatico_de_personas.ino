/*UNIVERSIDAD TECNICA DEL NORTE 
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS-laboratorio
 * Nombre: Brayan Chandi-Wilmer Benavides-Fredy Chicaiza
 * Contador de personas automatico
 * Objetivo: El sistema debe ser diseñado para realizar un contador personas 
 * que puede ser implementado en un bus o en un auditorio. Para ello, se debe 
 * presentar: diagrama de flujo, diagrama de bloques, diseño del sistema en 
 * proteus y armado en fritzing. Además, realizar pruebas de funcionamiento. 
*/
int A=5, B=4, C=3, D=2, mas=7,menos=6; //declaracion de variables, pines que se va a utilizar en el arduino 
int i=0;
int reset=11;
int dec=9;
int unit=8;
int decenas, unidades; //variables que definen como se obtendrda el valor que se va a mostrar como unidades o decenas
void setup() {
  //0
  pinMode(A,OUTPUT); //pin A declarado como salida 
  pinMode(B,OUTPUT);//pin B declarado como salida 
  pinMode(C,OUTPUT);//pin C declarado como salida 
  pinMode(D,OUTPUT);//pin D declarado como salida 
  pinMode(mas,INPUT);//pin mas declarado como entrada 
  pinMode(menos,INPUT);//pin menos declarado como entrada 
   pinMode(dec,OUTPUT); //pin dec declarado como salida 
  pinMode(unit,OUTPUT); //pin unit declarado como salida 
  

}

void loop() { // operaciones que se van a realizar 
  if(digitalRead(mas)==LOW ){ //si es leido el pulsador mas 
    delay(1); //hay un tiempo de espera de 1 ms
      if(i<51){ //si el contador es menor a 50
        i++; //el contador se incrementa 
      
        decenas=i/10; //las decenas se obtienen dividiendo el contador para 10
        unidades=i-(decenas*10); //obtencion de las unidades que se mostraran en el display 
      }else{ i=50; //caso contrario en contador regresa a 0 
        }
  }
  if(digitalRead(menos)==LOW ){//si es leido el pulsador menos
    delay(1);//hay un tiempo de espera de 1 ms
    if(i<51){//si el contador es menor a 50
      i--;//el contador se decrementa 
      decenas=i/10;//las decenas se obtienen dividiendo el contador para 10
      unidades=i-(decenas*10);//las decenas se obtienen dividiendo el contador para 10
    }else{ i=0;//caso contrario en contador regresa a 0 
      }
  }
  if (digitalRead(reset)==HIGH){
    delay(1);
    if(i<51){ 
      i=0; 
        decenas=0; //las decenas se obtienen dividiendo el contador para 10
        unidades=0; //obtencion de las unidades que se mostraran en el display 
      }
    }
  digitalWrite(unit,HIGH); //encendido del display para mostrar digitos unidades
  digitalWrite(dec,LOW);
  display(unidades);
  delay(20); //tiempo de refrescamiento 
  digitalWrite(unit,LOW);
  digitalWrite(dec,HIGH); //encendido del display mara mostrar digitos decenas
  display(decenas);
  delay(20); //tiempo de refrescamiento 
  }
    void display (int j){ //metodo que permite encender cada digito en el display 
      switch(j){
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
