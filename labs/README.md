# The labs

This chunk of the class involes you writing a few simple low-level
devices and using modern techniques to check them.  Some of these labs
are quick (< 60 minutes), some are longer.

#### Laying the groundwork:

  The first few labs are intended to help get everyone on the same page and set up the
  development cycle you will all you over the course of the quarter.

  0. [blink](0-blink/): get everyone up to speed and all necessary
     software installed.  By the end you'll be able to compile the code
     for the pi and blink a light.

  1. [gpio](1-gpio/): You'll write your own
     GPIO implementations based on the Broadcom document GPIO description
     and use it to implement the LED in the previous lab and a touch
     sensor.

  2. [cross-check](2-cross-check/): you will use read-write logging
     to verify that your GPIO code is equivalent to everyone else's.
     If one person got the code right, everyone will have it right.

     A key part of this class is having you write all the low-level,
     fundamental code your OS will need.  The good thing about this
     approach is that there is no magic.  A bad thing is that a single
     mistake makes more a miserable quarter.  Thus, we show you modern
     tricks for ensuring your code is correct.

  3. [hello](3-hello/): As you've noticed, debugging without even having
     `printf` is a hassle   Before we do a bunch of devices, we first
     get `printf` working by writing a couple GPIO functions and then
     putting then `libpi`.

#### Basic devices:

  4. [hall](4-hall-effect/):  for this lab you'll bang out your first
     device: a hall-effect sensor that detects proximity of a magnet.
     We work directly off of the data sheets, so you get practice
     deciphering these.    They will be confusing.  This is expected.
     You will cross check your code against everyone else.

  5. [sonar](5-sonar/): for this lab you'll write a more complicated
     driver to measure distance using sonar.  Again, we'll work directly
     from a datasheet.

#### Less basic devices [***NOT DONE***]

  6. [ADC](7-adc/): many cheap devices are analog --- they communicate
     information by varying an output between 0 and some maximum voltage.
     Since pi GPIO pins only state that whether an input voltage is 0
     or 3.3v (read as a 1), we cannot connect analog devices directly.
     This lab shows how to use a cheap analog-to-digital (ADC) to convert
     these analog values to ones the pi can read.

  7. [lightstrip](6-ws2812b/): do the neopixel as part of basic devices?
     Have them make an equivalizer?

  8. [esp8622](8-esp): we show how to use an ESP8622 to communicate
     between r/pi's.

#### Synthesis [***NOT DONE***]
  - combine the ADC+mic+lightstrip into an equalizer.
  - combine the accel+lightstrip+esp into a remote wearable display.
  - use virtualization to convert the esp to a remote setup where r/pi code runs on 
    laptop and it sends commands to a remote set of pi's.  probably use a UDP server.
