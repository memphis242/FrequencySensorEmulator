# Frequency Sensor Emulator
At work, I had the need for a device that could produce particular subset of square wave signals. No function generator around could do exactly what I needed, so I decided this was enough to do with almost any microcontroller around. I selected the STMicroelectronics Nucleo-144 STM32H743ZI2 board along with some additional circuitry on a breadboard for the prototype. That worked quite well and just for fun and learning, I plan to bring this up to a professional-grade product.

# Device Demo
### Prototype
Here is a screenshot of an example signal I was able to produce:

![37us 328Hz 5V Screenshot 1](https://github.com/user-attachments/assets/18f7d477-d7f0-4fc0-a244-829e36fbbb07)

The frequency was certainly adjustable from as low as ≈30Hz to as high as ≈3kHz, and the pulse width was very precisely selectable from the discrete set `[38, 45, 52, 74, 90, 104, 200]` microseconds.

# Project Status / History
This project is in its initial development phase.

# Table of Contents
TODO

# Usage Instructions
TODO

# How Can I Get This?
TODO

# Repository Walk-Through
TODO

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