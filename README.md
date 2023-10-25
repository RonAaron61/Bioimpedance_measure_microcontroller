# Bioimpedance_measure_microcontroller
Measuring bioimpedance using a microcontroller


A tool for measuring a person's bioimpedance, using a microcontroller as a signal processor and reader of measurement results, and displaying it. The device that is made consists of a signal generator that uses a Wien bridge oscillator circuit to produce a 33 kHz sine wave signal, then VCCS to convert the input voltage into a current source so that it is safe when it enters the body, and then the signal is read using an instrument amplifier as an amplifier so that it is easy to read, and converted to a DC signal for reading. After trying, this tool can be used as an angle estimation on the human hand to control robotic, and I tried to control the servo motor.


In this project, I created 2 different circuits, one using [wien bridge oscillator](#using-wiens-bridge-oscillator) and using [AD9833](#using-AD9833) module.

for the full documentation: Using [wien's bridge oscillator](WienBridge.md) and using [AD9833](AD9833.md)

---

- [Wien bridge oscillator](#using-weins-bridge-oscillator)
- [AD9833](#using-AD9833)
- [Implementation](#Implementation)

---

# Using wien's bridge oscillator


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

A tool for measuring a person's bioimpedance, using a microcontroller as a signal processor and reader of measurement results, and displays it. The device that is made consists of a signal generator that uses a AD9833 module to produce a 50 kHz sine wave signal, then VCCS to convert the input voltage into a current source so that it is safe when it enters the body, then the signal is read using an instrument amplifier as an amplifier so that it is easy to read, and converted to a DC signal for reading. It can read resistance/impedance from 82 Ω - 1 kΩ on ±3.25 V supply, and can also read the bioimpedance from human skin and can detect flexion and relaxation movement. But curently based on the experiment it still has some limitations such as it can only detect 82 Ω - 1 KΩ of impedance, above that the signal will be cuted, and below that the ADC can't read it because it to small. But this can be fixed by using a higher supply because currently it used around ±3.2V.

after using wein's bridge oscillator I want to test the same with ad9833 module as the function generator to produce a sine wave. The schematic is still mostly the same


## Schematic 

![Schematic_BIoimpedance2_2023-10-11 (1)](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/3d252a6d-891e-4264-bf06-23ac05744445)


## Results

### Using Resistor

*Using 215ohm Reference resistor

-> 1k Ω (real: 955 Ω)

![955](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/5537720e-d7f5-4cd4-b33d-e9ba8ba4ba36)

-> 642 Ω 

![642ohm](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/929407c9-dcf4-4ede-8932-a5a66542b263)

-> 320 Ω

![320 2](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/affaecd0-a64a-4374-8083-36ed3b7c13ba)

-> 215 Ω

![215ohm](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/f2a1e7dc-f008-49e0-8005-b6a233bf863c)

-> 80 Ω

![80 2](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/cd54eaf1-e470-42a1-bba8-33e1e7def20f)


### On human skin

after testing on a resistor and getting a pretty decent result, next, I tried it on human skin. I try on the biceps and try some flexing and relax to see the difference in the impedance

-> relax (180°)

![IMG_20231010_212323](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/a11fd528-4cc6-4d29-8dfd-16c5a544e4a0)

Result:

![flexx4](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/c50fa640-f446-416d-b48a-06751453d5ec)

-> 90°

![IMG_20231010_212315](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/70f69c8e-3e6e-41fd-b0ca-37c25b953ba6)

Result:

![s4](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/545faa30-82f9-478b-9652-0b37f34d6743)

-> flexion (around 40°)

![IMG_20231010_212320](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/325b4e28-b0d1-4dfa-aa75-2005ca41768d)

Result:

![lip4](https://github.com/RonAaron61/Bioimpedance_measure_microcontroller/assets/105662575/722dc10b-3eee-422c-8786-bf21f573499a)

# Implementation

After trying with both the AD9833 and Wien bridge oscillator, I decided to use the AD9833 because it is more stable and easier to control the frequency. As you can see above when I bend or straighten my hand the impedance also changes, so I try to implement this circuit as an estimation of the angle to control the servo motor based on the angle of my hand

Result: [YouTube](https://youtu.be/hNxc7NsJVV0?si=vREEqcHBl0VcCDHA)

[![Alt text](https://img.youtube.com/vi/hNxc7NsJVV0/0.jpg)](https://www.youtube.com/watch?v=hNxc7NsJVV0)
