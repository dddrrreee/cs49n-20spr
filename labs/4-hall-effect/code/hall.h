#ifndef __HALL_H__
#define __HALL_H__

// initialize the hall effect sensor.
void hall_init_a1104(int pin);

// return 1 if magnet touching, 0 otherwise.
int hall_read(int pin);
#endif
