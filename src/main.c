#include <stdlib.h>
#include <argp.h>
#include "parser/parser.h"
#include <string.h>
#include "cli.h"


int main(int argc, char *argv[]) {
    struct arguments arguments;
    error_t error = argp_parse(&argp, argc, argv, 0, 0, &arguments);
    strerror(error);
    printf ("ARG1 = %s\nARG2 = %s\nOUTPUT_FILE = %s\n"
            "VERBOSE = %s\nSILENT = %s\n",
            arguments.args[0], arguments.args[1],
            arguments.output_file,
            arguments.verbose ? "yes" : "no",
            arguments.silent ? "yes" : "no");

    parse("enum tested { ADADAD, ADADAD, }");

    return EXIT_SUCCESS;
}