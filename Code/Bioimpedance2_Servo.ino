  /*
  AD9833
  clk = 13
  dat = 11
*/
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <AD9833.h>     // Include the library
#include <Servo.h>

Servo myservo;

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

float up = 0;
float down = 0;
int servo = 0;

void setup() {
  Serial.begin(9600);

  myservo.attach(9, 500, 2400);
  
  // This MUST be the first command after declaring the AD9833 object
  gen.Begin();
  gen.ApplySignal(SINE_WAVE, REG0, Frequency);

  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF

  // AD1115
  ads.setGain(GAIN_ONE);
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }

  calibrate();
  delay(1000);
}

void loop() {
  adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = ads.computeVolts(adc0);
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = ads.computeVolts(adc1);

  z = (Voltage1*215)/Voltage0;
  servo = map(z, down, up, 45, 180);

  myservo.write(servo);

  //Serial.println(z);
  //Serial.println(down);
  //Serial.println(up);
  delay(100);
}

void calibrate() {
  //posisi tangan lurus
  //Serial.println("Tangan lurus");
  myservo.write(180);
  delay(2000);
  for (int i=0;i<50;i++){
    adc0 = ads.readADC_SingleEnded(0);
    Voltage0 = ads.computeVolts(adc0);
    adc1 = ads.readADC_SingleEnded(1);
    Voltage1 = ads.computeVolts(adc1);
    z = (Voltage1*215)/Voltage0;

    up += z;
  }
  up = up/50;
  
  //Serial.println("Tangan nekuk");
  myservo.write(45);
  delay(2000);
  // Posisi tangan nekuk
  for (int i=0;i<50;i++){
    adc0 = ads.readADC_SingleEnded(0);
    Voltage0 = ads.computeVolts(adc0);
    adc1 = ads.readADC_SingleEnded(1);
    Voltage1 = ads.computeVolts(adc1);
    z = (Voltage1*215)/Voltage0;

    down += z;
  }
  down = down/50;
}
