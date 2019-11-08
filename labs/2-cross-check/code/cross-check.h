#ifndef __CROSS_CHECK_H__
#define __CROSS_CHECK_H__

typedef struct mem {
    volatile void *addr;
    unsigned val;
} mem_t;

unsigned long xchk_rand(void);
#define random xchk_rand

#define panic(msg...) do {                      \
    fprintf(stderr, "%s:%s:%d:PANIC:", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, ##msg);                     \
    exit(1);                                                        \
} while(0)

#define debug(msg...) do {                      \
    fprintf(stderr, "%s:%s:%d::", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, ##msg);                     \
} while(0)

#define unimplemented() panic("implement this function!\n")


#endif
