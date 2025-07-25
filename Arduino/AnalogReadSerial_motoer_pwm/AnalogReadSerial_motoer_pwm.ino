/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/
*/
#define motorPin 9
int sensorValueOld;
int pwm;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  if(abs(sensorValue - sensorValueOld)>10)
  {
    Serial.print(sensorValue);
    Serial.print(" V : ");
    Serial.print(5/1024.0 * sensorValue,4);
    pwm = map(sensorValue,0,1023,0,255);
    analogWrite(motorPin,pwm);
    Serial.print(" pwm : ");
    Serial.println(pwm);
    sensorValueOld=sensorValue;
  }
}
