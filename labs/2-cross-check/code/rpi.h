#ifndef __RPI_H__
#define __RPI_H__

// these are in start.s
void put32(volatile void *addr, unsigned v);
unsigned get32(volatile void *addr);

// same as get32, just takes an unsigned rather than a void*
unsigned GET32(unsigned long addr);
// same as put32, just takes an unsigned rather than a void*
void PUT32(unsigned long addr, unsigned val);

// different functions we can set GPIO pins to.
enum {
    GPIO_FUNC_INPUT   = 0,
    GPIO_FUNC_OUTPUT  = 1,
    GPIO_FUNC_ALT0    = 4,
    GPIO_FUNC_ALT1    = 5,
    GPIO_FUNC_ALT2    = 6,
    GPIO_FUNC_ALT3    = 7,
    GPIO_FUNC_ALT4    = 3,
    GPIO_FUNC_ALT5    = 2,
};

// set GPIO function for <pin> (input, output, alt...).  settings for other
// pins should be unchanged.
void gpio_set_function(unsigned pin, int function);


// set <pin> to be an output pin.
void gpio_set_output(unsigned pin);

// set <pin> to input.
void gpio_set_input(unsigned pin);

// set GPIO <pin> on.
void gpio_set_on(unsigned pin);

// set GPIO <pin> off
void gpio_set_off(unsigned pin);

// set <pin> to <v> (v \in {0,1})
void gpio_write(unsigned pin, unsigned v);

// return the value of <pin>.
int gpio_read(unsigned pin);

#endif
