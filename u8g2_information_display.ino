/* Information display the displays (Time and Date, Temp and humidty)
using a DHT11 Connected to the pin defined in line 20 ,and a DS1307 RTC connected to your i2c pins, a 128x64 display supported by u8g2 defined in line 16 and 17
 and dont forget to change the pins accoarding to your board, the pins i wrote are for the esp8266 NodeMcu */

#include <RTClib.h>

#include <TimeLib.h>

#include <Arduino.h>
#include <U8g2lib.h>


#include <Wire.h>
static const char daysOfTheWeek[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, D5, D7, D8, D3);
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN D4
RTC_DS1307 rtc;
void setup(void) {
//
rtc.begin();
  u8g2.begin();  
}

void loop(void) {
    tmElements_t tm;
   DateTime now = rtc.now();
  DHT.read(DHT11_PIN);
  u8g2.firstPage();
  do {
 u8g2.setFont(u8g2_font_littlemissloudonbold_tr);
 u8g2.setCursor(0,10);
 u8g2.print("Date:");
 u8g2.setCursor(50,10);
 u8g2.print(daysOfTheWeek[now.dayOfTheWeek()]);

  u8g2.setCursor(0,20);
 u8g2.print("           /     /");
   u8g2.setCursor(12,20);
 u8g2.print(now.year(), DEC);
 u8g2.setCursor(67,20);
  u8g2.print(now.month(), DEC);
   u8g2.setCursor(103,20);
    u8g2.print(now.day(), DEC);
  u8g2.setCursor(0,30);
 u8g2.print("Time:");
  u8g2.setCursor(0,40);
 u8g2.print("     :     :");
 u8g2.setCursor(5,40);
 u8g2.print(now.twelveHour(), DEC);
 u8g2.setCursor(34,40);
  u8g2.print(now.minute(), DEC);
   u8g2.setCursor(60,40);
     u8g2.print(now.second(), DEC);
u8g2.setCursor(85,40);
if (now.isPM() == true){
  u8g2.print("PM");
}
else{
  u8g2.print("AM");
}
   u8g2.setCursor(0,50);
 u8g2.print("Temperature:     C");
  u8g2.setCursor(102,50);
  u8g2.print(DHT.temperature);
    u8g2.setCursor(0,60);
 u8g2.print("Humidity:      %");
 u8g2.setCursor(71,60);
 u8g2.print(DHT.humidity);


  } while ( u8g2.nextPage() );

}

