# Bioimpedance_measure_microcontroller
Measuring bioimpedance using a microcontroller

*Note: this project is not done

A tool for measuring a person's bioimpedance, using a microcontroller as a signal processor and reader of measurement results, and displays it. The device that is made consists of a signal generator that uses a Wien bridge oscillator circuit to produce a 33 kHz sine wave signal, then VCCS to convert the input voltage into a current source so that it is safe when it enters the body, then the signal is read using an instrument amplifier as an amplifier so that it is easy to read, and converted to a DC signal for reading


In this project, I created 2 different circuits, one using [wien bridge oscillator](#using-weins-bridge-oscillator) and using [AD9833](#using-AD9833) module.

for the full documentation: [Using wien bridge oscillator](WienBridge.md) and using [AD9833](AD9833.md)

---

# Using wein's bridge oscillator


## Schematic 

![Schematic_Bioimpedance_2023-10-07](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/4e0a50bc-f4f0-4f06-821f-029a3d162ce8)

## Components

- Positive to Negative Voltage Converter
- Wein's Bridge Oscillator
- VCCS
- Instrument amplifier
- AC to DC converter

## Results

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

# Using AD9833

after using wein's bridge oscillator I want to test the same with ad9833 module as the function generator to produce sine wave. The schamatic is still mostly the same

## Schematic 

(image)


