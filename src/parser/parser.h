#ifndef GRIZZLY_PARSER_H
#define GRIZZLY_PARSER_H

#include "../ast/ast_tree.h"

struct translation_unit_t* parse(const char* target_file);

#endif //GRIZZLY_PARSER_H
