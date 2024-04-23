# DESIGN THOUGHTS
### Initial Thoughts
- This component needs to output a square wave signal of variable frequency and duty cycle.
- I need to be able to set the output frequency between 3.5Hz and 2660Hz and vary the high-pulse time from 37us through 52us and 76us through 104us.
- Going to do the initial draft of this project with one guiding design principle: keep it simple, stupid! (KISS)
   - ADC will be software-triggered (no timer-triggered DMA shenanigans)
   - Single 32-bit timer whose interrupt routine will trigger a GPIO pin (no hardware PWM DMA shenanigans)
   - Frequency will be varied based on timer auto-reload register value
   - High-pulse time (duty-cycle) will be varied based on output-compare value