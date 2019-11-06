#include "stdio.h"

enum mes_type_t {
    ERROR,
    WARNING
};

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_SGR_BOLD      "\033[1m"

void write(char* msg, char* some) {
    printf(ANSI_COLOR_RED ANSI_SGR_BOLD "error" ANSI_COLOR_RESET ANSI_SGR_BOLD ": %s" "\n" ANSI_COLOR_RESET ANSI_COLOR_MAGENTA "  -->" ANSI_COLOR_RESET " %s" "\n", msg, some);
    for(int i = 0; i < 3; i++) {
        printf(ANSI_COLOR_MAGENTA"   |\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA"%d  |\n"ANSI_COLOR_RESET, i);
    }
    printf("  "ANSI_COLOR_MAGENTA":::"ANSI_COLOR_RESET" %s" "\n", some);
    for(int i = 0; i < 3; i++) {
        printf(ANSI_COLOR_MAGENTA"   |\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA"%d  |\n"ANSI_COLOR_RESET, i);
    }
    printf(ANSI_COLOR_MAGENTA"..."ANSI_COLOR_RESET "\n");
    for(int i = 0; i < 3; i++) {
        printf(ANSI_COLOR_MAGENTA"   |\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA"%d  |\n"ANSI_COLOR_RESET, i);
    }

    printf("   "ANSI_COLOR_MAGENTA"= "ANSI_COLOR_RESET ANSI_SGR_BOLD "note: "ANSI_COLOR_RESET "some\n");

    printf("      var a = &"ANSI_COLOR_MAGENTA ANSI_SGR_BOLD "rocket_start"ANSI_COLOR_RESET"->ws(1, 22, 44)\n");
    printf(ANSI_COLOR_MAGENTA ANSI_SGR_BOLD "               ------------ some message"ANSI_COLOR_RESET"\n");

    printf("      var a = &"ANSI_COLOR_RED ANSI_SGR_BOLD  "rocket_start\n");
    printf("               ^^^^^^^^^^^^ some message"ANSI_COLOR_RESET);
}