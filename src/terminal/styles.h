#ifndef GRIZZLY_TERMINAL_STYLES_H
#define GRIZZLY_TERMINAL_STYLES_H

#include <stdbool.h>

const char *styles_underline, *styles_bold, *styles_reset;

void styles_disable(void);

#endif // GRIZZLY_TERMINAL_STYLES_H