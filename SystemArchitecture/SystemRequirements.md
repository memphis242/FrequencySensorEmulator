# System Requirements Document
## General Description
The **Frequency Sensor Emulator** device is intended to serve a simple purpose - generate a square wave signal that emulates certain speed sensors that have a single data line where frequency gives speed information and high pulse time gives direction information. To get this device to be professional-grade and fulfill its purpose reliabily and conveniently, considerable thought has been put into the user experience as well as diagnostics and the selection of its components.  

This particular document is the System Requirements Document, where top-level system behavior is specified, as well as critical user interface items. Downstream of this are the [Hardware](../Hardware/Requirements/) and [Software](../Software/Requirements/) requirements documents which go a layer lower than the system level behavior.

## Terminology
1. **Diagnostic Routine**: A routine that checks that a particular aspect of the system's behavior is operating within certain constraints
1. **Diagnostic Fault**: If a particular diagnostic routine's check fails
1. **DC**: "Direct Current"; signal with a frequency of zero
1. **Square Wave**: A signal that ideally only takes on two different voltage levels
1. **HIGH**: The higher of the two voltage levels that the output square wave signal is driven to
1. **LOW**: The lower of the two voltage levels that the output square wave signal is driven to
1. **High Pulse Time**: The amount of time that the output signal's square wave is HIGH, usually given in microseconds (µs)
1. **HPT**: Abbreviation for "High Pulse Time"
1. **Setpoint Mode**: The mode that indicates whether the user's potentiometer input will be setting output frequency or output high pulse time
1. **User Interface Device**: A button, slide switch, potentiometer, LED, display, or other device that is directly interacted with by a user
1. **Power Switch**: The switch that turns on or off the device
1. **Enable Switch**: The switch that enables or disables the output signal
1. **SetPot**: The potentiometer that configures the setpoint for either frequency or HPT
1. **Setpoint Mode Switch**: The switch that toggles the setpoint mode
1. **Mild Fault**: A fault that, although active, does not prevent the device from producing a valid output that may still be usable to a user
1. **Catastrophic Fault**: A fault that indicates the output signal is out-of-spec
1. **Coarse Mode**: The SetPot's range is mapped to the full range of either frequency
1. **Fine Mode**: The SetPot's range is mapped to ±10% of the frequency value that was present at the moment of switching into fine mode
1. **Coarseness Switch**: The switch to toggle between coarse and fine mode
1. **Fault Context Values**: Values that provide more context to a fault
1. **Screen Knob**: The knob that will be near the edge of the screen and used to scroll through the screen, set the two voltage levels of the output square wave, and support several other functions
1. **Main Screen**: The screen that includes the output waveform graphic as well as the frequency and HPT text fields
1. **Diagnostic Screen**: The screen that lays out the diagnostic faults and other information
1. **Voltage Setpoint Modes**: One of three modes:
   a. Set Upper Voltage Level
   b. Set Lower Voltage Level
   c. Voltage Level Setpoint Off
1. **Voltage Setpoint Mode Button**: The button that cycles through the voltage setpoint modes

## User Interface
### Requirements
1. `UI_01`: The user shall turn on or off the device using a slide switch (power switch).
1. `UI_02`: The slide switch that turns on or off the device shall have at least two different mitigating measures to prevent accidental switching.
1. `UI_03`: The user shall enable or disable the output signal using a switch (enable switch).
1. `UI_04`: The output signal shall be made available through at least two different ports.
1. `UI_05`: The user shall set the desired output frequency using a potentiometer.
1. `UI_06`: The user shall set the desired output high pulse time using a potentiometer.
1. `UI_07`: There shall only be one potentiometer - the SetPot.
1. `UI_08`: The user shall be able to switch between setting frequency and setting HPT (i.e., select the setpoint mode) using a momentary push button (setpoint mode switch).
1. `UI_09`: There shall be two LEDs that indicate whether frequency or HPT is being set, or neither (both off).
1. `UI_10`: There shall be an amber LED that indicates a mild fault is active.
1. `UI_11`: There shall be a red LED that indicates a catastrophic fault is active.
1. `UI_12`: There shall be a display to present various pieces of information and screens.
1. `UI_13`: Holding down the setpoint mode switch shall  
   a. `UI_13A`: Cause the diagnostic screen to take over or to return to the main screen  
   b. `UI_13B`: **NOT** cause the setpoint mode to change  
1. `UI_14`: The screen shall display the set frequency in text form.
1. `UI_15`: The screen shall display the set high pulse time in text form.
1. `UI_16`: The screen shall display a waveform graphic that represents the set output waveform. It shall:  
   a. `UI_16A`: Include a separate horizontal axis for each frequency decade (0 to 10Hz, 10 to 100Hz, etc.) from 0 to 10kHz  
   b. `UI_16B`: Only display one horizontal axis at a time  
   c. `UI_16C`: Display the period in `000` (without leading 0's) format, with µs or ms units as applicable  
   d. `UI_16D`: Include a vertical axis that goes from 0.0V to (Max Voltage)  
   e. `UI_16E`: Plot a period of the set square waveform against the two axes  
1. `UI_17`: The user shall be able to toggle between a coarse and a fine mode using a momentary push button (coarseness switch)  
   a. `UI_17A`: The frequency resolution shall be the greater of 1Hz or `(Maximum Frequency) / (2 ^ (ADC Resolution))` in coarse mode  
   b. `UI_17B`: The frequency resolution shall be `(0.2 x Present Frequency) / (2 ^ (ADC Resolution))` in fine mode, with `Present Frequency` being the frequency that was set the moment fine mode was entered into  
1. `UI_19`: Pressing the voltage setpoint mode button shall cycle the screen through the three voltage setpoint modes.
1. `UI_20`: The voltage setpoint mode button shall be a momentary push button.
1. `UI_21`: The voltage setpoint modes shall be defined as follows:  
   a. `UI_21A`: Set Upper Voltage Level:  
      - The top level of the square waveform shall take on a different color.  
      - The screen knob shall move the top of the waveform up or down.  
      - The voltage level shall be greater than 0.0V and less than or equal to (Max Voltage).   
   b. `UI_21B`: Set Lower Voltage Level:  
      - The bottom level of the square waveform shall take on a different color.  
      - The screen knob shall move the bottom of the waveform up or down.  
      - The voltage level shall be greater than or equal to 0.0V and less than (Max Voltage).  
   c. `UI_21C`: Voltage Level Setpoint Off:  
      - The screen knob does not affect either voltage level.  
1. `UI_22`: (FUTURE) The device shall support a sweep for each of frequency and HPT.  
1. `UI_23`: There shall be a green LED to indicate the output is enabled.
1. `UI_24`: All recorded faults in memory shall be cleared through 5 presses of the setpoint mode button.
1. `UI_25`: The screen shall be visible during normal office indoor lighting conditions.
1. `UI_26`: The screen shall be visible from a 120° viewing angle from all sides.

## Functional Requirements
1. `SYS_FUNC_01`: The device shall output a square wave signal.  
   a. `SYS_FUNC_01A`: The output waveform's HIGH voltage level shall be settable from 0.1V to a **Max Voltage** of 5.0V.  
   b. `SYS_FUNC_01B`: The output waveform's LOW voltage level shall be settable from a **Minimum Voltage** of 0.0V to 0.1V below Maximum Voltage.  
   c. `SYS_FUNC_01C`: The output waveform's frequency shall be settable from **Minimum Frequency** of 0Hz to a **Maximum Frequency** of 5kHz.  
   d. `SYS_FUNC_01D`: The output waveform's high pulse time shall be settable from a **Minimum HPT** of 10µs to a **Maximum HPT** of 200µs.  
   e. `SYS_FUNC_01E`: The output waveform's frequency shall be within ±1% of the set frequency.  
   f. `SYS_FUNC_01F`: The output waveform's HPT shall be within ±0.5µs of the set HPT.  
   g. `SYS_FUNC_01G`: The output waveform's two voltage levels shall be within ±2% of the set voltage levels.  
1. `SYS_FUNC_02`: Only one Setpoint Mode shall be active at a time.
1. `SYS_FUNC_03`: The device shall last ≥ 2 hours driving a 1kΩ load across the output frequency range specified in `SYS_FUNC_01C`.
1. `SYS_FUNC_04`: The present session (except for what is mentioned in `SYS_FUNC_05`) shall be saved and reloaded at the start of the next session. Included in the session are:  
   a. HIGH and LOW voltage levels (1)  
   b. Frequency setpoint (2)  
   c. HPT setpoint (3)  
   d. Diagnostic faults (4)  
   e. Coarseness setting (5)  
   f. Setpoint mode (6)  
1. `SYS_FUNC_05`: The following session parameters/configurations shall be excluded from the session save specified in `SYS_FUNC_04`:  
   a. Output enabled  
   b. Active screen  
1. `SYS_FUNC_06`: At startup, the following shall be true:  
   a. Output is disabled  
   b. Active screen is the main screen  
1. `SYS_FUNC_07`: The device's output current shall be ≤ 50mA.
1. `SYS_FUNC_08`: The device shall keep track of time using a real-time clock, and support the user setting a time.

## Diagnostics
### Diagnostic Faults
Every diagnostic fault has a name, a description, severity level, an associated diagnostic check, and one or more values that provide further context for the fault.
#### Mild
1. `UI_SETPOT_LED_FRQ_INVALID`:  
   a. Description: The state of the SetPot frequency selection LED differs from the intended drive  
   b. Associated Diagnostic Check: `SYS_DIAG_06`  
   c. Context Values: None  
1. `UI_SETPOT_LED_HPT_INVALID`:  
   a. Description: The state of the SetPot HPT selection LED differs from the intended drive  
   b. Associated Diagnostic Check: `SYS_DIAG_06`  
   c. Context Values: None  
1. `SESSION_SAVE_FAILED`:  
   a. Description: Saving the present session's settings failed to save to non-volatile memory  
   b. Associated Diagnostic Check: `SYS_DIAG_01`  
   c. Context Values: Indices of failed session items, as specified in `SYS_FUNC_04`  
1. `UI_OUT_COARSENESS_LED_INVALID`:  
   a. Description: The state of the coarseness selection LED differs from the intended drive  
   b. Associated Diagnostic Check: `SYS_DIAG_06`  
   c. Context Values: None  
1. `DIAG_AMBER_LED_INVALID`:  
   a. Description: The state of the amber LED differs from the intended drive  
   b. Associated Diagnostic Check: `SYS_DIAG_06`  
   c. Context Values: None  
1. `DIAG_RED_LED_INVALID`:  
   a. Description: The state of the amber LED differs from the intended drive  
   b. Associated Diagnostic Check: `SYS_DIAG_06`  
   c. Context Values: None  
#### Catastrophic
1. `FRQ_OUTPUT_FRQ_LOW`:  
   a. Description: The output square wave signal's frequency is lower than the acceptable tolerance  
   b. Associated Diagnostic Check: `SYS_DIAG_04A`  
   c. Context Values:  
      - measured frequency  
      - setpoint frequency  
1. `FRQ_OUTPUT_FRQ_HIGH`  
   a. Description: The output square wave signal's frequency is higher than the acceptable tolerance  
   b. Associated Diagnostic Check: `SYS_DIAG_04A`  
   c. Context Values:  
      - measured frequency  
      - setpoint frequency  
1. `FRQ_OUTPUT_FRQ_NILL`:  
   a. Description: The output square wave signal's frequency is zero (it is DC) when the user has specified a non-zero frequency  
   b. Associated Diagnostic Check: `SYS_DIAG_04A`  
   c. Context Values: None  
1. `HPT_LOW`:  
   a. Description: The output square wave signal's HPT is lower than the acceptable tolerance  
   b. Associated Diagnostic Check: `SYS_DIAG_04C`  
   c. Context Values:  
      - measured HPT  
      - setpoint HPT  
1. `HPT_HIGH`  
   a. Description: The output square wave signal's HPT is higher than the acceptable tolerance  
   b. Associated Diagnostic Check: `SYS_DIAG_04C`  
   c. Context Values:  
      - measured HPT  
      - setpoint HPT  
1. `UPPER_VOLTAGE_OUT_OF_SPEC`:  
   a. Description: The output square wave signal's HIGH voltage level is outside acceptable tolerance  
   b. Associated Diagnostic Check: `SYS_DIAG_04B`  
   c. Context Values:  
      - measured HIGH voltage  
      - setpoint HIGH voltage  
1. `LOWER_VOLTAGE_OUT_OF_SPEC`:  
   a. Description: The output square wave signal's LOW voltage level is outside acceptable tolerance  
   b. Associated Diagnostic Check: `SYS_DIAG_04B`  
   c. Context Values:  
      - measured LOW voltage  
      - setpoint LOW voltage  
1. `OVERCURRENT`:  
   a. Description: The output current is above device limitations  
   b. Associated Diagnostic Check: `SYS_DIAG_05`  
   c. Context Values: Measured current before disable  
1. `UI_OUT_EN_LED_INVALID`:  
   a. Description: The state of the output enable LED differs from the intended drive  
   b. Associated Diagnostic Check: `SYS_DIAG_06`  
   c. Context Values: None  
### Requirements
1. `SYS_DIAG_01`: The device shall store diagnostic faults in non-volatile memory.
1. `SYS_DIAG_02`: The diagnostic faults shall be retrievable through the following means:  
   a. `SYS_DIAG_02A`: The display on the diagnostic screen  
   b. `SYS_DIAG_02B`: (FUTURE) Over CAN  
   b. `SYS_DIAG_02C`: (FUTURE) Over USB  
1. `SYS_DIAG_03`: Each fault shall have a name and one or more context values.
1. `SYS_DIAG_04`: The device shall monitor its square wave output and confirm that the waveform meets the following specs:  
   a. `SYS_DIAG_04A`: Frequency is within ± 1%  
   b. `SYS_DIAG_04B`: Voltage levels are within ± 2%  
   b. `SYS_DIAG_04C`: HPT is within ± 0.5µs  
1. `SYS_DIAG_05`: The device shall monitor its output current and if the current is ≥ 95% of the current specified in `SYS_FUNC_07` for ≥ 500ms, the device shall:   
   a. `SYS_DIAG_05A`: Record a catastrophic fault  
   b. `SYS_DIAG_05B`: Disable its output  
1. `SYS_DIAG_06`: For every digital output, the device shall confirm that the output level matches the intended drive to within 100ms.
1. `SYS_DIAG_07`: The device shall monitor display faults and record a separate fault for each fault reported by the display.
1. `SYS_DIAG_08`: The device shall support clearing of all faults from memory through the input specified in `UI_24`.
1. `SYS_DIAG_09`: (FUTURE) The device shall support timestamping faults.