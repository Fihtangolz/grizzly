#include <stdlib.h>
#include <argp.h>
#include "parser/parser.h"


int main(int argc, char *argv[]) {
   error_t error = argp_parse(0, argc, argv, 0, 0, 0);
   strerror(error);
   parse("enum tested { ADADAD, ADADAD, }");

   return EXIT_SUCCESS;
}