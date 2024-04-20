# DESIGN THOUGHTS
### Initial Thoughts
- This component needs to output a square wave signal of variable frequency and duty cycle.
- I need to be able to set the output frequency between 3.5Hz and 2660Hz and vary the high-pulse time from 37us through 52us and 76us through 104us.
- Since all timers are 16-bit in the STM32H743 as far as I can tell, and I really just want to keep things simple, I'll chain two 16-bit timers to produce a 32-bit one, and then write the interrupt routine to toggle a GPIO output pin.
    - Looks like I should reference 39.3.19 Timer Synchronization to setup timer chaining, and to enable interrupt on overflow (an event included in the "update event" umbrella), you set the TIMx_DIER UIE bit.