#include <stdint.h>
#include <ctype.h>

extern void* (**malloc)(size_t) __attribute__((section(".data")));
extern void (**free)(void*) __attribute__((section(".data")));