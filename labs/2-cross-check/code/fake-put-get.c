/*
 * Simple tracing memory implementation.  Used for cross-checking.
 *
 * you will implement a simple fake memory that maps addresses to values with two 
 * operations:
 *  put32(addr,val) --- maps addr to val.   
 *  get32(addr)     --- returns the value associated with val.  random number if never
 *                      written.
 *
 * memory is persistent and determistic.  i.e., if you do a put32(addr,val), then all
 * subsequent calls get32(addr) return <val> until the next put32(addr,val) where 
 * <val> != <val'>
 * 
 * simplistic assumptions:
 *  - all loads/stores are 32 bits.
 *  - read returns value of last write, or random() if none.
 *  - load and store prints the addr,val
 * 
 * HINT: the unavoidable price of correctness is simplicity.  I would implement 
 * this as a fixed sized array, that you do a simple linear scan to insert,
 * and lookup.
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cross-check.h"
#include "rpi.h"

/****************************************************************************
 * DO NOT CHANGE THIS CODE
 * DO NOT CHANGE THIS CODE
 * DO NOT CHANGE THIS CODE
 * DO NOT CHANGE THIS CODE
 * DO NOT CHANGE THIS CODE
 * DO NOT CHANGE THIS CODE
 */

// don't change print_write/print_read so we can compare to everyone.
static void print_write(mem_t *m) {
    printf("\tWRITE:addr=%p, val=%u\n", m->addr, m->val);
}
static void print_read(mem_t *m) {
    printf("\tREAD:addr=%p, val=%u\n", m->addr, m->val);
}

/****************************************************************************
 * Put your changes here.
 * Put your changes here.
 * Put your changes here.
 * Put your changes here.
 * Put your changes here.
 * Put your changes here.
 *
 * Implement these four functions:
 *  - lookup
 *  - insert
 *  - get32
 *  - put32
 */

// lookup <addr> in your memory implementation.  Returns the associated <mem_t>
// or 0 if there is none (null).
static mem_t* lookup(volatile void *addr) {
    unimplemented();
}

// insert (<addr>, <val>) into your fake memory.  
// do an assertion check that:
//   - before: <addr> is not in fake memory.
//   - after: <addr> is in fake memory and lookup returns the corect <val>
static mem_t *insert(volatile void *addr, unsigned val) {
    unimplemented();
}

// return the value associated with <addr>.  if this <addr> has not been written
// to, insert a random() value and return that.
//
// before you return, call print_read on the mem_t associated with <addr>.
unsigned get32(volatile void *addr) {
    unimplemented();
}

// write (<addr>, <val>) into your fake memory.  if the <addr> is already in fake
// memory, overwrite it.
// 
// before you return, call print_write on the mem_t associated with <addr>.
void put32(volatile void *addr, unsigned val) {
    unimplemented();
}

unsigned GET32(unsigned long addr) { return get32((void*)addr); }
void PUT32(unsigned long addr, unsigned val) { put32((void*)addr, val); }
