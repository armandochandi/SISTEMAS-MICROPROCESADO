/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: Chandi Brayan
 * Realizar un reloj dentro del arduino con el menor coste computacional 
 * que se visualiza en una LCD (apagar los periféricos que no se usen).
 */
#include <LiquidCrystal.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <MsTimer2.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //RS-E-D4-D5-D6-D7
 int seg=0, minut=0, hor=0;
void setup() {
  lcd.begin(16, 2);
  MsTimer2::set(500,reloj); //interrupcion del timer,entervalo en el que se va a ejecutar 
  MsTimer2::start();
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
  delay(200);
  set_sleep_mode(SLEEP_MODE_IDLE); //modo sleep
  sleep_enable();
  sleep_mode();  
}

void loop() {
power_twi_disable(); //deshabilitar el modulo de interfaz de 2 cables
power_timer0_disable(); //deshabilitar el timer 0
power_timer1_disable(); //deshabilitar el timer 1
power_adc_disable(); // deshabilitar el modulo conversor de analogo a digital
power_spi_disable(); //deshabilitar el modulo de interfaz periferica en serie
power_usart0_disable(); //deshabilitar el modulo usart0
}
void reloj() {
  seg++; //incremento de segundos, variable inicial
  if (seg < 10) { //si segundos es menor a 10
    lcd.setCursor(7, 0); //se muestra el conteo en la columna 7 de la fila 0
    lcd.print(seg); //se imprime el valor del conteo
    lcd.setCursor(6, 0); //en la columna 6 y fila 0
    lcd.print('0'); //se imprime cero
  } else { //caso contrario los valores
    lcd.setCursor(6, 0); //se imprimen en la columna 6 fila 0
    lcd.print(seg);
  } //valores que tiene el conteo de segundos
  if (seg == 60) { //si el conteo de la variable seg llega a 60
    seg = 0; //la variable seg vuelve a ser 0 y se reinicia el conteo
    lcd.setCursor(6, 0); //en la columna 6 fila 0
    lcd.print(seg); //se vuelve a imprimir los valores dela variable seg
    seg++; //incrementos de valores en la variable
    minut++; //la variable minut empieza su incremento
    if (minut < 10) { //si minut es menor que 10
      lcd.setCursor(4, 0); //el cursor se ubica en la columna 4 fila 0
      lcd.print(minut); //se imprime el valor dela variable minut
      lcd.setCursor(3, 0); // y en la posicion columna 3 fila 0
      lcd.print('0');
    }// se imprime 0
    else { //caso contrario
      lcd.setCursor(3, 0); //en la posicion columna 3 fila 0
      lcd.print(minut); //se imprime el valor de conteo de la variable minut
    }
    if (minut == 60) { //si minut llega a 60
      minut = 0; //minut toma el valor de 0
      lcd.setCursor(4, 0); //el cursor en la posicion columna 4 fila 0
      lcd.print(minut); //se imprime el valor de la variable minut
      lcd.setCursor(3, 0); //el cursor esta en la posicion columna 3 fila 0
      lcd.print('0');  //se imprime el valor de 0
      hor++; //se incrementa la variable hor
      lcd.setCursor(0, 0); //cursor se ubica en la columna 0 fila 0
      lcd.print('0'); //se imprime el valor 0
      lcd.setCursor(1, 0); //en la columna 1 fila 0
      lcd.print('0'); // se imprime el valor 0
      if (hor < 10) { // si hor es menor a 10
        lcd.setCursor(1, 0); //en la columna 1 fila 0
        lcd.print(hor); // se imprime el valor de hor
        lcd.setCursor(0, 0); //en la columna 0 fila 0
        lcd.print('0'); //se imprime el valor 0
      } else { //caso contrario
        lcd.setCursor(0, 0); //en la columna 0 de la fila 0
        lcd.print(hor); //se imprime el valor de la variable hor
      }
    }
    if (seg == 60 && minut == 60 && hor == 24) { //si hora,minutos y segundos llegan a sus limites
      hor = 0;
      minut = 0; //las variables se reestablecen a 0
      hor = 0;
      lcd.setCursor(1, 0); // y se repite el ciclo
      lcd.print(hor);
      lcd.setCursor(4, 0);
      lcd.print(minut);
      lcd.setCursor(7, 0);
      lcd.print(seg);
      lcd.setCursor(0, 0);
      lcd.print('0');
      lcd.setCursor(3, 0);
      lcd.print('0');
      lcd.setCursor(6, 0);
      lcd.print('0');
    }
  }
}
