
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht.h>
#define dht_apin A0 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
dht DHT;
void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  /*display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("    A Project By");
   display.setTextSize(2);
  display.println("ElectroBoY");
  display.display(); 
  delay(3000); */
 
}

void loop() {

  int a,b = 0;
   
  DHT.read11(dht_apin);
  a = DHT.humidity;
  b = DHT.temperature;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);      //discuss impotant
    display.print("\thumidity   ");
    display.setTextSize(2);
    display.print(a);
    display.println("%  ");
    display.setTextSize(1);
  //  display.print("\n");
    display.print("\ttemp   ");
    display.setTextSize(2);
    display.print(b); 
    display.println(" C  ");
    display.display();  
    delay(2000);

  
  }
  
