#include "sifdev.h"

int (*sceOpen)(const char *pathname, int flags) = (int (*)(const char *, int))0x00540B28;
int (*sceClose)(int fd) = (int (*)(int))0x00540DB8;
size_t (*sceLseek)(int fd, size_t offset, int whence) = (size_t (*)(int, size_t, int))0x00540F30;
size_t (*sceRead)(int fd, void *buf, size_t count) = (size_t (*)(int, void *, size_t))0x00541170;
size_t (*sceWrite)(int fd, const void *buf, size_t count) = (size_t (*)(int, const void *, size_t))0x005413E0;
int (*sceChdir)(const char *name) = (int (*)(const char *))0x00542D20;

int (*sceDopen)(const char *dirname) = (int (*)(const char *))0x00542388;
int (*sceDclose)(int fd) = (int (*)(int))0x00542450;
int (*sceDread)(int fd, struct sce_dirent *buf) = (int (*)(int, struct sce_dirent *))0x005425B8;
int (*sceRemove)(const char *filename) = (int (*)(const char *))0x00542B18;
int (*sceMkdir)(const char *dirname, int flag) = (int (*)(const char *, int))0x00541DE0;
int (*sceRmdir)(const char *dirname) = (int (*)(const char *))0x00541F98;
