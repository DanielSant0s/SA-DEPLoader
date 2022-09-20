#include <stdint.h>
#include <ctype.h>

extern void* (*memset)(void *, int, size_t) __attribute__((section(".data")));
extern void* (*memcpy)(void *, const void *, size_t) __attribute__((section(".data")));
extern int (*memcmp)(const void *, const void *, size_t) __attribute__((section(".data")));

extern size_t (*strlen)(const char *) __attribute__((section(".data")));
extern int (*strcmp)(const char *, const char *) __attribute__((section(".data")));
extern char* (*strcpy)(char *, const char *) __attribute__((section(".data")));
extern char* (*strcat)(char *, const char *) __attribute__((section(".data")));
extern char* (*strncpy)(char *, const char *, size_t) __attribute__((section(".data")));
