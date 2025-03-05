// A test pogram to have neopixels move on user input.

#include <Adafruit_NeoPixel.h>

//Define LED Pin
#define LED_PIN  26

//Define LED Count
#define LED_COUNT 48

// //Define Touch Pin
// #define TOUCH_PIN A9

//functions declarations 
void colorIncrement(Adafruit_NeoPixel &strip, uint16_t timeInterval);

//Establish the neopixle object
Adafruit_NeoPixel TestStrip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Define LED Variables
uint8_t RGBcolor [] = {0,0,0};
uint32_t TestColorRGB = TestStrip.Color(RGBcolor[0],RGBcolor[1],RGBcolor[2]);

uint16_t LEDColorH = 100;
uint8_t LEDColorS = 100;
uint8_t LEDColorV = 0;

uint32_t LEDColorHSV = 0;
uint32_t ConvertedHSVtoRGB = 0;

//Define touch variables
uint8_t touchValue = 0;

void setup() {
  Serial.begin(115200); //establish serial port
  delay(1500);
  TestStrip.begin();
  TestStrip.setBrightness(255); //using this to have the values we input be fully deterministic
  TestStrip.clear();
  TestStrip.show();
  
  Serial.println("Setup Complete...");
  Serial.println("Starting..."); //nice confirmation that it's actually working
  delay(500);
}

void loop() {
  // while (touchRead(TOUCH_PIN) > 1800) {
  //   ConvertedHSVtoRGB = TestStrip.gamma32(TestStrip.ColorHSV(LEDColorH, LEDColorS, LEDColorV));
  //   TestStrip.fill(ConvertedHSVtoRGB);
  //   uint8_t ColorR = ConvertedHSVtoRGB >> 16;  
  //   uint8_t ColorG = ConvertedHSVtoRGB >> 8;
  //   uint8_t ColorB = ConvertedHSVtoRGB;
  //   //Serial.println((String)"LED Value is H:" + LEDColorH + " S:" + LEDColorS + " V:" + LEDColorV);
  //   Serial.println((String)"Converted RGB is:" + ConvertedHSVtoRGB + " R:" + ColorR + " G:" + ColorB + " B:" + ColorB);
  //   TestStrip.show();
  //   delay(1000);
  //   Serial.println("Great! Next!");
  //   LEDColorV++;
  // }
  colorIncrement(TestStrip, 750);

}

void colorIncrement(Adafruit_NeoPixel &strip, uint16_t timeInterval) {
  // 1. Increment Red
  for (int i = 0; i < 256; i++) {
    strip.fill(strip.Color(i, 0, 0), 0, strip.numPixels());
    strip.show();

    // Print serial feedback
    Serial.print("R=");
    Serial.print(i);
    Serial.print(", G=0, B=0  ");
    Serial.println(" (Incrementing Red)");

    delay(timeInterval);
  }
  // Go Black
  strip.fill(strip.Color(0, 0, 0), 0, strip.numPixels());
  strip.show();
  Serial.println("All pixels set to Black");
  delay(timeInterval);

  // 2. Increment Green
  for (int i = 0; i < 256; i++) {
    strip.fill(strip.Color(0, i, 0), 0, strip.numPixels());
    strip.show();

    // Print serial feedback
    Serial.print("R=0, G=");
    Serial.print(i);
    Serial.print(", B=0  ");
    Serial.println(" (Incrementing Green)");

    delay(timeInterval);
  }
  // Go Black
  strip.fill(strip.Color(0, 0, 0), 0, strip.numPixels());
  strip.show();
  Serial.println("All pixels set to Black");
  delay(timeInterval);

  // 3. Increment Blue
  for (int i = 0; i < 256; i++) {
    strip.fill(strip.Color(0, 0, i), 0, strip.numPixels());
    strip.show();

    // Print serial feedback
    Serial.print("R=0, G=0, B=");
    Serial.print(i);
    Serial.println(" (Incrementing Blue)");

    delay(timeInterval);
  }
  // Go Black
  strip.fill(strip.Color(0, 0, 0), 0, strip.numPixels());
  strip.show();
  Serial.println("All pixels set to Black");
  delay(timeInterval);

  // 4. Increment White for an RGB strip by increasing R=G=B:
  for (int i = 0; i < 256; i++) {
    // "White" on an RGB strip is full R, G, and B in equal amounts:
    strip.fill(strip.Color(i, i, i), 0, strip.numPixels());
    strip.show();

    // Print serial feedback
    Serial.print("R=");
    Serial.print(i);
    Serial.print(", G=");
    Serial.print(i);
    Serial.print(", B=");
    Serial.print(i);
    Serial.println("  (Incrementing White on RGB strip)");

    delay(5000);
  }
}
