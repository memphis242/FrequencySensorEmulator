# Frequency Sensor Emulator
## The (Relatable) Backstory
At work, I had been tasked with writing the software for one of our controllers that read the square wave signal from a speed sensor. That square wave signal gave us information on our Backhoe machine's output shaft speed via the signal's frequency as well as the shaft's direction via the signal's high-pulse time (how long the square wave signal's HIGH portion lasted in a given period). However, the sensor part had not arrived yet, and even if it was available, there was no simple test rig to place it into to test against, neither was there any desire to spend the money and time needed to create that test rig.   

"No matter", I thought. I'll use a handy function generator to emulate the sensor when it comes time to test. I soon came to find out that no function generator around could do exactly what I needed - duty cycle resolution was simply not enough, even on high-end function generators, and it would have been super inconvenient to utilize duty cycle regardless, because it was **high pulse time** alone that mattered for direction (45µs ±8 meant forward, 90µs ±14 meant backwards, regardless of frequency). So, I decided that this was easy enough to do with almost any microcontroller, and I endeavored to just that. It'd be fun to do it and show my resourcefulness to my team!   

For the sake of rapid prototyping, I initially selected the STMicroelectronics Nucleo-144 STM32H743ZI2 development board that I just had on hand from college along with some additional circuitry on a breadboard for the prototype. To be honest, the board was absolutely over-kill, and an Arduino likely would have been a lot of people's go-to, but I was trying to show that this wasn't an amateur project (sadly, people still called the board an Arduino FYI). With that said, how were the results? The prototype worked well! :partying_face:  

I decided to further "professionalize" this device by

1. bringing the software to higher quality standards,
2. giving it a friendlier user interface,
3. improving the reliability of the produced waveform,
4. selecting quality components (without concern for price since this is a one-off for now),
5. and adding several internal diagnostic measures

Overall, this is to make the device **easier to use** and **reliable**, as well as for my own personal enjoyment. I do actually have several ideas for further improvements (e.g., USB interface to control this emulator via a PC, opening the door to automated testing with it), but I shall reserve those for a third iteration.

# Device Demo
### Release `1.0.0`
TODO

### Prototype (STM32H743 Nucleo Board)
Here is a screenshot of an example signal I was able to produce:

![37us 328Hz 5V Screenshot 1](https://github.com/user-attachments/assets/18f7d477-d7f0-4fc0-a244-829e36fbbb07)

The frequency was certainly adjustable from as low as ≈30Hz to as high as ≈3kHz, and the pulse width was very precisely selectable from the discrete set `[38, 45, 52, 74, 90, 104, 200]` microseconds.

# Project Status / History
This project is in its initial development phase.

# Usage Instructions
TODO

# How Can I Get This?
TODO

# Repository Walk-Through
TODO

### KiCad Library Files
When viewing the KiCad files, you'll need to straighten out some custom symbol/footprint references I made weren't part of the libraries that came with my KiCad installation (as of 12/30/2024). My shared library files can be found here: [memphis242/KiCad-Libraries](https://github.com/memphis242/KiCad-Libraries)

TODO: Utilize relative references for the custom library components.

# Development Tech Used
### Hardware
TODO

### Software
TODO

# Detailed Documentation
TODO

# Contributing Guidelines
TODO

# License
TODO

# Acknowledgements
Credit where credit is due!

## Initial Prototype
STMicroelectronics products delivered the goods for the initial prototype. That includes the [NUCLEO-H743ZI](https://www.st.com/en/evaluation-tools/nucleo-h743zi.html) dev board along with the [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html).
