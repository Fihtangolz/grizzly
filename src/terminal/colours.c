#include "colours.h"

const char *colours_red = "\x1b[31m", *colours_yellow = "\x1b[33m",
           *colours_green = "\x1b[32m", *colours_magenta = "\x1b[35m",
           *colours_cyan = "\x1b[36m", *colours_reset = "\x1b[0m";

void colours_disable(void) {
    colours_red = "";
    colours_yellow = "";
    colours_green = "";
    colours_magenta ="";
    colours_cyan = "";
    colours_reset = "";
}