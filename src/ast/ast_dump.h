#ifndef GRIZZLY_AST_DUMP_H
#define GRIZZLY_AST_DUMP_H

#include <bits/types/FILE.h>

void ast_dump(const struct translation_unit_t* tu, FILE* output);

#endif //GRIZZLY_AST_DUMP_H
