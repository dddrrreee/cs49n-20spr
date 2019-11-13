## Tips, Tricks, and FAQ

You'll likely forget this link, but if at any point you get confused about some basic
concept, cs107e has a good set of guides on electricity, shell commands, pi stuff in 
general:
   - [CS107E repo] (http://cs107e.github.io/guides/)

Nice-haves, you don't need these for the first lab, but they will make
your Stanford journey much easier:

   - Figure out how to "tab complete" in your shell.  This gives you
     a fast(er) way to list out files and run things.  We'll show this,
     but you can google.

   - Figure out how to use tags.  Both `emacs` or `vim` support "tags",
     which use keyboard shortcuts to essentially treat identifiers as urls
     and navigate to the definitions of structures, functions, variables.
     This makes understanding code ***much much*** faster and easier.   [A description for `vim`](https://vim.fandom.com/wiki/Browsing_programs_with_tags).

   - Longer term: eliminate as much mouse usage as you can; ***especially
     eliminate screen switching***.  Ideally you'll have your code in one
     window, the compilation in another window on the same screen and
     switch back and forth between these windows without lifting your
     hands off the keyboard.  You should definitely not be switching
     screens for such tasks.

     The single biggest productivity slowdown I see in stanford undergrads
     (grads too) is the slow, laborious use of taking their hand off
     a keyboard, moving a mouse, clicking, switching screens, clicking
     on something else, switching back, etc.   You don't realize how
     much this will cripple you until you watch someone who writes code
     well and compare their fluent flow to your plodding agrarian
     lifestyle.  Such switching screens means you lose context
     (which makes fixing even trivial compilation errors painful),
     you move slowly, and in many different ways you will distrupt your
     programming flow state, which is basically the only real way you
     can get significant, effective work done.  Any time you move the
     mouse, you're not doing work.  Do what you can to stop this.

   - Install `gdb` if you can --- it makes things easier in other classes
     (e.g., you can do a backtrace after a crash to figure out where the
     code was) and for this class let you answer simple code questions
     quickly.  For example, what is the decimal value of `01010101011`?

          % gdb
          (gdb) p 0b01010101011
          $1 = 683

     Easy.

### FAQ

   - *How do I install `git`?*
     Look in the 
[Lab 0 Prelab] (labs/0-blink/PRELAB.md) for most of the details, but if you're having trouble, email the professor or TA.

   - *How do I edit files from the command line?*
     There are many tools to edit from the command line, but the three we suggest
     are `vim`, `nano`, and `emacs`. `emacs` is taught in CS107, so for those of you that have
     taken 107, you should know how to use it. If you haven't taken 107 and want to edit
     right away, try running `nano yourfilename`. `nano` is a pretty basic editor that ships
     by default on Mac and most Linux distributions, and you should be able to figure it out by
     trial-and-error.

     If you're inclined to learn something a little more complicated but potentially much more useful,
     try learning to use `vim`. Luckily for you, `vim` comes with it's own tutorial (run `vimtutor` from the
     command line), though it may be helpful to look online as well.

   - *What do you mean by 'edit your PATH?'*
     In UNIX operating systems, your $PATH is a global variable that programs will use in order to find
     files that they need. For example, whenever you run `git`, `vim`, or even `python` from the command
     line, your shell looks for an executable program named `git`, etc. in all the locations specified by
     your $PATH. For CS49N, we want you to be able to add programs like `pi-install` to your $PATH so that
     you can run them easily. To find the path to any given file, navigate to the directory with the file,
     then run `pwd` and it will read out the path.

     How to edit your path is pretty straightforward: you will need to create a custom settings file for
     your shell (`.bashrc` for bash, `.tcshrc` for tcsh) by running `vim .bashrc` in your home folder,
     then adding the line:

           % export PATH="$PATH:your/path/goes/here:/your/other/path/goes/here"
      
     It's key to preserve your default $PATH by including it in the export. If you don't, you may notice your
     shell won't know how to do things like `ls` or `vim`. Whenever you want your shell to load settings from
     this file, run `source ~/.bashrc`. If you have any more questions, try asking the professor, TA, or the
     internet --- there's a lot of stuff out there on how to use the UNIX command line.

   - *What is a Makefile?*
     Referring you to the CS107E [Guide to Makefiles] (http://cs107e.github.io/guides/make/).

   - *I loaded my code onto the SD card, but the R/Pi isn't working!*
     Awesome, this is exactly what Lab 0 is designed to help you tackle! Figure out what step went wrong -
     is it the hardware? SD card? Code you loaded onto that SD card? Try it on someone else's R/Pi, and see
     if it works. This should help narrow down what went wrong, and once you have a guess, you can try and
     debug it yourself or ask the professor for tips. Some common mistakes people make"

   1. Forgetting to rename `mysdcardcode.bin` to `kernel.img`. The R/Pi is looking for a file named `kernel.img`,
      so if it's not there, tough luck.

   2. Forgetting the `make` step. If you try renaming `mycode.c` as `kernel.img`, nothing will stop you, but the 
      code isn't compiled to binary and it's essentially a foreign language to the R/Pi processor.

     Hopefully this helps! As always, ask the professor if you're confused!

   - *There are so many wires! What goes where?*
     You're going to have to hook up wires for most of the sensors in this class, but we will do our best to
     make sure you don't need to be a professional electrician to figure it out. We've given you an R/Pi pin
     diagram for the first few labs, and you will be able to figure out what pins are what for each sensor by
     using its datasheet. Here's a few tips for the general case:

   1. Vs/Vcc/HIGH/RED/+5V/+3.3V often means the power supply. For the R/Pi, this means the pins to and from the
      Vs/Vcc/etc pins of the sensors will connect.

   2. GND/Ground/0V/BLACK means ground. Hopefully you have a basic sense of what this means, but either way it's
      almost always connected to the respective GND pin on the sensor. ***Whatever you do, try and avoid switching
      the Vcc/GND pins. For most sensors, this will cause them to overheat and stop working in a matter of seconds,
      so always plug stuff in while everything is off and double check before turning the power on***

   3. SENS/SIG/SIGNAL/TRG/TRIGGER/etc. are generally GPIO pins. These are connections on a sensor where you will
      need to send or receive information, so you probably want to hook it up to a GPIO pin.

   - *I have a question not answered here. What do I do?*
     Ask the professor! It's a small class and we're hoping that everyone will learn a lot, regardless of where they
     start from. Also, there are a TON of hobbyist resources for most of this, so look it up!
