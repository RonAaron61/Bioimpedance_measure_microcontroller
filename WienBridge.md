# Bioimpedance_measure_microcontroller
Measuring bioimpedance using a microcontroller

*Note: this project is not done

A tool for measuring a person's bioimpedance, using a microcontroller as a signal processor and reader of measurement results, and displays it. The device that is made consists of a signal generator that uses a Wien bridge oscillator circuit to produce a 33 kHz sine wave signal, then VCCS to convert the input voltage into a current source so that it is safe when it enters the body, then the signal is read using an instrument amplifier as an amplifier so that it is easy to read, and converted to a DC signal for reading


---

### List of content

- [Schematic](#schematic)
- [Components](#components)
- [Poisitve to negative voltage](#Positive-toNegative-Voltage-Converter)
- [Wein's Bridge Oscillator](#Wein's-Bridge-Oscillator)
- [VCCS](#VCCS)
- [Instrument Amplifier](#Instrument-Amplifier)
- [AC tp DC](#AC-to-DC-converter)
- [Results](#Results)

## Schematic 

![Schematic_Bioimpedance_2023-10-07](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/cb31a872-894d-475b-b052-1f7df286cc38)


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

And also the voltage gain of the amplifier circuit MUST be equal too or greater than three “Gain = 3” for oscillations to start. Because the input is 1/3 of the output, so R1 and R2 and for a non-inverting amplifier need to be 2/3, this is given as the ratio 1+(R1/R2).

I also add a voltage divider to lower the amplitude, and add buffer,

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/6222594d-0f26-4aa0-a34c-f740887dece3)

Beacuse I use 1 nF with 4.7kΩ so I should get around 33.86 kHz, and based on the reading of the oscilloscope (I used Analog Discovery 2) get similar results which are 33.55 kHz

![33k wein bridge](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/7e5e3506-c464-414a-a9db-cca1e0fca692)



### VCCS

The function of VCCS is to get current sources that can be controlled using the input voltage, so the current doesn't exceed some limit. The VCCS that I used is a basic Howland Circuit that consists of 4 resistors and an Op-amp. 

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/3201c667-718c-4ebc-8fc2-7bc18fc961b7)

With 500mV input I get a current of around 0.3 mA, with the highest current is 0.5 mA, which is below 1 mA so it safe for the human body

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/984e8c8e-4b56-4b08-b842-a6e99724385e)


### Instrument amplifier

The instrument amplifier function as an amplifier from two different signal inputs. For the instrument amplifier (IA), I use AD620 IC. One IA is connected to a reference resistor from VCCS, and the other one is placed at the observed object with the same gain value.

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/cf48099c-1c1c-4573-bc30-73e7e69c18d0)

On the second IA, there's also a High Pass Filter because the signal from the human body will also contain a DC signal, so we will remove it using a High Pass Filter, I use first-order HPF with a 159 Hz cut-off frequency

### AC to DC converter

Because the output of the signal is still an AC signal, we need to convert it to a DC signal, so the microcontroller can read it. I used a peak detector as the AC-to-DC converter. consisting of an op-amp, diode, capacitor, and resistor. 

![image](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/4128837d-0dfe-4be0-a1e1-d2c8b6e17acb)

At first, I didn't use a resistor and when I checked using a multimeter I get a satisfied result, but when it was connected to the microcontroller ADC it suddenly when higher than it should have. So because a multimeter usually has around 1m ohm impedance, I tried connecting a 1m ohm resistor to it and get a kinda satisfied result. But there's a second problem which is it can't read lower than 100mV, but when I read it using a multimeter I can get the actual result i.e. 82mV. So I still don't know what caused it. So for now I can't read impedance lower than 100 Ω. 

## Results

As mentioned above there's still a problem that I haven't figured out yet. But here are the current results:

### Using Resistor

*Using 320ohm Reference resistor

- 1320 Ω resistor

![1320 ohm](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/f0573433-095c-44dc-afdb-be468862d06f)

- 1kΩ resistor

![1k](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/0bbc9a15-97e3-4c21-af13-99f5cdbaf897)

- 568 Ω resistor

![264 320 ohm](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/edef5eda-d9bd-4ce7-9b44-b819f870cfb9)

- 320 Ω resistor

![330 ohm 320](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/a1072c09-794d-4338-a150-9b4c80346d77)

- 264 Ω resistor

![264 ohm](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/7e72dd5d-efd6-4bf7-961a-99f7b31c1fb4)

- 100 Ω resistor

![100 ohm](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/0406ae25-db73-45f7-b508-b2471e4d5e26)

---
