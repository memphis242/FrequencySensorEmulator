# Hardware Requirements Document
This requirements document specified hardware details that are a layer lower than the system level requirements. This includes:
- Component selection
- Hardware ports
- Device enclosure requirements

## Terminology
Reference [SystemRequirements.md](../../SystemArchitecture/SystemRequirements.md) for more terminology
1. **Height**: Looking at the face of the device with the screen, the height is the vertical dimension
1. **Width**: Looking at the face of the device with the screen, the width is the horizontal dimension
1. **Depth**: How high the device comes off a flat surface if the face of the device with the screen is facing up
1. **Max Frequency**: Maximum Frequency specified in `SYS_FUNC_01C`
1. **Rated Frequency Range**: 0Hz to the Max Frequency
1. **Unwanted Signal Overlay**: Any signal on top of the ideal square waveform that is undersired (noise, ripple)
1. **Device Efficiency**: The ratio between the power to a 100Ω load and the power supplied by the device's battery
1. **Worst-Case Device Efficiency**: The device efficiency under conditions that cause maximum losses

## Requirements
1. `HRD_01`: The device shall be within ± 10% of these dimensions:
   a. Height: 76mm  
   b. Width: 100mm  
   c. Depth: 30mm  
1. `HRD_02`: To fulfill `UI_04`, the following shall be the output ports for this device:
   a. a BNC port (receptable) where the outer shell is connected to ground and the inner line is connected to the output signal
   b. a 0.1" pin header pair (ground + signal)
   c. a 0.1" socket header pair (ground + signal)
   d. two banana plug receptacles (ground + signal)
1. `HRD_03`: The device shall be powered by a single standard ANSI 1604A (IEC 6LR61) 9V alkaline battery.
1. `HRD_04`: (FUTURE) The device shall support being powered via USB C.
1. `HRD_05`: The device shall have a 3V backup 2032 battery to support graceful shutdown.
1. `HRD_06`: The display shall have 10mm bevels above and below it.
1. `HRD_07`: The display shall be on the left half of the device.
1. `HRD_08`: The display's right edge shall be at 60% ± 5% of the device's width.
1. `HRD_09`: The output ports for the device shall be on the left, right, or top face of the device.
1. `HRD_10`: The output enabled LED shall be on the same face as the output ports.
1. `HRD_11`: The SetPot shall be support > 2 full turns.
1. `HRD_12`: The SetPot shall have a metal knurled knob.
1. `HRD_13`: The SetPot shall a diameter ≥ 60% of the height of the display.
1. `HRD_14`: The enable switch shall be a slide switch.
1. `HRD_15`: When driving an infinite impedance, the device's output signal shall have a rise and fall time of no more than 2µs collectively.
   - _Rationale_: At 5kHz, the period is 200µs. I would like no more than 1% of that to be a rise and a fall time. In addition, with a Minimum HPT of 10µs, as specified in `SYS_FUNC_01D`, I would like at least 80% of the signals' HIGH pulse to be at the upper voltage level.
1. `HRD_16`: The device shall have a 100Ω ± 10% output impedance throughout its rated frequency range.
1. `HRD_17`: The device must be able to operate in typical indoor office conditions:   
   a. `HRD_17A`: 10°C to 50°C ambient temperature   
   b. `HRD_17B`: 30% to 60% relative humidity
1. `HRD_18`: The output signal shall have ≤ ±1mV of **unwanted signal overlay** on top of the base square waveform across its rated frequency range and output load range.
1. `HRD_19`: The worst-case device efficiency shall be ≥ 80%.

## Physical I/O
### Inputs
1. `AIN_SETPOT`: Analog input for the SetPot
1. `AIN_SCREEN_KNOB`: Analog input for the screen knob
1. `DIN_SETPOINT_MODE`: Digital input to set the setpoint mode
1. `DIN_VOLT_SET_MODE`: Digital input to set the voltage setpoint mode
1. `DIN_COARSENESS_SW`: Digital input to set the coarseness of the SetPot
1. `DIN_OUT_EN_SW`: Digital input switch to enable/disable the output
1. `DIAG_FRQ_OUT_AIN`: Diagnostic analog input to independently measure the output signal and confirm that it is within spec
1. `DIAG_FRQ_OUT_DIN`: Diagnostic digital input to independently measure the output signal and confirm that it is within spec (to be used as a PWM input)
1. `DIAG_FRQ_OUT_CURRENT_AIN`: Diagnostic analog input to measure the output current and detect overcurrents
1. `DIAG_DIN_UI_LED_FRQ`: Diagnostic digital input for the LED that indicates frequency is the active setpoint mode
1. `DIAG_DIN_UI_LED_HPT`: Diagnostic digital input for the LED that indicates high pulse time is the active setpoint mode
1. `DIAG_DIN_OUT_EN`: Diagnostic digital input for the green LED that indicates the output is active
1. `DIAG_DIN_LED_AMBER`: Diagnostic digital input for the amber LED that indicates a mild fault is active
1. `DIAG_DIN_LED_RED`: Diagnostic digital input for the red LED that indicates a catastrophic fault is active
### Outputs
1. `FRQ_OUT`: Digital output that represents the square wave output
1. `UI_SETPOT_LED_FRQ`: Digital output for the UI LED that represents frequency setpoint mode
1. `UI_SETPOT_LED_HPT`: Digital output for the UI LED that represents HPT setpoint mode
1. `DIAG_LED_AMBER`: Digital output for the amber LED
1. `DIAG_LED_RED`: Digital output for the red diagnostic LED
1. `LED_OUT_EN`: Digital output for the green LED that indicates the output is enabled and active
1. `UPPER_VOLTAGE_SETPOINT`: Digital output to PWM the upper voltage setpoint
1. `LOWER_VOLTAGE_SETPOINT`: Digital output to PWM the lower voltage setpoint
