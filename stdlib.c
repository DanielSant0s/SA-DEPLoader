#include "stdlib.h"

void* (**malloc)(size_t) = (void* (**)(size_t))0x008250E4;
void (**free)(void*) = (void (**)(void*))0x008250E8;
