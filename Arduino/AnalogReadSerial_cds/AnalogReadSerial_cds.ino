#define LED 2
bool flag;
int cds_state;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  
  int sensorValue = analogRead(A1);
  if(sensorValue<780 && !cds_state)
  {


      Serial.print("sensorValue : ");
      Serial.print(sensorValue);
      Serial.println(" LED : ON");
      digitalWrite(LED,HIGH);

    cds_state=true;
  }
  else if(sensorValue >=780 && cds_state)
  {
    

      Serial.print("sensorValue : ");
      Serial.print(sensorValue);
      Serial.println(" LED : OFF");
      digitalWrite(LED,LOW);

    cds_state=false;
  }
  delay(10);
  

}