#include <Adafruit_I2CDevice.h>
#include <FS.h>
#include "SPIFFS.h" 
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

//====================================================================

void setup(void) {
  Serial.begin(115200);
  Serial.println("\n\nStarting...");

  tft.init();
  tft.drawCentreString("You ain't toched nothing!", 150, 30, 4);

}

//====================================================================

void loop() {
  uint16_t x, y;
  tft.getTouchRaw(&x, &y);
  Serial.printf("x: %i     ", x);
  Serial.printf("y: %i     ", y);
  Serial.printf("z: %i \n", tft.getTouchRawZ());

  if (tft.getTouchRawZ() > 100){
    tft.fillScreen(TFT_BLACK); // Clear the screen
    tft.drawCentreString("x: %i", 100, 30, 4);
    tft.drawCentreString("I've been touched!!! %i", 150, 30, 4);
  }

  delay(250);
}

//===================================================================