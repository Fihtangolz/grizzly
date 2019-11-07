#include <stdlib.h>
#include <argp.h>
#include "parser/parser.h"
#include <string.h>
#include "cli.h"
#include "ast/ast_tree.h"
#include "ast/ast_dump.h"


int main(int argc, char *argv[]) {
    error_t error = cli_parse_arg(argc, argv, &arguments);
    if(error) {
        strerror(error);
    }

    struct translation_unit_t* tu = parse(arguments.target_file);
    ast_dump(tu, stdin);

    return EXIT_SUCCESS;
}