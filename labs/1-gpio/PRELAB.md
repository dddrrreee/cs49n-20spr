## Lab 1 - GPIO - Prep Worksheet
### Background Summary

A register is a block of memory (often 32 bits long). In the R/Pi, there are quite a few registers dedicated to hardware control. For this lab you will read pgs. ---- of the Broadcom document and look for registers associated with switching the output of the gpio pins on the R/Pi. 

### Lab skills

  1. You will learn how to use the R/Pi GPIO memory addresses and modify them with PUT32/GET32.

  2. You will make your own GPIO functions so that you can read and write values
     to/from the GPIO pins. This will allow you to control LEDs, touch sensors, sonar
     devices, and pretty much everything you can think of over the course of the quarter.

  3. You will use your GPIO functions to make an LED respond to a touch sensor!

### Review Exercises

#### Binary Translations!

1) What is 01101000 in decimal (base-10)?

2) What is the decimal number 17 is binary?

#### Logical Operations: BITSHIFTING, AND, OR

3) What is (1011 << 2) in decimal?

4) What is 01101001 & 00111000? Binary is fine.

5) What is 1001 | 1100?

6) What is (01111001 & ~(111 << 4)) | (1 << 5)?

#### Broadcom document

7) You've been asked to read pgs. 90-96 of the broadcom document, which describes several memory registers. What is the address of the register(s) we will use to change a pin to output or input (say, for pin 5)?

8) What about the address for checking the input level of a pin?
