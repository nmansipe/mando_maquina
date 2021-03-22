/*
                              ***** YouTube: Creatividad y Reparación *****
						
					       Marzo 2019
              
                                   Como conectar emisora RC a Arduino

                                    Movimiento de led's segun stick


 */
 
// Para mostrar mejor los datos del puerto serie en el video usaré “PuTTY” en lugar del monitor serial de Arduino.
// Lo podéis ver arriba.


// --------------------- Variable que guardara el valor del canal 4 del RX RC conectado al PIN 2 de Arduino
int valorCanal4;



void setup() { // Indicamos los PINES que usaremos y como las usaremos.
  
  
  // Entrada
  pinMode(2, INPUT);
  
  
  
  // Salidas, PINES del 3 al 13 donde irán conectados los LED's
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  

  //-------------------  Abrimos el puerto serie y lo ponemos a 9600 bps
  Serial.begin(9600);

}

void loop() { //Bucle infinito
  
  //----------- La función pulseIn puede leer pulsos de una entrada.
  //----------- Esta linea,lee la entrada digital 2 de Arduino, donde hemos conectado el canal 4 del receptor RC
  //----------- y guarda en la variable valorCanal4 los microsegundos que ha durado el pulso.
  //----- NOTA: La duración del pulso depende, en este caso, de la posicion del stick de la emisora.
 //------ Si el stick esta a la izquierda tendra menor logitud de pulso por lo que el valor sera menor
 //------ Mientras que si el stick esta a la derecha la longitud del pulso sera mayor.

 //                stick a la izquierda                       stick a la derecha
 //            __  Pulso de unos 950 ms +-      ___________   Pulso de unos 1670 ms +-
 //           |  |                             |           |
 //___________|  |_____________________________|           |________________________
 //
 //
  
  valorCanal4 = pulseIn(2, HIGH, 25000); // Lee la entrada 

   
  
  
  
  //Como el valor guardado en valorCanal4 depende de la posicion del stick,podremos usar esto para delimitar rangos.
  
                           
  if (valorCanal4 < 1015 ) // Enciende el led colocado de la salidad 3 de Arduino si el valor es menor de 1015ms.
  {
  digitalWrite(3,HIGH);// stick |*----------| Izquierda
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
  else if(valorCanal4 < 1083) // Enciende el led colocado de la salidad 4 de Arduino si el valor es menor de 1080ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);// stick |-*---------|
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
  else if(valorCanal4 < 1151) // Enciende el led colocado de la salidad 5 de Arduino si el valor es menor de 1145ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);// stick |--*--------|
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
   else if(valorCanal4 < 1219) // Enciende el led colocado de la salidad 6 de Arduino si el valor es menor de 1210ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);// stick |---*-------|
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
  else if(valorCanal4 < 1287) // Enciende el led colocado de la salidad 7 de Arduino si el valor es menor de 1275ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);// stick |----*------|
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
  else if(valorCanal4 < 1355) // Enciende el led colocado de la salidad 8 de Arduino si el valor es menor de 1340ms. Centro
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);// stick |-----*-----| Centro
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                          
  else if(valorCanal4 < 1423) // Enciende el led colocado de la salidad 9 de Arduino si el valor es menor de 1405ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH); // stick |------*----|
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                          
  else if(valorCanal4 < 1491) // Enciende el led colocado de la salidad 10 de Arduino si el valor es menor de 1470ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH); // stick |-------*---|
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
  else if(valorCanal4 < 1559) // Enciende el led colocado de la salidad 11 de Arduino si el valor es menor de 1535ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);// stick |--------*--|
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }                           
   else if(valorCanal4 < 1627) // Enciende el led colocado de la salidad 12 de Arduino si el valor es menor de 1600ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);// stick |---------*-|
  digitalWrite(13,LOW);
  }                           
  else if(valorCanal4 < 1700) // Enciende el led colocado de la salidad 13 de Arduino si el valor es menor de 1670ms.
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);// stick |----------*| Derecha
  }
    
   
  Serial.print("Canal 4:"); // Mostramos los valores en el monitor serie
  Serial.print(valorCanal4);
  Serial.print("    ");
  Serial.print('\r');

}
