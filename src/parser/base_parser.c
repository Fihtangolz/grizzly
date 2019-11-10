#include <stdio.h>
#include "base_parser.h"

void update_chunk(struct parser_t* parser, FILE* file) {
    size_t nread = fread(parser->buf, 1, sizeof(parser->buf), file);
    if(nread != sizeof(parser->buf) && ferror(file)) {
        perror("The following error occurred");
    }
    parser->cursor = parser->buf;
}