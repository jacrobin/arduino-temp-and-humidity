#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTTYPE    DHT11     // DHT 11
#define DHTPIN 3
DHT_Unified dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(5, HIGH);
  dht.begin();
  sensor_t sensor;
  // initialize the lcd 
  lcd.init();  
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Starting Sensor");
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Readings");
  delay(1000);
  digitalWrite(5, HIGH);
  delay(300);
  digitalWrite(5, LOW);
  delay(300);
  digitalWrite(5, HIGH);
  delay(300);
  lcd.init();
}

void loop()
{
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(300);
  digitalWrite(4, LOW);
  delay(300);
  digitalWrite(4, HIGH);

  //Get Temp and print it
  sensors_event_t event;
  lcd.backlight();
  dht.temperature().getEvent(&event);
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(5,0);
  lcd.print(1.8*event.temperature+32);
  lcd.setCursor(11,0);
  lcd.print((char)223);
  lcd.setCursor(12,0);
  lcd.print("F");

  //Get humidity  and print it
  dht.humidity().getEvent(&event);
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.setCursor(9,1);
  lcd.print(event.relative_humidity);
  lcd.setCursor(15,1);
  lcd.print("%");
}
