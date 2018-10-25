/*
 * UTN-FICA-CIERCOM
 * Puertos Salida
 * Nombre: Brayan Chandi 
 * Deber:Ejercicios- juegos con 6 leds
 * 1. Se encienden secuencialmente los leds impares (1,3,5)
 * 2. se encienden uno por uno los leds pares (0,2,4)
 * 3. Se encienden y apagan los leds de fprma aleatoria (RANDOM)
 */
 int impares[3]={9,11,13};  //vector para configurar los leds impares de salida 
 int pares [3]={8,10,12};   // vector para configurar los leds pares de la salida 
 int aleatorio[6]={8,9,10,11,12,13}; // vector para configurar todos los leds de la salida 
 int i=0; // variable de recorrido del vector 
 int l=0; // variable para generar numeros aleatorios 
void setup() {
  
  //configuracion de pines impares de forma grupal 
 for(;i<3;i++){
     pinMode(impares[i],OUTPUT);
    }
    i=0; // reseteo de variable de conteo 
    //configuracion de pines pares de forma grupal 
 for(;i<3;i++){
     pinMode(pares[i],OUTPUT);
    }
    i=0; // reseteo de variable de conteo 
    //configuracion de pines aleatorios
 for(;i<6;i++){
     pinMode(aleatorio[i],OUTPUT); // pines a recorrer, los especificados en el array aleaorio
     digitalWrite(aleatorio[i],LOW); // el punto de partida es que todos los leds esten apagados 
     randomSeed(analogRead(0)); // generacion de un valor aleatorio en cada repeticion -- 0 es el valor de un pin que no se esta utilizando 
    }
  
    i=0; // reseteo de variable de conteo 
}

void loop() {
  // programacion de cada ejercicio
  // ejercicio 1: se encienden secuencialmente los leds impares

 for(;i<3;i++){  // se encienden secuencialmete los leds que se encuentran en las pocisiones impares
    digitalWrite (impares[i],HIGH);
    delay(200); 
    }
    i=0; 
    for(;i<3;i++){
    digitalWrite (impares[i],LOW); // se apagan secuencialmente los leds que se encuantran en las posiciones impares 
    delay(200); 
    }
    i=0; 
     for(;i<3;i++){ // se encienden y se apagn uno por uno los leds que se encuentran en las posiciones pares 
    digitalWrite (pares[i],HIGH);
    delay(200); 
    digitalWrite (pares[i],LOW);
    delay(200); 
    }
    i=0; 
    l=random(7); // se encienden aleatoriamente leds entre 0-6
    for(i=0;i<l;i++){
      digitalWrite(aleatorio[i],HIGH);}
      delay (200);
      for(i=0;i<l;i++){
       digitalWrite(aleatorio[i],LOW);}
       delay (200); 
   i=0; 
   

}
