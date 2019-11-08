### Lab: automatically cross-check your GPIO code against everyone else's.

A goal of this course is that you will write every single line of
(interesting) low level code you use.  A good result of this approach is
that you will understand everything and, unlike most OS courses, there
will not be a lot of opaque, magical code that you have no insight into,
other than sense of unease that it does important stuff beyond your ken.

An obvious potential result of this strategy is that since you are writing
all code your system depends on, a single bug can make the rest of the
quarter miserable.

This lab will have you build the initial pieces needed to automatically
check that your homework code is correct.

After completing the lab you will:

  1. Be able to check that your `gpio` code is equivalent to
     everyone else's in the class by tracing all reads and writes
	 it does and comparing them to everyone else's implementation.
	 If even one person gets it right, then showing equivalence means
	 you got it right too.  And, nicely, automatically detect if any
	 subsequent modifications you do break the code.

   2. Be able to quickly, correctly write a more full-featured
	`gpio` implementation by checking its equivalence against the
	fairly complicated code used in the initial cs107e class.

##### Pre-lab

Read through the code in the `code/` subdirectory:
   1. `cross-check.c` contains the procedures that you will implement.
   2. `test-put-get.c` has a simple test harness that will test the code you
      will write.  Do not modify this code (at least until you finish the lab!)
      but you should understand what it does.  What bugs will it find?  What
      bugs will it miss?
   3. `test-gpio.c` contains the simple test harness to check your
      `gpio` implementations.


##### Sign-off

   1. Your `gpio_set_output`, `gpio_set_on`,
   `gpio_set_off` give the same result as other peoples.  You can
   run them in this order and just hash the end result.

----------------------------------------------------------------------
#### 1. Make a fake implementation of `put32` and `get32`

In order to make testing easy, we want to be able to run your r/pi code ---
unaltered --- on your Unix laptop.  This might seem implausible, since the
code was written to run on the r/pi.   However, if as you look at the code,
most of it is C code, which will run the same on the r/pi and your laptop.
The main pi-specific stuff is (1) the addresses we read and write and (2) the
assembly code.   We will be testing the gpio-implementations in isolation,
so the assembly is not relevant.   That leaves the addresses.   

What do you need to do so?  

  1. Compile it for Unix.   Fortunately, because of the way we wrote `
     gpio.c` you can easily compile it both for RPI and to run on your
     Unix laptop by simply switching compilers.  

  2. Override what happens when it writes to GPIO memory or calls ARM-specific
     assembly code.   

     Since your `gpio.c` is simple, all you'll have to do is provide fake
     implementations of `get32` and `put32` so that we can override what
     happens when your code writes to GPIO memory.

First steps:
  1. From the pre-lab: Look in `fake-put-get.c` and read the comments.  You will implement
     `put32` and `get32`.

  2. Before you start, run `make` and make sure everything compiles.
     Note: the code will use your `gpio.h` and `gpio.c` from Part 0 so
     if you get compile errors it's probably because you have stuff in the 
     wrong place.

You'll now build a fake memory so that you can implement `put32` and
`get32` (again, look in `fake-put-get.c` file).

For `put32(addr,v)`: 
  1. Create an entry for `addr` in your fake memory if `addr` doesn't exist.
  2. Write `v` to `addrs` entry.
  3. Call `print_write(addr,v)`.

On `get32(addr)`:

  1. If `addr` does not exist, insert `(addr, random())` (but do not print anything).
  2. Get the value `v` associated with `addr`.
  3. Call `print_read(addr,v)` to print out the address and value.
  4. Return `v`.

To test it:
  1. Run `./test-put-get > out` on Unix.	It should run without
	   crashing and, importantly, print out the values for each
	   `put32` and `get32` in the exact order they happened.
  2. Get the checksum of the output (`cksum out`) and compare to your partner.
  3. If these values match, you know your code worked the same as your partner's.
  4. Now post to the newsgroup so everyone can compare.
  5. If everyone matches, and one person got it right, we've proven that
       everyone has gotten it right (at least for the values tested).

----------------------------------------------------------------------
#### 3. Check your code against everyone else (5 minutes)

After you checked your fake `put32` and `get32` we now want to check that
your `gpio` code works the same as everyone else.  Given the `get32` and
`put32` modifications above, a simple, stringent approach is to check
that two `gpio` implementations are the same:

  1. They read and write the same addresses in the same order with
  the same values.
  2. They return the same result.    (For our implementations we
  did not return any result, so this just means that your code
  never crashes.)

If both checks pass then we know that both implementations are equivalent
--- at least for the tested inputs.

For this section:
 1. Uncomment out the rule for `test-gpio` in `Makefile` and run `make`.
       This will compile the test harness `test-gpio.c`.
 2. You can test each function individually by running `test-gpio 0`,
       `test-gpio 1`, etc.  (Look in the `test-gpio.c` file.)
 3. Again compare the results to your partner and post to the newsgroup.
