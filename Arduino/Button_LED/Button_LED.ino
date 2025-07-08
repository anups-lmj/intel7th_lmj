/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/Button/
*/
// unsigned long 배열[10]로 루프돌았을 때의 시간저장 후 출력 
// constants won't change. They're used here to set pin numbers:
//const int buttonPin = 2;  // the number of the pushbutton pin
//const int ledPin = 13;    // the number of the LED pin
#define buttonPin 3
#define ledPin 13

// variables will change:
unsigned long arr[10];
unsigned long time;
int lastPush=0;
int buttonState = 0;  // variable for reading the pushbutton status
int buttonOld=0;
int state=0;
int cnt=0;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  time = millis();
  //Serial.println(time);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if(buttonOld != buttonState)
  {
    if(buttonState)
    {
      arr[cnt]=time-lastPush;
      
      state= !state;
      if (state == HIGH) {
        // turn LED on:
        digitalWrite(ledPin,HIGH);
      }
      else
      {
        digitalWrite(ledPin,LOW);
      }
      cnt++;
      if(cnt==10)
      {
        for(int i=0;i<10;i++)
        {
          Serial.print("arr[");
          Serial.print(i);
          Serial.print("] : ");
          Serial.println(arr[i]);
        }
      }
    }

  }
  buttonOld=buttonState;
    

}
