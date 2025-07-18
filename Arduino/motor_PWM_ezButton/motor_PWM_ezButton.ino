#include <ezButton.h>
#define motor 9
const int BUTTON_NUM = 2;
const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
int PWM=0;
ezButton buttonArray[] = {
  ezButton(BUTTON_1_PIN),
  ezButton(BUTTON_2_PIN),
};
void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  for (byte i = 0; i < BUTTON_NUM; i++) {
    buttonArray[i].setDebounceTime(50); // set debounce time to 50 milliseconds
  }
}

void loop() {
 for (byte i = 0; i < BUTTON_NUM; i++)
    buttonArray[i].loop(); // MUST call the loop() function first

  if(buttonArray[0].isPressed())
  {
    if(PWM<250)
    {
      PWM+=25;
      analogWrite(motor,PWM);
      Serial.println(PWM);
    }
  }
  else if(buttonArray[1].isPressed())
  {
    if(PWM>0)
    {
      PWM-=25;
      analogWrite(motor,PWM);
      Serial.println(PWM);
    }
  }


 /* for (byte i = 0; i < BUTTON_NUM; i++) {
    if (buttonArray[i].isPressed()) {

      //Serial.print("The button ");
      //Serial.print(i + 1);
      //Serial.println(" is pressed");
    }

    if (buttonArray[i].isReleased()) {
      Serial.print("The button ");
      Serial.print(i + 1);
      Serial.println(" is released");
    }
  }*/
}
