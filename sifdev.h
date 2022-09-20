#include <stdint.h>
#include <ctype.h>

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

struct sce_stat {
        unsigned int    st_mode;                   
        unsigned int    st_attr;       
        unsigned int    st_size;       
        unsigned char   st_ctime[8];   
        unsigned char   st_atime[8];   
        unsigned char   st_mtime[8];   
        unsigned int    st_hisize;     
        unsigned int    st_private[6]; 
};

struct sce_dirent {
        struct sce_stat d_stat; 
        char d_name[256];       
        void    *d_private;     
};

extern int (*sceOpen)(const char *pathname, int flags) __attribute__((section(".data")));
extern int (*sceClose)(int fd) __attribute__((section(".data")));
extern size_t (*sceLseek)(int fd, size_t offset, int whence) __attribute__((section(".data")));
extern size_t (*sceRead)(int fd, void *buf, size_t count) __attribute__((section(".data")));
extern size_t (*sceWrite)(int fd, const void *buf, size_t count) __attribute__((section(".data")));
extern int (*sceChdir)(const char *name) __attribute__((section(".data")));

extern int (*sceDopen)(const char *dirname) __attribute__((section(".data")));
extern int (*sceDclose)(int fd) __attribute__((section(".data")));
extern int (*sceDread)(int fd, struct sce_dirent *buf) __attribute__((section(".data")));
extern int (*sceRemove)(const char *filename) __attribute__((section(".data")));
extern int (*sceMkdir)(const char *dirname, int flag) __attribute__((section(".data")));
extern int (*sceRmdir)(const char *dirname) __attribute__((section(".data")));
