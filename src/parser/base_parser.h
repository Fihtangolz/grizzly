#ifndef GRIZZLY_BASE_PARSER_H
#define GRIZZLY_BASE_PARSER_H

#include <stdbool.h>
#include <setjmp.h>
#include <stdio.h>

// drop comment
// malloc ast (if you dont need ast and just use simple visitors)
// set visitor for node
// allow drop identifiers table

typedef struct {
    bool drop_comment;
    bool drop_static_assert;
} config_t;

struct parser_t {
    char* cursor;
    char buf[4096];
    config_t config;
    jmp_buf checkpoint;
};

void update_chunk(struct parser_t* parser, FILE* file);

#endif //GRIZZLY_BASE_PARSER_H
