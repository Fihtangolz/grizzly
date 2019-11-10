#include "base_parser.h"
#include "tokenizer.h"
#include <string.h>
#include <stdlib.h>

static void skip_space(struct parser_t* parser) {
    while(((*parser->cursor)) == ' ' || ((*parser->cursor)) == '\n'){
        parser->cursor++;
    }
}

//static void is_comment(const char** str) {
//    for(const char* ptr = str; *ptr != '\0'; ++ptr) {
//        bool ol_commnet = false;
//        bool ml_comment = false;
//
//        if (is_starts_with(ptr, "//")) {
//            ol_commnet = true;
//        }
//
//        if (ol_commnet && *ptr == '\n') {
//            ol_commnet = false;
//        }
//
//        if (is_starts_with(ptr, "/*")) {
//            ml_comment = true;
//        }
//
//        if (ml_comment && is_starts_with(ptr, "*/")) {
//            ml_comment = false;
//        }
//    }
//}

static char* is_identifier(struct parser_t* parser) {
    char digit[] = "0123456789";
    char nondigit[] = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(char* s = digit; s != '\0'; ++s){

    }

    return NULL;
}

//static char* is_s_char_sequence() {
//    //TODO: not implemented escape-sequence
//    char* start = parser.cursor;
//    while(true) {
//        if((*parser.cursor) == '\"' || (*parser.cursor) == '\\' || (*parser.cursor) == '\n') {
//            char* ret = NULL;
//            size_t len =  parser.cursor - start;
//            if(len) {
//                ret = malloc(len+1);
//                memcpy(ret, start, len);
//                ret[len] = '\0';
//            }
//
//            return ret;
//        }
//        parser.cursor++;
//    }
//}
//
//void is_string_literal() {
//    typedef struct {
//        const char *pattern;
//        enum str_literal_prefix_t type_qualifier;
//    } compliance_t;
//
//    compliance_t patterns[] = {
//            {
//                    "u8",
//                    STR_PREF_U8
//            },
//            {
//                    "u",
//                    STR_PREF_LC_U,
//            },
//            {
//                    "U",
//                    STR_PREF_UC_U
//            },
//            {
//                    "L",
//                    STR_PREF_L
//            }
//    };
//
//    enum str_literal_prefix_t pref = STR_PREF_NONE;
//    for(int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
//        if(is_starts_with(parser.cursor, patterns[i].pattern)) {
//            pref = patterns[i].type_qualifier;
//        }
//    }
//
//    if((*parser.cursor) != '\"') {
//        return NULL;
//    }
//    parser.cursor++;
//    char* scs = is_s_char_sequence();
//    if((*parser.cursor) != '\"') {
//        return NULL;
//    }
//}

char* token_type_stringify(struct token_t* token) {
    switch(token->token_type) {
        case TOK_IDENTIFIER:
            return "TOK_IDENTIFIER";
        case TOK_AUTO:
            return "TOK_AUTO";
        case TOK_BREAK:
            return "TOK_BREAK";
        case TOK_CASE:
            return "TOK_CASE";
        case TOK_CHAR:
            return "TOK_CHAR";
        case TOK_CONST:
            return "TOK_CONST";
        case TOK_CONTINUE:
            return "TOK_CONTINUE";
        case TOK_DEFAULT:
            return "TOK_DEFAULT";
        case TOK_DO:
            return "TOK_DO";
        case TOK_DOUBLE:
            return "TOK_DOUBLE";
        case TOK_ELSE:
            return "TOK_ELSE";
        case TOK_ENUM:
            return "TOK_ENUM";
        case TOK_EXTERN:
            return "TOK_EXTERN";
        case TOK_FLOAT:
            return "TOK_FLOAT";
        case TOK_FOR:
            return "TOK_FOR";
        case TOK_GOTO:
            return "TOK_GOTO";
        case TOK_IF:
            return "TOK_IF";
        case TOK_INLINE:
            return "TOK_INLINE";
        case TOK_INT:
            return "TOK_INT";
        case TOK_LONG:
            return "TOK_LONG";
        case TOK_REGISTER:
            return "TOK_REGISTER";
        case TOK_RESTRICT:
            return "TOK_RESTRICT";
        case TOK_RETURN:
            return "TOK_RETURN";
        case TOK_SHORT:
            return "TOK_SHORT";
        case TOK_SIGNED:
            return "TOK_SIGNED";
        case TOK_SIZEOF:
            return "TOK_SIZEOF";
        case TOK_STATIC:
            return "TOK_STATIC";
        case TOK_STRUCT:
            return "TOK_STRUCT";
        case TOK_SWITCH:
            return "TOK_SWITCH";
        case TOK_TYPEDEF:
            return "TOK_TYPEDEF";
        case TOK_UNION:
            return "TOK_UNION";
        case TOK_UNSIGNED:
            return "TOK_UNSIGNED";
        case TOK_VOID:
            return "TOK_VOID";
        case TOK_VOLATILE:
            return "TOK_VOLATILE";
        case TOK_WHILE:
            return "TOK_WHILE";
        case TOK_ALIGNAS:
            return "TOK_ALIGNAS";
        case TOK_ALIGNOF:
            return "TOK_ALIGNOF";
        case TOK_ATOMIC:
            return "TOK_ATOMIC";
        case TOK_BOOL:
            return "TOK_BOOL";
        case TOK_COMPLEX:
            return "TOK_COMPLEX";
        case TOK_GENERIC:
            return "TOK_GENERIC";
        case TOK_IMAGINARY:
            return "TOK_IMAGINARY";
        case TOK_NORETURN:
            return "TOK_NORETURN";
        case TOK_STATIC_ASSERT:
            return "TOK_STATIC_ASSERT";
        case TOK_THREAD_LOCAL:
            return "TOK_THREAD_LOCAL";
        case TOK_LEFT_SQUARED_BRACKET:
            return "TOK_LEFT_SQUARED_BRACKET";
        case TOK_RIGHT_SQUARED_BRACKET:
            return "TOK_RIGHT_SQUARED_BRACKET";
        case TOK_LEFT_ROUND_BRACKET:
            return "TOK_LEFT_ROUND_BRACKET";
        case TOK_RIGHT_ROUND_BRACKET:
            return "TOK_RIGHT_ROUND_BRACKET";
        case TOK_LEFT_BRACE:
            return "TOK_LEFT_BRACE";
        case TOK_RIGHT_BRACE:
            return "TOK_RIGHT_BRACE";
        case TOK_SEMICOLON:
            return "TOK_SEMICOLON";
        case TOK_COLON:
            return "TOK_COLON";
        case TOK_COMMA:
            return "TOK_COMMA";
        case TOK_PLUS:
            return "TOK_PLUS";
        case TOK_MINUS:
            return "TOK_MINUS";
        case TOK_DOT:
            return "TOK_DOT";
        case TOK_THREE_DOT:
            return "TOK_THREE_DOT";
        case TOK_ARROW:
            return "TOK_ARROW";
        case TOK_W_PLUS:
            return "TOK_W_PLUS";
        case TOK_W_MINUS:
            return "TOK_W_MINUS";
        case TOK_STAR:
            return "TOK_STAR";
        case TOK_EQ:
            return "TOK_EQ";
        case TOK_STAR_EQ:
            return "TOK_STAR_EQ";
        case TOK_LINE:
            return "TOK_LINE";
        case TOK_W_LINE:
            return "TOK_W_LINE";
        case TOK_QUESTION_MARK:
            return "TOK_QUESTION_MARK";
        case TOK_AMPERSAND:
            return "TOK_AMPERSAND";
        case TOK_AMPERSAND_EQ:
            return "TOK_AMPERSAND_EQ";
        case TOK_LINE_EQ:
            return "TOK_LINE_EQ";
        case TOK_RIGHT_SIFT_EQ:
            return "TOK_RIGHT_SIFT_EQ";
        case TOK_WAVE:
            return "TOK_WAVE";
        case TOK_EXCLAMATION_MARK:
            return "TOK_EXCLAMATION_MARK";
        case TOK_GREATER:
            return "TOK_GREATER";
        case TOK_SMALLER:
            return "TOK_SMALLER";
        case TOK_MINUS_EQ:
            return "TOK_MINUS_EQ";
        case TOK_PLUS_EQ:
            return "TOK_PLUS_EQ";
        case TOK_LEFT_SHIFT_EQ:
            return "TOK_LEFT_SHIFT_EQ";
        case TOK_MOD_EQ:
            return "TOK_MOD_EQ";
        case TOK_MOD:
            return "TOK_MOD";
        case TOK_LEFT_SHIFT:
            return "TOK_LEFT_SHIFT";
        case TOK_SLASH:
            return "TOK_SLASH";
        case TOK_SMALLER_EQ:
            return "TOK_SMALLER_EQ";
        case TOK_GREATER_EQ:
            return "TOK_GREATER_EQ";
        case TOK_W_EQ:
            return "TOK_W_EQ";
        case TOK_NOT_EQ:
            return "TOK_NOT_EQ";
        case TOK_CARET:
            return "TOK_CARET";
        case TOK_W_AMPERSAND:
            return "TOK_W_AMPERSAND";
        case TOK_SLASH_EQ:
            return "TOK_SLASH_EQ";
        case TOK_CARET_EQ:
            return "TOK_CARET_EQ";
        case TOK_SHARP:
            return "TOK_SHARP";
        case TOK_W_SHARP:
            return "TOK_W_SHARP";
    }
}

void debug_log(struct token_t* token) {
    printf("%s \n", token_type_stringify(token));
}

struct token_t* get_next_token(struct parser_t* parser) {
    skip_space(parser);

    typedef struct {
        char *pattern;
        enum token_type token_type;
    } compliance_t;

    char* start_pos = parser->cursor;
    compliance_t patterns[] = {
            {"[",TOK_LEFT_SQUARED_BRACKET},
            {"]",  TOK_RIGHT_SQUARED_BRACKET},
            {"(",  TOK_LEFT_ROUND_BRACKET},
            {")",  TOK_RIGHT_ROUND_BRACKET},
            {"{",  TOK_LEFT_BRACE},
            {"}",  TOK_RIGHT_BRACE},
            {".",  TOK_DOT},
            {"->", TOK_ARROW},
            {"++", TOK_W_PLUS},
            {"--", TOK_W_MINUS},
            {"&",  TOK_AMPERSAND},
            {"*",  TOK_STAR},
            {"+",  TOK_PLUS},
            {"-",  TOK_MINUS},
            {"~",  TOK_WAVE},
            {"!",  TOK_EXCLAMATION_MARK},
            {"/",  TOK_SLASH},
            {"%",  TOK_MOD},
            {"<<", TOK_LEFT_SHIFT},
            {"<",  TOK_SMALLER},
            {">",   TOK_GREATER},
            {"<=",  TOK_SMALLER_EQ},
            {">=",  TOK_GREATER_EQ},
            {"==",  TOK_W_EQ},
            {"!=",  TOK_NOT_EQ},
            {"^",   TOK_CARET},
            {"|",   TOK_LINE},
            {"&&",  TOK_W_AMPERSAND},
            {"||",  TOK_W_LINE},
            {"?",   TOK_QUESTION_MARK},
            {":",   TOK_COLON},
            {";",   TOK_SEMICOLON},
            {"...", TOK_THREE_DOT},
            {"=",   TOK_EQ},
            {"*=",  TOK_STAR_EQ},
            {"/=",  TOK_SLASH_EQ},
            {"%=",  TOK_MOD_EQ},
            {"+=",  TOK_PLUS_EQ},
            {"-=",  TOK_MINUS_EQ},
            {"<<=", TOK_LEFT_SHIFT_EQ},
            {">>=", TOK_RIGHT_SIFT_EQ},
            {"&=",  TOK_AMPERSAND_EQ},
            {"^=", TOK_CARET_EQ},
            {"|=",  TOK_LINE_EQ},
            {",",   TOK_COMMA },
            {"#", TOK_SHARP},
            {"##", TOK_W_SHARP},
            {"auto", TOK_AUTO},
            {"break", TOK_BREAK},
            {"case", TOK_CASE},
            {"char", TOK_CHAR},
            {"const", TOK_CONST},
            {"continue", TOK_CONTINUE},
            {"default", TOK_DEFAULT},
            {"do", TOK_DO},
            {"double", TOK_DOUBLE},
            {"else", TOK_ELSE},
            {"enum", TOK_ENUM},
            {"extern", TOK_EXTERN},
            {"float", TOK_FLOAT},
            {"for", TOK_FOR},
            {"goto", TOK_GOTO},
            {"if", TOK_IF},
            {"inline", TOK_INLINE},
            {"int", TOK_INT},
            {"long", TOK_LONG},
            {"register", TOK_REGISTER},
            {"restrict", TOK_RESTRICT},
            {"return", TOK_RETURN},
            {"short", TOK_SHORT},
            {"signed", TOK_SIGNED},
            {"sizeof", TOK_SIZEOF},
            {"static", TOK_STATIC},
            {"struct", TOK_STRUCT},
            {"switch", TOK_SWITCH},
            {"typedef", TOK_TYPEDEF},
            {"union", TOK_UNION},
            {"unsigned", TOK_UNSIGNED},
            {"void", TOK_VOID},
            {"volatile", TOK_VOLATILE},
            {"while", TOK_WHILE},
            {"_Alignas", TOK_ALIGNAS},
            {"_Alignof", TOK_ALIGNOF},
            {"_Atomic", TOK_ATOMIC},
            {"_Bool", TOK_BOOL},
            {"_Complex", TOK_COMPLEX},
            {"_Generic", TOK_GENERIC},
            {"_Imaginary", TOK_IMAGINARY},
            {"_Noreturn",  TOK_NORETURN},
            {"_Static_assert", TOK_STATIC_ASSERT},
            {"_Thread_local", TOK_THREAD_LOCAL},
    };

    enum token_type token_type = 9999;
    for(int i = 0; i < sizeof(patterns) / sizeof(compliance_t); i++) {
        if(!strncmp(parser->cursor, patterns[i].pattern, strlen(patterns[i].pattern))) {
            token_type = patterns[i].token_type;
            parser->cursor+=strlen(patterns[i].pattern);
            break;
        }
    }

    is_identifier(parser);

    struct token_t* token = malloc(sizeof(struct token_t));
    token->token_type = token_type;
    token->line_slice.star_pos = start_pos;
    token->line_slice.end_pos = parser->cursor;

    return token;
}