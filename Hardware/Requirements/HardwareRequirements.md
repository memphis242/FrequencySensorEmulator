# Hardware Requirements Document
This requirements document specified hardware details that are a layer lower than the system level requirements. This includes:
- Component selection
- Hardware ports
- Device enclosure requirements

## Terminology
Reference [SystemRequirements.md](../../SystemArchitecture/SystemRequirements.md) for more terminology.
1. **Height**: Looking at the face of the device with the screen, the height is the vertical dimension.
1. **Width**: Looking at the face of the device with the screen, the width is the horizontal dimension.
1. **Depth**: How high the device comes off a flat surface if the face of the device with the screen is facing up.

## Requirements
1. `HRD_01`: The device shall be within ± 10% of these dimensions:
   a. Height: 76mm  
   b. Width: 100mm  
   c. Depth: 30mm  
1. `HRD_02`: To fulfill `UI_04`, the following shall be the output ports for this device:
   a. a BNC port (receptable)
   b. a 0.1" pin header
   c. a 0.1" socket header
   d. two banana plug receptacles
1. `HRD_03`: The device shall be powered by a standard ANSI 1604A 9V alkaline battery.
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