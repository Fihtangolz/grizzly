#ifndef GRIZZL_TERMINAL_COLOURS_H
#define GRIZZL_TERMINAL_COLOURS_H

#include <stdbool.h>

extern const char *colours_red, *colours_yellow, *colours_green, *colours_magenta,
    *colours_cyan, *colours_reset;

void colours_disable(void);

#endif // GRIZZL_TERMINAL_COLOURS_H