int channel[8];
int RC_inputs = 0; 
int i;

void setup() {
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);

pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
/*
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
*/
Serial.begin(9600);

}

void loop() {
  channel[0] = pulseIn(2, HIGH);
  channel[1] = pulseIn(3, HIGH);
  channel[2] = pulseIn(4, HIGH);
  channel[3] = pulseIn(5, HIGH);
  channel[4] = pulseIn(6, HIGH);
  channel[5] = pulseIn(7, HIGH);
  channel[6] = pulseIn(8, HIGH);
  channel[7] = pulseIn(9, HIGH);


  if (channel[0] < 1300 | channel[0] < 1400 ) 
  {
    digitalWrite(10,LOW);
    Serial.println ("            Izquierda");
  }
  else 
  {
    digitalWrite(10,HIGH);
    
  }

  if (channel[0] > 1700 | channel[0] > 1800 ) 
  {
    digitalWrite(11,LOW);
    Serial.println ("            Derecha");
  }
  else 
  {
    digitalWrite(11,HIGH);
  }







     if (channel[1] < 1300 | channel[1] < 1400 ) 
  {
    digitalWrite(12,LOW);
    Serial.println ("             Abajo");
  }
  else 
  {
    digitalWrite(12,HIGH);
  }

  if (channel[1] > 1700 | channel[1] > 1800 ) 
  {
    digitalWrite(13,LOW);
    Serial.println ("             Arriba");
  }
  else 
  {
    digitalWrite(13,HIGH);
  }



/*


  if (channel[1] < 1300 | channel[0] < 1400 )
  {
    digitalWrite(10,LOW);
    Serial.println ("           Izquierda");
  }
  else 
  {
    digitalWrite(10,HIGH);
    
  }

  if (channel[1] > 1700 | channel[0] > 1800 ) 
  {
    digitalWrite(11,LOW);
    Serial.println ("          Derecha");
  }
  else 
  {
    digitalWrite(11,HIGH);
  }


*/



/*
     if (channel[6] < 1300 | channel[1] < 1400 )
  {
    digitalWrite(12,LOW);
  }
  else
  {
    digitalWrite(12,HIGH);
  }

  if (channel[6] > 1700 | channel[1] > 1800 )
  {
    digitalWrite(13,LOW);
  }
  else 
  {
    digitalWrite(13,HIGH);
  }

  */
  
  Serial.print(channel[0]);
  Serial.println(" - ");
  /*
  Serial.print(channel[1]);
  Serial.print(" - ");
  Serial.print(channel[2]);
  Serial.print(" - ");
  Serial.print(channel[3]);
  Serial.print(" - ");
  Serial.print(channel[4]);
  Serial.print(" - ");
  Serial.print(channel[5]);
  Serial.print(" - ");
  Serial.print(channel[6]);
  Serial.print(" - ");
  Serial.println(channel[7]);
  
  Serial.println("--------------------------------------------------");
  */

  


}
