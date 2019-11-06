#include <stdlib.h>
#include <argp.h>
#include "parser/parser.h"
#include <string.h>
#include "cli.h"
#include "ast/ast_tree.h"
#include "ast/ast_dump.h"


int main(int argc, char *argv[]) {
//    struct arguments arguments;
//    error_t error = argp_parse(&argp, argc, argv, 0, 0, &arguments);
//    strerror(error);
//    printf ("ARG1 = %s\nARG2 = %s\nOUTPUT_FILE = %s\n"
//            "VERBOSE = %s\nSILENT = %s\n",
//            arguments.args[0], arguments.args[1],
//            arguments.output_file,
//            arguments.verbose ? "yes" : "no",
//            arguments.silent ? "yes" : "no");

    struct translation_unit_t* tu = parse("_Static_assert(,);");
    ast_dump(tu, stdin);

    return EXIT_SUCCESS;
}