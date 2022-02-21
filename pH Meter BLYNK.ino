#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define SensorPin A0  
unsigned long int avgValue;  
float b, pH;
int buf[10],temp;

char auth[] = "fLLrUS-oh7u0oXoNwUyJ0S6W3i_pxG6r";
char ssid[] = "Tunas Pontianak";
char pass[] = "1234567890";

BlynkTimer timer;

void sendData() {

  for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //take the average value of 6 center sample
  avgValue+=buf[i];
  float X=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
  pH=-7.500*X + 40.53; //Kalibrasi kabel 70cm
  //pH=9.8; //Kalibrasi kabel 700cm
  Serial.print("pH:");  
  Serial.print(pH,2);
  Serial.print(" V:");  
  Serial.print(X,2);
  Serial.println(" ");  
  Blynk.virtualWrite(V0, pH);
  Blynk.virtualWrite(V1, X);
  if (pH >= 9)
  {
  lcd.setCursor(0,0);
  lcd.print("PH -> ");
  lcd.print(pH, 1);
  lcd.setCursor(0,1);
  lcd.print("      (HIGH)"); 
  }
  else if (pH <= 6)
  {
  lcd.setCursor(0,0);
  lcd.print("PH -> ");
  lcd.print(pH, 1);
  lcd.setCursor(0,1);
  lcd.print("      (LOW)"); 
  }
  else {
  lcd.setCursor(0,0);
  lcd.print("PH -> ");
  lcd.print(pH, 1);
  lcd.setCursor(0,1);
  lcd.print("    (NORMAL)"); 
  }
 }

void setup()
{
  // Debug console
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  lcd.setCursor(0,1);
  lcd.print("-> ");
  lcd.print("Connecting...");
  }
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("-> ");
  lcd.print("Connected");
  delay(3000);
  lcd.clear();
  // Setup a function to be called every second
  timer.setInterval(1000L, sendData);
}

void loop()
{
  Blynk.run();
  timer.run();
}
