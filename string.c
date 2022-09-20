#include "string.h"

void* (*memset)(void *, int, size_t)  = (void* (*)(void *, int, size_t))0x0054E568;
void* (*memcpy)(void *, const void *, size_t)  = (void* (*)(void *, const void *, size_t))0x0054E3B0;
int (*memcmp)(const void *, const void *, size_t)  = (int (*)(const void *, const void *, size_t))0x0054E318;

size_t (*strlen)(const char *)  = (size_t (*)(const char *))0x005517B8;
int (*strcmp)(const char *, const char *)  = (int (*)(const char *, const char *))0x00551558;
char* (*strcpy)(char *, const char *)  = (char* (*)(char *, const char *))0x005516A0;
char* (*strcat)(char *, const char *)  = (char* (*)(char *, const char *))0x00551298;
char* (*strncpy)(char *, const char *, size_t) = (char* (*)(char *, const char *, size_t))0x00551D80;
