#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../ast/ast_tree.h"
#include "base_parser.h"
#include "tokenizer.h"

//////////////////////////////////////////////////////////////////
//// Statements //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void is_statement() {
    void labeled_statement();
    void compound_statement();
    void expression_statement();
    void selection_statement();
    void iteration_statement();
    void jump_statement();
}

void labeled_statement() {
    TOK_IDENTIFIER; TOK_COLON; is_statement();
    TOK_CASE; /* constant-expression */ TOK_COLON; is_statement();
    TOK_DEFAULT; TOK_COLON; is_statement();
}

void compound_statement() {
    TOK_LEFT_BRACE;  /* block-item-list opt */ TOK_RIGHT_BRACE;
}

void block_item_list() {

}

void expression_statement() {
    /* expression opt */ TOK_SEMICOLON;
}

void block_item() {
    // declaration
    // statement
}

void selection_statement() {
    TOK_IF; TOK_LEFT_ROUND_BRACKET; /* expression */ TOK_RIGHT_ROUND_BRACKET; /* statement */
    TOK_IF; TOK_LEFT_ROUND_BRACKET; /* expression */ TOK_RIGHT_ROUND_BRACKET; /* statement */
    TOK_SWITCH; TOK_LEFT_ROUND_BRACKET; /* expression */ TOK_RIGHT_ROUND_BRACKET; /* statement */
}

void iteration_statement() {
    TOK_WHILE; TOK_LEFT_ROUND_BRACKET; /* expression */ TOK_RIGHT_ROUND_BRACKET; /* statement */
    TOK_DO; /* statement */ TOK_WHILE; TOK_LEFT_ROUND_BRACKET; /* expression */ TOK_RIGHT_ROUND_BRACKET; TOK_SEMICOLON;
    TOK_FOR; TOK_LEFT_ROUND_BRACKET; /* expression opt */ TOK_SEMICOLON; /* expression opt */ TOK_SEMICOLON; /* expression opt */ TOK_RIGHT_ROUND_BRACKET; /* statement */
    TOK_FOR; TOK_LEFT_ROUND_BRACKET; /* declaration expression opt */ TOK_SEMICOLON; /* expression opt */ TOK_RIGHT_ROUND_BRACKET; /* statement */
}

void jump_statement() {
    TOK_GOTO; TOK_IDENTIFIER; TOK_SEMICOLON;
    TOK_CONTINUE; TOK_SEMICOLON;
    TOK_BREAK; TOK_SEMICOLON;
    TOK_RETURN; /* expression opt */ TOK_SEMICOLON;
}

//////////////////////////////////////////////////////////////////
//// Declarations ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void declaration() {

}

void declaration_specifier() {

}

void init_declaration_list() {

}

struct translation_unit_t* parse(struct parser_t* parser, const char* target_file) {
    FILE* file = fopen(target_file, "r");
    if(!file) {
        ferror(file);
    }

    update_chunk(parser, file);
    while(true) {
        debug_log(get_next_token(parser));
    }
//    struct translation_unit_t* tu = parse_translation_unit();

    fclose(file);
    return NULL;
}
