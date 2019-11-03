#include <assert.h>
#include <string.h>

#include "keywords.h"

/* Constraint: `(keyword_t)i` signifies `keywords[i]`, where `i` belongs to `[0;
 * KEYWORDS_COUNT)`. If i is -1, then a keyword doesn't exist
 * (`KEYWORD_NONEXISTENT`).
 */
const char *const keywords[] = {
    "auto",       "break",     "case",           "char",
    "const",      "continue",  "default",        "do",
    "double",     "else",      "enum",           "extern",
    "float",      "for",       "goto",           "if",
    "inline",     "int",       "long",           "register",
    "restrict",   "return",    "short",          "signed",
    "sizeof",     "static",    "struct",         "switch",
    "typedef",    "union",     "unsigned",       "void",
    "volatile",   "while",     "_Alignas",       "_Alignof",
    "_Atomic",    "_Bool",     "_Complex",       "_Generic",
    "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local"};

keyword_t recognise_keyword(const char *text) {
    for (int i = 0; i < KEYWORDS_COUNT; i++) {
        if (strcmp(keywords[i], text) == 0) {
            return (keyword_t)i;
        }
    }

    return KEYWORD_NONEXISTENT;
}