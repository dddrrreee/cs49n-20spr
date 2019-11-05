/*
 * sonar, hc-sr04
 */
#include "rpi.h"


// use this timeout so everyone is consistent.
static unsigned timeout = 55000;

// gpio_read(pin) until either:
//  1. gpio_read(pin) != v ==> return 1.
//  2. <timeout> microseconds have passed ==> return 0
int read_while_eq(int pin, int v, unsigned timeout) {
    unimplemented();
}

// common pattern: devices usually have various bits of internal state.  wrap
// it up in a structure.  we return a copy to we don't have to malloc/free it.
typedef struct {
    int trigger, echo;
} hc_sr04_t;

// initialize:
//  1. setup the <trigger> and <echo> GPIO pins.
// 	2. init the HC-SR04 (pay attention to time delays here)
// 
// Pay attention to the voltages on:
//    - Vcc
//    - Vout.
//
// Troubleshooting:
// 	1. there are conflicting accounts of what value voltage you
//	need for Vcc.
//	
// 	2. the initial 3 page data sheet you'll find sucks; look for
// 	a longer one. 
//
// The comments on the sparkfun product page might be helpful.
hc_sr04_t hc_sr04_init(int trigger, int echo) {
    hc_sr04_t h = { .trigger = trigger, .echo = echo };
    unimplemented();
    return h;
}

// get distance.
//	1. do a send (again, pay attention to any needed time 
// 	delays)
//
//	2. measure how long it takes and compute round trip
//	by converting that time to distance using the datasheet
// 	formula
//
// troubleshooting:
//  0. We don't have floating point or integer division.
//
//  1. The pulse can get lost!  Make sure you use the timeout read
//  routine you write.
// 
//	2. readings can be noisy --- you may need to require multiple
//	high (or low) readings before you decide to trust the 
// 	signal.
//
int hc_sr04_get_distance(hc_sr04_t *h) {
    unimplemented();
    return -1;
}

void notmain(void) {
    uart_init();

	printk("starting sonar!\n");
    hc_sr04_t h = hc_sr04_init(20, 21);
	printk("sonar ready!\n");

    for(int dist, i = 0; i < 10; i++) {
        // read until no timeout.
        while((dist = hc_sr04_get_distance(&h)) < 0)
            ;
        printk("distance = %d inches\n", dist);
        // wait a second
        delay_ms(1000);
    }
	printk("stopping sonar !\n");
    clean_reboot();
}
