#define motorPin 9
#define BUTTON_OFF 0
#define BUTTON1_ON 1
#define BUTTON2_ON 2
const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
int PWM=0;
volatile int buttonState;
void setup() {
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
  pinMode(BUTTON_1_PIN,INPUT);
  pinMode(BUTTON_2_PIN,INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Isr, RISING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Isr, RISING);
  Serial.println("Start setup!!");
}

void loop() {

  if(buttonState != BUTTON_OFF)
  {
   if(buttonState == BUTTON1_ON)
   {
     if(PWM<250)
     {
       PWM+=25;
     }
   }
   else if(buttonState==BUTTON2_ON)
   {
     if(PWM>0)
     {
       PWM-=25;
     }
   }
   analogWrite(motorPin,PWM);
   Serial.println(PWM);
   buttonState=BUTTON_OFF;
  }
}
void button1Isr()
{
  buttonState = BUTTON1_ON;
}
void button2Isr()
{
  buttonState=BUTTON2_ON;
}
