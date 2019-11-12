#include "styles.h"

const char *styles_underline = "\033[4m", *styles_bold = "\033[1m",
           *styles_reset = "\033[0m";

void styles_disable(void) {
        styles_underline = "";
        styles_bold = "";
        styles_reset = "";
}