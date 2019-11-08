// simple test for your put/get implementation.  get this working first!
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "cross-check.h"
#include "rpi.h"

// simplest possible test: write a single value and then look it up.
static void simple_test(void) {
    PUT32(4,5);
    assert(GET32(4) == 5);
    PUT32(4,6);
    assert(GET32(4) == 6);
}

/***********************************************************************************
 * do a bunch of random insertions and verify they state there persistently.
 */
static void check_all_mem(struct mem *m, int n) {
    for(int i = 0; i < n; i++)
        assert(get32(m[i].addr) == m[i].val);
}

static void harder_test(void) { 
#   define N 128
    struct mem m[N];

    // create all "addresses"
    for(int i = 0; i < N; i++)
        m[i].addr = (void*)random();

    // we do multiple passes to check that assigments stay persisent over multiple writes.
    for(int trials = 0; trials < 4;  trials++) {
        for(int i = 0; i < N; i++) {
            m[i].val = random();
            put32(m[i].addr,m[i].val);
            check_all_mem(m,i);
        }
    }
}

int main(void) {
    // make sure that everyone has the same random.
    assert(22128 == random());


    simple_test();
    harder_test();

    return 0;
}
