#ifndef GRIZZLY_TOKENIZER_H
#define GRIZZLY_TOKENIZER_H

enum token_type {
    TOK_IDENTIFIER,

    TOK_AUTO,
    TOK_BREAK,
    TOK_CASE,
    TOK_CHAR,
    TOK_CONST,
    TOK_CONTINUE,
    TOK_DEFAULT,
    TOK_DO,
    TOK_DOUBLE,
    TOK_ELSE,
    TOK_ENUM,
    TOK_EXTERN,
    TOK_FLOAT,
    TOK_FOR,
    TOK_GOTO,
    TOK_IF,
    TOK_INLINE,
    TOK_INT,
    TOK_LONG,
    TOK_REGISTER,
    TOK_RESTRICT,
    TOK_RETURN,
    TOK_SHORT,
    TOK_SIGNED,
    TOK_SIZEOF,
    TOK_STATIC,
    TOK_STRUCT,
    TOK_SWITCH,
    TOK_TYPEDEF,
    TOK_UNION,
    TOK_UNSIGNED,
    TOK_VOID,
    TOK_VOLATILE,
    TOK_WHILE,
    TOK_ALIGNAS,
    TOK_ALIGNOF,
    TOK_ATOMIC,
    TOK_BOOL,
    TOK_COMPLEX,
    TOK_GENERIC,
    TOK_IMAGINARY,
    TOK_NORETURN,
    TOK_STATIC_ASSERT,
    TOK_THREAD_LOCAL,

    TOK_LEFT_SQUARED_BRACKET, //[
    TOK_RIGHT_SQUARED_BRACKET, //]
    TOK_LEFT_ROUND_BRACKET, //(
    TOK_RIGHT_ROUND_BRACKET, //)
    TOK_LEFT_BRACE, //{
    TOK_RIGHT_BRACE, //}
    TOK_SEMICOLON, //;
    TOK_COLON, //:
    TOK_COMMA, //,
    TOK_PLUS, //+
    TOK_MINUS, //-
    TOK_DOT, //.
    TOK_THREE_DOT, //...
    TOK_ARROW, //->
    TOK_W_PLUS, //++
    TOK_W_MINUS, //--
    TOK_STAR, //*
    TOK_EQ, //=
    TOK_STAR_EQ, //*=
    TOK_LINE, //|
    TOK_W_LINE, //||
    TOK_QUESTION_MARK, //?
    TOK_AMPERSAND, //&
    TOK_AMPERSAND_EQ, //&=
    TOK_LINE_EQ, //|=
    TOK_RIGHT_SIFT_EQ, //>>=
    TOK_WAVE, //~
    TOK_EXCLAMATION_MARK,
    TOK_GREATER,
    TOK_SMALLER,
    TOK_MINUS_EQ,
    TOK_PLUS_EQ,
    TOK_LEFT_SHIFT_EQ,
    TOK_MOD_EQ,
    TOK_MOD,
    TOK_LEFT_SHIFT,
    TOK_SLASH,
    TOK_SMALLER_EQ,
    TOK_GREATER_EQ,
    TOK_W_EQ,
    TOK_NOT_EQ,
    TOK_CARET,
    TOK_W_AMPERSAND,
    TOK_SLASH_EQ,
    TOK_CARET_EQ,
    TOK_SHARP,
    TOK_W_SHARP,
};

typedef struct {
    char* star_pos;
    char* end_pos;
} line_slice_t;

struct token_t {
    enum token_type token_type;
    line_slice_t line_slice;
};

struct token_t* get_next_token(struct parser_t* parser);
void debug_log(struct token_t*);

#endif //GRIZZLY_TOKENIZER_H
