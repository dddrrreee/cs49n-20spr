### Lab: make sure R/pi hardware and its toolchain works.

Today you'll write your own code to control the r/pi pins.  You should have 
read through 8 pages of the broadcom document.

The first lab was just setup.  Today we get to the fun part.  You'll read
the Broadcom document to see how to turn the GPIO pins on yourself and
then filling in the code in `part3/blink.c`.


The final sign off for the lab, show the TA/me your code and run four
  programs: 
  1. one that blinks pin 20; 
  2. pin 16 (right above 20);
  3. pin 5;
  4. Finally, blink 20 and 21 (right below 20) in opposite orders (i.e.,
  if 20 is on, 21 should be off).  (This will point out a subtle mistake
  people make reading the docs).

--------------------------------------------------------------------------
#### 1. write your own blink!

###### 1.a write your own blink!

Change the code to first work with GPIO20.

   1. look at the broadcom document: `docs/BCM2835-ARM-Peripherals.pdf`
   pages 90--96.  NOTE: where the broadcom document uses
   addresses `0x7420xxxx`, you'll use `0x2020xxxx`.
   2. Adapt the code in `part3/blink.c` to (1) set GPIO pin 20 to output,
   and then in a loop repeatedly set it on and off ("clear").
   3. After each change, power-cycle the pi, and use the bootloader to
   load the code. `pi-install kernel.img`

#### 1.b Generalize: Implement `gpio_read` and `gpio_write`

Modify the code in `gpio.c`.

Generalize your code to work with any pin from 0 to 30 (note, not all of these
are defined, but ignore that):  

   1. Note that the different `GPFSELn` registers handle group of 10, so you 
	can divide the pin number to compute the right `GPFSEL` register.
   2. You will be using this code later!   Make sure you test the code by 
	rewiring your pi to use pins in each group.

Hint:

  0.  Be very careful to read the descriptions in the broadcom document to
   see when you are supposed to preserve old values or ignore them.
   If you don't ignore them when you should, you can write back
   indeterminant values, causing weird behavior.  If you overwrite old
   values when you should not, the code in this assignment may work,
   but later when you use other pins, your code will reset them.
 
               // assume: we want to set the bits 7,8,9 in <x> to <v> and
               // leave everything else undisturbed.
               
               x &=  ~(0b111 << 7); // clear the bits 7, 8, 9  in x
               x |= (v << 7);     // or in the new bits
                          

  1. You write `GPFSELn` register (pages 91 and 92) to set up a pin as an
  output or input. You'll have to set GPIO 20 in GPFSEL2 to output.

  2. You'll turn it off and on by writing to the `GPSET0` and `GPCLR0`
  registers on page 95.  We write to `GPSET0` to set a pin (turn it on)
  and write to `GPCLR0` to clear a pin (turn it off).

--------------------------------------------------------------------------


--------------------------------------------------------------------------
#### 6. Extra: Break and tweak stuff.

You're going to break and change your code to see effects of things going 
wrong and to make it somewhat better:

   1. Change your delay to increasingly smaller amounts.   What is going on?

   2. Add the reboot code below (we'll go into what different things mean)
   so that you don't have to unplug, plug your rpi each time:

           // define: dummy to immediately return and PUT32 as above.
           void reboot(void) {
                const int PM_RSTC = 0x2010001c;
                const int PM_WDOG = 0x20100024;
                const int PM_PASSWORD = 0x5a000000;
                const int PM_RSTC_WRCFG_FULL_RESET = 0x00000020;
                int i;
                for(i = 0; i < 100000; i++)
                     dummy(i);
                PUT32(PM_WDOG, PM_PASSWORD | 1);
                PUT32(PM_RSTC, PM_PASSWORD | PM_RSTC_WRCFG_FULL_RESET);
                while(1);
           }
   Change your code to just loop for a small fixed number of times and make
   sure reboot() works.

   3. Force the blink loop to be at different code alignments mod 64.   Do 
   you notice any difference in timing?  (You may have to make your 
   delay longer.)  What is going on?  

--------------------------------------------------------------------------
#### Additional information

More links:

  1. Useful baremetal information: (http://www.raspberrypi.org/forums/viewtopic.php?t=16851)

  2. More baremetalpi: (https://github.com/brianwiddas/pi-baremetal)

  3. And even more bare metal pi: (http://www.valvers.com/embedded-linux/raspberry-pi/step01-bare-metal-programming-in-cpt1)

  4. Finally: it's worth running through all of dwelch's examples:
  (https://github.com/dwelch67/raspberrypi).
