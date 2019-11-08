#ifndef __SONAR_HC_SR04_H__
#define __SONAR_HC_SR04_H__

// common pattern: devices usually have various bits of internal state.  wrap
// it up in a structure.  we return a copy to we don't have to malloc/free it.
typedef struct {
    int trigger, echo;
} hc_sr04_t;

// initialize the hc-sr04
hc_sr04_t hc_sr04_init(int trigger, int echo);

// get distance.
int hc_sr04_get_distance(hc_sr04_t *h);

#endif
