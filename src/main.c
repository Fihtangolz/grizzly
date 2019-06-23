#include <stdlib.h>
#include "parser/parser.h"

int main(int argc, char *argv[]) {
   parse("enum tested { ADADAD, ADADAD, }");

   return EXIT_SUCCESS;
}