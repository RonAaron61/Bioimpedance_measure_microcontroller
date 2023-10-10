  /*
  AD9833
  clk = 13
  dat = 11
*/
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <AD9833.h>     // Include the library

Adafruit_ADS1115 ads;

#define FNC_PIN 10       // Can be any digital IO pin
#define Frequency 50000  // Frequency = 1Hz

//--------------- Create an AD9833 object ----------------
// Note, SCK and MOSI must be connected to CLK and DAT pins on the AD9833 for SPI
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency


float Voltage0;
int16_t adc0;  // we read from the ADC, we have a sixteen bit integer as a result
float Voltage1;
int16_t adc1;  // we read from the ADC, we have a sixteen bit integer as a result
float z = 0.0;

void setup() {
  Serial.begin(9600);
  
  // This MUST be the first command after declaring the AD9833 object
  gen.Begin();
  gen.ApplySignal(SINE_WAVE, REG0, Frequency);

  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
  // There should be a 1 Hz square wave on the output of the AD9833

  // AD1115
  ads.setGain(GAIN_ONE);
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

void loop() {
  adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = ads.computeVolts(adc0);
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = ads.computeVolts(adc1);

  z = (Voltage1*215)/Voltage0;

  Serial.print("Voltage 0: ");
  Serial.print(Voltage0, 4);  
  Serial.println();
  Serial.print("Voltage 1: ");
  Serial.print(Voltage1, 4);
  Serial.println();
  Serial.print("Z: ");
  Serial.print(z);
  Serial.println();
  Serial.println();

  delay(100);
}
