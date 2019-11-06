## Lab 1 - GPIO - Prep Worksheet
### Background Summary

A register is a block of memory (often 32 bits long). In the R/Pi, there are quite a few registers dedicated to hardware control. For this lab you will read pgs. ---- of the Broadcom document and look for registers associated with switching the output of the gpio pins on the R/Pi. 

### Lab skills

  1. You will learn how to use the R/Pi GPIO memory addresses and modify them with PUT32/GET32.

  2. You will make your own GPIO functions so that you can read and write values
     to/from the GPIO pins. This will allow you to control LEDs, touch sensors, sonar
     devices, and pretty much everything you can think of over the course of the quarter.

  3. You will use your GPIO functions to make an LED respond to a touch sensor!

### Library functions

We've written two functions to write/read the memory addresses you will be manipulating for GPIO. We highly recommend looking at the prototypes for each one to confirm you understand what it does.

          put32(*addr, v) sets the 32 bits starting at *addr to v (unsigned).
          get32(*addr) returns the 32 bits starting at *addr.
          nop() does nothing, can be used for delays
          delay(ticks) delays the r/pi for an amount of time corresponding to ticks

### Review Exercises

The review exercises for Lab 1 center around reading/writing binary values into memory. If this takes you more than a few minutes, consult the CS107e background page at (https://cs107e.github.io/guides/numbers/). If this is new material and it seems a little daunting, know that everyone will need a refresher on these skills and successfully using them will carry you through this course.

#### Binary Translations!

1) What is 01101000 in decimal (base-10)?

2) What is the decimal number 17 is binary?

#### Logical Operations: BITSHIFTING, AND, OR

3) What is (1011 << 2) in decimal?

4) What is 01101001 & 00111000? Binary is fine.

5) What is 1001 | 1100?

6) What is (01111001 & ~(111 << 4)) | (1 << 5)?

#### Shifting Pointers

7) If we have an `*unsigned x` (4 bytes long) such that `x = (void*)0x4`, what memory address does `x+2` point to?

Note: this is effectively the following code:

          unsigned *x = (void*)0x4;
          x+2 # equals what?

#### Broadcom document

8) You've been asked to read pgs. 90-96 of the broadcom document, which describes several memory registers. What is the address of the register(s) we will use to change a pin to output or input (say, for pin 5)?

9) What about the address for checking the input level of a pin?
