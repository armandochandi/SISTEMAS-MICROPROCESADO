/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: Brayan Chandi
 * PUERTOS DE SALIDA-MULTIPLEXACION
 * DEBER:CONTADOR DEL 1 AL 200 DE INICIO AUTOMATICO SIN NINGUNA ACTIVIDAD DE USUARIO 
 * 
 */
int A=5; // declaracion de pin de salida para entrada A del ci 7447
int B=4; // declaracion de pin de salida para entrada B del ci 7447
int C=3; // declaracion de pin de salida para entrada C del ci 7447
int D=2; // declaracion de pin de salida para entrada D del ci 7447
int unit=8; // pin que enviara la señal para accionar el display que muestra unidades
int dec=9;  // pin que enviara la señal para accionar el display que muestra decenas
int cen=10; // pin que enviara la señal para accionar el display que muestra centenas
int i=1;    //tiempo de refrescamiento de displays
int k=0;    // variable de conteo para el refrescamiento de displays 
int cont1=0;  //nombre del menu que especifica los numeros del 0-2,  que inicializa el display centenas
int cont2=0;  //nombre del menu que especifica los numeros 0-9 que inicializa el display decenas
int cont3=0;  // nombre del menu que especifica los numeros 0-9 que inicializa el display unidades
void setup() {
  pinMode(A,OUTPUT); //declaracion de pin de salida para entrada A del ci 7447
  pinMode(B,OUTPUT); //declaracion de pin de salida para entrada B del ci 7447
  pinMode(C,OUTPUT); //declaracion de pin de salida para entrada C del ci 7447
  pinMode(D,OUTPUT); //declaracion de pin de salida para entrada D del ci 7447
  pinMode(unit,OUTPUT); //pin de salida que controlara el display unidades
  pinMode(dec,OUTPUT);  //pin de salida que controlara el display decenas
  pinMode(cen,OUTPUT);  //pin de salida que controlara el display centenas
}void cero(){  // metodo para mostrar en el display el numero cero a partir de las entradas del ci 7447
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
    }void uno(){ // metodo para mostrar en el display el numero uno a partir de las entradas del ci 7447
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
      }void dos(){ // metodo para mostrar en el display el numero dos a partir de las entradas del ci 7447
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);    
    }
void tres(){  // metodo para mostrar en el display el numero tres a partir de las entradas del ci 7447
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);      
      }
 void cuatro(){  // metodo para mostrar en el display el numero cuatro a partir de las entradas del ci 7447
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);  
  }
void cinco(){  // metodo para mostrar en el display el numero cinco a partir de las entradas del ci 7447
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);  
  }
void seis(){   // metodo para mostrar en el display el numero seis a partir de las entradas del ci 7447
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);  
  }
void siete(){  // metodo para mostrar en el display el numero siete a partir de las entradas del ci 7447
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);  
  }
void ocho(){   // metodo para mostrar en el display el numero ocho a partir de las entradas del ci 7447
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);  
  }
void nueve(){  // metodo para mostrar en el display el numero nueve a partir de las entradas del ci 7447
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH); 
  }
void display3(){ //metodo para permitir encender el display unidades
  switch (cont3){ //variable contador unidades inicia en 0
    case 0:
    cero(); //en cada case se llama al metodo que permite proyectar el numero en el display
    break;
    case 1:
    uno();
    break;
    case 2:
    dos();
    break;
    case 3:
    tres();
    break;
    case 4:
    cuatro();
    break;
    case 5:
    cinco();
    break;
    case 6:
    seis();
    break;
    case 7:
    siete();
    break;
    case 8:
    ocho();
    break;
    case 9:
    nueve();
    break;
    }
  }
  void display2(){ //metodo para permitir encender el display decenas
  switch (cont2){ //variable contador decenas inicia en 0
    case 0:
    cero(); //en cada case se llama al metodo que permite proyectar el numero en el display
    break;
    case 1:
    uno();
    break;
    case 2:
    dos();
    break;
    case 3:
    tres();
    break;
    case 4:
    cuatro();
    break;
    case 5:
    cinco();
    break;
    case 6:
    seis();
    break;
    case 7:
    siete();
    break;
    case 8:
    ocho();
    break;
    case 9:
    nueve();
    break;
    }
  }
  void display1(){ //metodo para permitir encender el display centenas
  switch (cont1){ //variable contador centenas inicia en 0
    case 0:
    cero(); //en cada case se llama al metodo que permite proyectar el numero en el display
    break;
    case 1:
    uno();
    break;
    case 2:
    dos();
    break;
    case 3:
    tres();
    break;
    case 4:
    cuatro();
    break;
    case 5:
    cinco();
    break;
    case 6:
    seis();
    break;
    case 7:
    siete();
    break;
    case 8:
    ocho();
    break;
    case 9:
    nueve();
    break;
    }
  }

  void cifra(){ //metodo que especifica los valores para que cada display este encendido
    switch(k){ // variable para que los displys esten encendidos, se inicializa en 0 
      case 0:
      display3(); // case 0, se muetran los respecticos valores para que se encienda el display unidades, el pulso es enviado desde el pin declarado como salida
      digitalWrite(unit,HIGH); //display unidades encendido
      digitalWrite(dec,LOW);  //display decenas apagado
      digitalWrite(cen,LOW);  //display centenas apagado
      break;
         case 1:
      display2(); // case 1, se muetran los respecticos valores para que se encienda el display decenas, el pulso es enviado desde el pin declarado como salida
      digitalWrite(unit,LOW); //display unidades apagado
      digitalWrite(dec,HIGH); //display decenas encendido
      digitalWrite(cen,LOW);  //display centenas apagado
      break;
         case 2:
      display1(); // case 2, se muetran los respecticos valores para que se encienda el display centenas, el pulso es enviado desde el pin declarado como salida
      digitalWrite(unit,LOW); //display unidades apagado
      digitalWrite(dec,LOW);  //display decenas apagado
      digitalWrite(cen,HIGH); //display centenas apagado 
      break;
      }
    }

void loop() { // funciones para los metodos antes creados 
   /*for(;cont3>9;cont3++){ // metodo alternativo 
    cont3=0;
    cont2++;
    for(;cont2>9;cont2++){
    cont2=0;
    cont1++;
      for(;cont1>1;cont1++){
        cont1=0;
      }
      }
    }*/           
   if(cont3>9){ //si la variable cont3(unidades) es mayor a 9
    cont3=0;    //el cont3(unidades) vueve a 0
    cont2++;    //en cont2(decenas) comienza a incrementar su conteo
    if(cont2>9){ //si la variable cont2(decenas) es mayor a 9
      cont2=0;  //en cont2(decenas) vuelve a 0
      cont1++;  //en cont1(centenas) comienza a incrementar su conteo
      if(cont1>=2){ //si la variable cont1(centenas) es mayor a 1
        cont1=0; //en cont1(centenas) vuelve a 0
        }
      }
    }
  cont3++; //el cont3(unidades) comienza a incrementar y vuelve a ejecutarse el conteo de 1 a 200
for(k=0;k<=2;k++){ // ciclo for creado con la variable k responsable de que los displays esten encendidos, se ejecuta hasta 2 por las posiciones (3 displays)
     cifra(); //llama al metodo cifra esponsable de encender los displays
     delay(200);//tiempo de refresco entre displays de 7 segmentos 
     }
  }
