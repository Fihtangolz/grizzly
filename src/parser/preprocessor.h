#ifndef GRIZZLY_PARSER_PREPROCESSOR_H
#define GRIZZLY_PARSER_PREPROCESSOR_H

#include <glib.h>

typedef enum {
    PREPROCESSOR_LEXEME_DEFINE,
    PREPROCESSOR_LEXEME_DEFINE_FUNCTIONAL,
    PREPROCESSOR_LEXEME_UNDEF,
    PREPROCESSOR_LEXEME_IFDEF,
    PREPROCESSOR_LEXEME_IFNDEF,

    PREPROCESSOR_LEXEME_INCLUDE,
    PREPROCESSOR_LEXEME_PRAGMA,
    PREPROCESSOR_LEXEME_ERROR,

    PREPROCESSOR_LEXEME_IF,
    PREPROCESSOR_LEXEME_ELIF,
    PREPROCESSOR_LEXEME_ELSE,
    PREPROCESSOR_LEXEME_ENDIF,
} preprocessor_lexeme_kind_t;

typedef struct {
    const preprocessor_lexeme_kind_t kind;

    union {
        struct {
            GString *filename;
        } include;

        struct {
            GString *identifier;
            GString *body;
        } define;

        struct {
            GString *identifier;
            GString *body;

            // An array of parameters, each is represented as `GString *`.
            GArray *parameters;
        } define_functional;

        struct {
            GString *content;
        } another;
    } data;
} preprocessor_lexeme_t;

void preprocessor_lexeme_free(preprocessor_lexeme_t lexeme);

const char *preprocessor_lexeme_kind_stringify(preprocessor_lexeme_kind_t kind);

GArray *preprocessor(const char *source);

#endif // GRIZZLY_PARSER_PREPROCESSOR_H