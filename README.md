# Bioimpedance_measure_microcontroller
Measuring bioimpedance using microcontroller

A tool for measuring a person's bioimpedance, using a microcontroller as a signal processor and reader of measurement results, and displays it. The device that is made consists of a signal generator that uses a Wien bridge oscillator circuit to produce a 33 kHz sine wave signal, then VCCS to convert the input voltage into a current source so that it is safe when it enters the body, then the signal is read using an instrument amplifier as an amplifier so that it is easy to read , and converted to a DC signal for reading

## Schematic

(Image)

## Components

### Positive to Negative Voltage Converter

Because all the IC that I use need dual rail supply (positive and negative) we need to change from positive input to positive and negative. First I try using LM2662 Module and get the negative supply, but when I try to connect it to the IC, the result signal is not stable with changing offset. So I try using another method which is using a voltage divider with buffer on the ground. 

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/099e97ca-ae0e-40f3-856f-7e93da516763)
[Source](https://electronoobs.com/eng_circuitos_tut82.php)

The function of using a buffer on the ground is to make sure both positive and negative supply is the same voltage even when there is load (IC)


### Wein's Bridge Oscillator

To create the sine wave signal I use Wein's bridge oscillator consisting of Op-amp IC with resistor and capacitor. The schematic of Wein's bridge oscillator is like the above image.

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/8a3f1093-d8c6-4f04-a31c-431f6ff70b5d)
[Source](https://www.electronics-tutorials.ws/oscillator/wien_bridge.html)

With:

F = 1/2πRC 

Beacuse I use 1 nF with 4.7kΩ so I should get around 33.86 kHz, and based on the reading of the oscilloscope (I used Analog Discovery 2) get similar results which are 33.55 kHz

![33k wein bridge](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/7e5e3506-c464-414a-a9db-cca1e0fca692)

And also the voltage gain of the amplifier circuit MUST be equal too or greater than three “Gain = 3” for oscillations to start. Because the input is 1/3 of the output, so R1 and R2 and for a non-inverting amplifier need to be 2/3, this is given as the ratio 1+(R1/R2).


### VCCS

The function of VCCS is to get current sources that can be controlled using the input voltage, so the current doesn't exceed some limit. The VCCS that I used is a basic Howland Circuit that consists of 4 resistors and an Op-amp. 

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/3201c667-718c-4ebc-8fc2-7bc18fc961b7)

With 500mV input I get a current of around 0.3 mA, with the highest current is 0.5 mA, which is above 1 mA so it safe for human body

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/984e8c8e-4b56-4b08-b842-a6e99724385e)


### Instrument amplifier


### AC to DC converter


## Results


### Using Resistor


### Human body

