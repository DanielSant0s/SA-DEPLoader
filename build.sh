#!/bin/bash

mips64r5900el-ps2-elf-g++ -Wno-pointer-arith -fomit-frame-pointer -fno-exceptions \
-fno-asynchronous-unwind-tables -fno-unwind-tables -nostartfiles -nostdlib \
-fno-builtin-memcmp -fno-builtin-memcpy -fno-builtin-memset \
-fno-builtin-printf -fno-builtin-strcat -fno-builtin-strchr \
-fno-builtin-strcmp -fno-builtin-strcpy -fno-builtin-strlen \
-fno-builtin-strncpy -fno-builtin-strrchr -fno-builtin-strncmp \
-fno-builtin-sprintf -fno-builtin-floor -fno-builtin-pow \
-fno-builtin-malloc -fno-builtin-free \
-Wl,\
--section-start=.text=0x529C40 \
 -T format.ld elfparser.cpp -o loader.elf 