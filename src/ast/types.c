#include "types.h"
#include <unistring/stdbool.h>
#include <z3.h>

typedef enum {
    CONST    = 0b10000000,
    RESTRICT = 0b01000000,
    VOLATILE = 0b00100000,
    ATOMIC   = 0b00010000,
} qualifier_t;

typedef enum {
    BOOL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,

    FLOAT_COMPLEX,
    DOUBLE_COMPLEX,
    LONG_DOUBLE_COMPLEX,
} fundamental_type_t;

typedef struct {
    uint8_t qualifiers;
    //...
    char* identifier;
} type_t;

void add_qualifier(type_t* target, const qualifier_t qualifier) {
    target->qualifiers |= qualifier;
}

bool is_conteine_qualifier(type_t* target, const qualifier_t qualifier) {
    return (target->qualifiers & qualifier) == qualifier;
}