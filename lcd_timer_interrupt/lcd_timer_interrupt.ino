#include <MsTimer2.h>
#include <DS1302.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <stdio.h>

LiquidCrystal_I2C lcd(0x27,16,2);
// DS1302 용 pin 설정
DS1302 rtc(4, 5, 6);
Time t;
// char date[11];
// char dow[5];
// char time[11];
char buf[16];
int state=0;
void setup()
{
  rtc.halt(false); // 동작 모드로 설정
  rtc.writeProtect(false); // 시간 변경이 가능하도록 설정
  Serial.begin(115200); // 시리얼 통신 초기화
  rtc.setDOW(FRIDAY); // SUNDAY 로 설정
  rtc.setTime(18, 00, 00); // 시간을 12:00:00로 설정 (24시간 형식)
  rtc.setDate(16, 5, 2025); // 2015년 8월 16일로 설정
  lcd.clear();
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();

  MsTimer2::set(1000,get_time);
  MsTimer2::start();
}

void loop() {
  if(state)
  {
    lcd.setCursor(1,0);
    t = rtc.getTime();
    sprintf(buf,"%s",rtc.getDateStr());
    lcd.print(buf);
  
    lcd.setCursor(1,1);
    sprintf(buf,"%s",rtc.getTimeStr());
    lcd.print(buf);
  
    lcd.setCursor(10,1);
    sprintf(buf,"%s",rtc.getDOWStr());
    for(int i=0;i<3;i++) lcd.print(buf[i]);
    state=false;
  }

}

void get_time() {
  state = true;
  
}