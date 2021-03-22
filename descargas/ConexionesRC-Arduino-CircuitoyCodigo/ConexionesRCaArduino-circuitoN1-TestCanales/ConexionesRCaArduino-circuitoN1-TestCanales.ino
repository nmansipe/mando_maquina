/*
                              ***** YouTube: Creatividad y Reparación *****
						
					       Marzo 2019
 
                                   Como conectar emisora RC a Arduino
 
                                           Verificar canales
 
 */
 
 
// Para mostrar mejor los datos del puerto serie en el video usaré “PuTTY” en lugar del monitor serial de Arduino.
// Lo podéis ver arriba.

//---------- Esta emisora en cuestión tiene 6 canales por lo que usaremos 6 variables, una por canal.

// Declaración de variables
int valorCanal1; 
int valorCanal2;
int valorCanal3;
int valorCanal4;
int valorCanal5;
int valorCanal6;


void setup() {  // Indicamos los PINES que usaremos y como las usaremos.

  // Entradas
  pinMode(2, INPUT); // Entrada conectada al Canal 1 de la emisora
  pinMode(3, INPUT); // Entrada conectada al Canal 2 de la emisora
  pinMode(4, INPUT); // Entrada conectada al Canal 3 de la emisora
  pinMode(5, INPUT); // Entrada conectada al Canal 4 de la emisora
  pinMode(6, INPUT); // Entrada conectada al Canal 5 de la emisora
  pinMode(7, INPUT); // Entrada conectada al Canal 6 de la emisora
  
  // Salidas
  pinMode(8, OUTPUT);  // Salidas a Led que corresponde al canal 1
  pinMode(9, OUTPUT);  // Salidas a Led que corresponde al canal 2
  pinMode(10, OUTPUT); // Salidas a Led que corresponde al canal 3
  pinMode(11, OUTPUT); // Salidas a Led que corresponde al canal 4
  pinMode(12, OUTPUT); // Salidas a Led que corresponde al canal 5
  pinMode(13, OUTPUT); // Salidas a Led que corresponde al canal 6


  //-------------------  Abrimos el puerto serie y lo ponemos a 9600 bps

  Serial.begin(9600);



}

void loop() { //Bucle infinito
  
//----- La función pulseIn en Arduino puede leer pulsos de una entrada.
// ---- Leemos las entradas con pulseIn cuando el nivel es alto con un tiempo de espera de 25000ms
// ---- y guardamos el valor, los microsegundos que ha durado, en las variables.

  valorCanal1 = pulseIn(2, HIGH, 25000); 
  valorCanal2 = pulseIn(3, HIGH, 25000); 
  valorCanal3 = pulseIn(4, HIGH, 25000); 
  valorCanal4 = pulseIn(5, HIGH, 25000); 
  valorCanal5 = pulseIn(6, HIGH, 25000);
  valorCanal6 = pulseIn(7, HIGH, 25000);



  /*    Los valores suelen estar, en este caso, entre 950 ms y 1670 ms +-
        Usamos una condición "if" para que cuando el stick este en el centro NO encienda el led 
        y que cuando desplacemos el stick hacia los extremos SI lo encienda.
   
   stick Centro    (entre 1100ms y 1400ms) |-----*-----| - Led apagado   Off
   stick Izquierda (menor de 1100ms)       |*----------| - Led encendido On     
   stick Derecha   (mayor de 1400ms)       |----------*| - Led encendido On
   */


// Podréis ver como cambian los valores arriba.



// Actúa sobre el led conectado al PIN 8 (Canal 1)

  if (valorCanal1 < 1100 | valorCanal1 > 1400 ) //Si el valor es menor de 1100ms o mayor de 1400ms
  {
    digitalWrite(8,HIGH);//--------------------- entonces enciende el LED
  }
  else // -------------------------------------- si no
  {
    digitalWrite(8,LOW);// --------------------  lo apaga
  }


// Actúa sobre el led conectado al PIN 9 (Canal 2)
  if (valorCanal2 < 1100 | valorCanal2 > 1400 ) 
  {
    digitalWrite(9,HIGH);
  }
  else
  {
    digitalWrite(9,LOW);
  }


// Actúa sobre el led conectado al PIN 10 (Canal 3)
  if (valorCanal3 < 1100 | valorCanal3 > 1400 ) 
  {
    digitalWrite(10,HIGH);
  }
  else
  {
    digitalWrite(10,LOW);
  }

// Actúa sobre el led conectado al PIN 11 (Canal 4)
  if (valorCanal4 < 1100 | valorCanal4 > 1400 ) 
  {
    digitalWrite(11,HIGH);
  }
  else
  {
    digitalWrite(11,LOW);
  }


// El Canal 5 de esta emisora es un conmutador por lo que no es necesario poner una condición doble.
  
// Actúa sobre el led conectado al PIN 12 (Canal 5)
  if (valorCanal5 < 1100 ) 
  {
    digitalWrite(12,HIGH);
  }
  else
  {
    digitalWrite(12,LOW);
  }

// Actúa sobre el led conectado al PIN 13 (Canal 6)
  if (valorCanal6 < 1100 | valorCanal6 > 1400 ) 
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }


// Para mostrar mejor los datos del puerto serie en el video usaré “PuTTY” en lugar del monitor serial de Arduino.

  Serial.print(" Canal 1: ");
  Serial.println(valorCanal1);
  Serial.print(" | Canal 2: ");
  Serial.println(valorCanal2);
  Serial.print(" | Canal 3: ");
  Serial.println(valorCanal3);
  Serial.print(" | Canal 4: ");
  Serial.println(valorCanal4);
  Serial.print(" | Canal 5: ");
  Serial.println(valorCanal5);
  Serial.print(" | Canal 6: ");
  Serial.println(valorCanal6);
  Serial.print("    ");
  Serial.print('\r');
  
  delay(100);// Retardo
}
