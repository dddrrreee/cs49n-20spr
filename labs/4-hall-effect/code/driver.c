 /* simple driver for hall effect sensor --- initially do not modify.  */
#include "rpi.h"
#include "hall.h"

void notmain(void) {
    uart_init();

    printk("starting hall effect!\n");
    int hall = 21;
    hall_init_a1104(hall);

    printk("ready: hall effect!\n");
    for(int i = 0; i < 10; i++) {
        while(hall_read(hall) == 0) {}
        printk("sensed magnet! count = %d\n", i);

        while(hall_read(hall) == 1) {}
        printk("no magnet!\n");
    }
    printk("stopping hall effect!\n");
    clean_reboot();
}
