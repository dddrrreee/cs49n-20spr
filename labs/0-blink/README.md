### Lab: make sure R/pi hardware and its toolchain works.

There's a lot of fiddly little details in getting a pi working, and
this lab is many people's first time working with hardware, so we break
the lab down into many (perhaps too-many) small steps.   Our theorem:
the smaller the step, the more obvious what the actual (distal) error is
and the less time you have to spend debugging.

We'll use different variations of a blinky light using GPIO pin 20 
(second from bottom on the right):

  1. you'll turn on an LED manually;
  2. then use a pre-compiled program (why not skip 1?);
  3. then use a bootloader (why not skip 2?);
  4. then install the r/pi tool chain, compile a given assembly
	   version and use it (why not skip 3?);
  5. then write your own and compile: this is the fun part.  It's also
	the longest (why not skip 4?).

The final sign off for the lab, show the TA/me your code and run four
  programs: 
  1. one that blinks pin 20; 
  2. pin 16 (right above 20);
  3. pin 5;
  4. Finally, blink 20 and 21 (right below 20) in opposite orders (i.e.,
  if 20 is on, 21 should be off).  (This will point out a subtle mistake
  people make reading the docs).

--------------------------------------------------------------------------
### Life and death rules for pi hardware.

Always:

  1. Whenever you make a hardware change --- messing with wires,
     pulling the SD card in/out --- ***make sure pi is disconnected***.
     It's too easy to short something and fry your hardware.  Also,
     pulling the SD card out while under power appears to sometimes
     cause corruption.

  2. While you've maybe never worked with a pi, it's just like anything
     else in the sense: if it's not responding, unplug it (remove power)
     and reconnect.

  3. If anything ever gets hot --- the serial device, the pi ---
     ***disconnect***.  Sometimes devices have manufacturing errors
     (welcome to hardware), sometimes you've made a mistake.  Any of
     these can lead to frying the device or, in the worst case, your
     laptop.  So don't assume you have a safety net: its up to you to
     avert disaster.

--------------------------------------------------------------------------
#### 0. Make sure you have everything.

Pick up:
  1. a R/PI A+;
  2. a microSD card and adapter;
  3. a CP2102 USB-TTL adapter;
  4. however many led's you want;
  5. some female-female jumpers;
  6. printout of the pi's pins.

<table><tr><td>
  <img src="images/manifest.jpg"/>
</td></tr></table>


--------------------------------------------------------------------------
#### 1. Make sure hardware is working:

Before we mess with software, we first make sure the hardware works.  When doing
something for the first time, you always want to isolate into small pieces.

Use the USB-TTY to power the pi, and use the pi's power to directly
turn on an LED.  This tests some basic hardware and that you know how to
wire.

<table><tr><td>
  <img src="../../docs/gpio.png"/>
</td></tr></table>

Mechanically:
  1. Connect the USB-to-TTL Serial cable's power (red) and ground  (black)
     wires to the 5v and ground pins on the pi that are next to each other
	(see your printout; upper right corner).
  2. Plug the USB-TTY into your USB port.
  3. Connect  your LED up to another ground pin and the 3v power pin (there are
     several) to make sure the hardware components work, and you know how
     get them to.  If the LED doesn't go on, reverse its connections.
     If still doesn't go on, plug someone else's working version into
     your computer.  If that doesn't work, ask.

(EE folks: We don't use a breadboard b/c it's bulky; we don't use
resistors for the same reason + the LED is big enough we generally don't
fry it.)


What can go wrong:
  1. If your USB-to-TTL starts heating up, disconnnect!   It appears that 1 in 8
  is defective.   
  2. If your pi starts heating up, now or ever, disconnect!   If you have a short,
  where a pin with power feeds right into ground, you'll fry it.

--------------------------------------------------------------------------
#### 2.  Make sure you're able to install firmware, etc:

You'll run a precompiled program (`part1/blink-pin20.bin`) on the pi and make
sure it can blink pin 20.


Note: in the next assignment  when you develop your own remote bootloader
(see next step), if your code is broken you'll need to use this SD
card method to load a new version, so pay attention to how you do it on
your computer.

Mechanically:
  1. Unplug the USB-TTY.
  2. Plug SD card into your computer and figure out where it's mounted.
  3. Copy all the files from class `firmware` directory onto the SD card (`cp firmware/* /<sdcard path>/`)
  4. copy `part1/blink-pin20.bin` to the SD card as `kernel.img`.
  5. unmount/eject the SD card (don't just pull it out!  data may not be written out.)
  6. connect the LED to GPIO20 and ground. 
     Use `docs/gpio.png` to figure out which this is.
  7. Plug the SD card into your pi
  8. Plug in the USB-TTY to your USB to power the pi.  The pi will jump
  to whatever code is in `kernel.img`.

The LED should be blinking.  If you get this working, please help anyone
else that is stuck so we all kind of stay about the same speed.

Troubleshooting:
   0. First try to trouble shooting from part 1.
   1. If it's not blinking, swap in someone else's card that is working.
   2. If that works, compare their SD card to yours.
   3. If that doesn't work, try your card in their rpi.  


--------------------------------------------------------------------------
#### 3.  Send a new pi program from your computer rather than SD card.

As you've noticed, running new programs on the pi using the SD card
method is tedious.  This step shows makes it so you can send programs
directly from your computer to a plugged-in pi.

Method: install a program (which we somewhat inaccurately call a
"bootloader").   This program will wait on the pi for a program sent by
your computer, copy it into pi memory, and then jump to it.  We currently
give you a pre-compiled version (`firmware/bootloader.bin`).

<table><tr><td>
  <img src="images/assembled.jpg"/>
</td></tr></table>

Mac:
  - Download and install the drivers for a
   CP210x USB-to-UART driver as described in the 
   [cs107e docs](http://cs107e.github.io/guides/mac_toolchain/).
   - Make sure you reboot after doing so.

Linux:
  - You shouldn't need drivers, however you may need to add yourself to
    the `dialout` group (or `serial`) depending on the distribution.

        sudo adduser <your username> dialout

    If that still doesn't work, you may have to remove `modemmanager`:

        sudo apt-get remove modemmanager

Mechanically:

  0. Unplug your pi. Don't modify your current wiring.
  1. Copy `firmware/bootloader.bin` on your SD card as `kernel.img` (see a 
 	pattern?).
  2. Hook the TX and RX wires up to the pi.  Do you TX/TX and RX/RX or
     switch them?  (Hint: Think about the semantics of TX (transmit)
     and RX (receive).)
  3. Copy `bin/pi-install.linux` or `bin/pi-install.macos` to your
     local `bin/pi-install`.  Make sure when you type 'pi-install'
     something happens!  If not, make sure your local `bin/` directory
     is in your path, and that you have sourced your shell startup file.
  4. Run `pi-install part1/blink-pin20.bin`

Your LED should be blinking.

--------------------------------------------------------------------------
#### 4.  Make sure your r/pi toolchain is working.

For this class you need to compile bare-metal r/pi programs on your
computer, which is most likely not a bare-metal r/pi itself.  Thus we
need to set up the tools needed to ``cross-compile'' r/pi programs on
your computer and to r/pi binaries.

Install the toolchain:
   -  For a mac use the [cs107e install notes](http://cs107e.github.io/guides/mac_toolchain/).    Note: do not install the python stuff.

   -  For [ubuntu/linux](https://github.com/eistec/mulle/wiki/Installing-toolchain-%28GCC%29):

           sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
           sudo apt-get update
           sudo apt-get install gcc-arm-none-eabi
       
      You may also have to add yourself to the `dialout` group.
      If gcc can't find header files, try:

           sudo apt-get install libnewlib-arm-none-eabi


Compile `part2/blink-pin20.s` using the shell script.

   1. `cd part2`.   Run `sh make.sh`.
   2. reset your pi: unplug the TTY-USB then plug it back in to your laptop.
   3.  `pi-install part2/blink-pin20.bin`.   Should blink.  If
	not isolate the problem by trying the blink-pin20.bin in `part1/`,
	your lab partner's, etc.

--------------------------------------------------------------------------
#### 5. write your own blink!

Congratulations!  You now have a working system, and have solved or
avoided a bunch of very annoying problems.

Now we get to the fun part.  You'll read the Broadcom document to see how to 
turn the GPIO pins on yourself and then filling in the code in `part3/blink.c`.

Change the code to first work with GPIO20.

   1. look at the broadcom document: `docs/BCM2835-ARM-Peripherals.pdf`
   pages 90--96.  NOTE: where the broadcom document uses
   addresses `0x7420xxxx`, you'll use `0x2020xxxx`.
   2. Adapt the code in `part3/blink.c` to (1) set GPIO pin 20 to output,
   and then in a loop repeatedly set it on and off ("clear").  
   3. After each change, power-cycle the pi, and use the bootloader to
   load the code. `pi-install kernel.img`

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
