#include <stdbool.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>
#include "parser.h"
#include "../ast/ast_tree.h"


bool is_declaration(const char** str);
bool is_statement(const char** str);

typedef enum {
    PARSE_COMMENT,
    PARSE_FUNCTION_BODY,
} state_t;

// pars config
// drop comment
// malloc ast (if you dont need ast and just use simple visitors)
// set visitor for node
// allow drop identifiers table

typedef struct {
    bool drop_comment;
    bool drop_static_assert;
} config_t;

typedef struct {
    config_t config;
    state_t* states;
    jmp_buf checkpoint;
} parser_t;

bool memcpr(const void* src1, size_t size, const void* src2) {
    for(size_t i = 0; i < size; ++i){
        if(((u_int8_t*)src1)[i] != ((u_int8_t*)src2)[i]) {
            return false;
        }
    }

    return true;
}

//TODO: bor

typedef struct {
    int started_pos;
    int end_pos;
} line_slice_t;

typedef struct {
    char* file_name;
    line_slice_t line_slice;
    char* body;
} comment_t;

typedef struct {
    size_t size;
    char* body;
} pstring_t;


void skip_space(const char **str) {
    while((**str) == ' ' || (**str) == '\n'){
        ++(*str);
    }
}

bool is_assignment_operator(const char* str) {
    const pstring_t patterns[] = {
        (pstring_t){2, (char[]){'*','='}},
        (pstring_t){2, (char[]){'/','='}},
        (pstring_t){2, (char[]){'%','='}},
        (pstring_t){2, (char[]){'+','='}},
        (pstring_t){2, (char[]){'-','='}},
        (pstring_t){3, (char[]){'<','<','='}},
        (pstring_t){3, (char[]){'>','>','='}},
        (pstring_t){2, (char[]){'&','='}},
        (pstring_t){2, (char[]){'^','='}},
        (pstring_t){2, (char[]){'|','='}}
    };

    bool flag = false;
    for(const pstring_t* p = patterns; p < patterns+(sizeof(patterns)/sizeof(pstring_t)+1); ++p){
        flag = memcpr(str, p->size, p->body);
    }

    return flag;
}

bool is_type_specifier() {
    (char[]){'v', 'o', 'i', 'd'};
    (char[]){'c', 'h', 'a', 'r'};
    (char[]){'s', 'h', 'o', 'r', 't'};
    (char[]){'i', 'n', 't'};
    (char[]){'l', 'o', 'n', 'g'};
    (char[]){'f', 'l', 'o', 'a', 't'};
    (char[]){'d', 'o', 'u', 'b', 'l', 'e'};
    (char[]){'s', 'i', 'g', 'n', 'e', 'd'};
    (char[]){'u', 'n', 's', 'i', 'g', 'n', 'e', 'd'};
    (char[]){'_', 'B', 'o', 'o', 'l'};
    (char[]){'_', 'C', 'o', 'm', 'p', 'l', 'e', 'x'};
    (char[]){'_', 'I', 'm', 'a', 'g', 'i', 'n', 'a', 'r', 'y'};
}

bool is_unary_expression(const char* str) {
    const pstring_t patterns[] = {
            (pstring_t) {2, (char[]) {'+', '+'}},
            (pstring_t) {2, (char[]) {'-', '-'}},
    };
}

bool is_unary_operator(const char* str) {
    const pstring_t patterns[] = {
            (pstring_t){1, (char[]){'&'}},
            (pstring_t){1, (char[]){'*'}},
            (pstring_t){1, (char[]){'+'}},
            (pstring_t){1, (char[]){'-'}},
            (pstring_t){1, (char[]){'~'}},
            (pstring_t){1, (char[]){'!'}}
    };

    bool flag = false;
    for(const pstring_t* p = patterns; p < patterns+(sizeof(patterns)/sizeof(pstring_t)+1); ++p){
        flag = memcpr(str, p->size, p->body);
    }

    return flag;
}

bool is_primary_expression() {
    //TODO: "(" expression ")"
//    return is_dentifier() || is_constant() || is_string_literal() if_generic_selection();
}

bool is_postfix_expression(const char* str) {

}

bool is_type_name() {

}

bool is_constant_expression() {

}

bool is_alignment_specifier(const char* str) {
    pstring_t a = {8, (char[]){'_','A' ,'l','i','g','n','a','s'}};

    bool flag1 = memcpr(str, a.size, a.body);
    bool type_name = is_type_name();

    bool flag2 = memcpr(str, a.size, a.body);
    bool constant_expression = is_constant_expression();
}

bool declaration_specifier() {

}

//TODO: пересортировать строки проанализировав статистику исползования идентификаторов
char* is_identifier(const char** str) {
    char digit[] = "0123456789";
    char nondigit[] = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(char* s = digit; s != '\0'; ++s){

    }

    return NULL;
}

bool is_logical_OR_expression() {
    //logical-AND-expression
    //logical-OR-expression || logical-AND-expression
}

bool is_logical_AND_expression() {
    //inclusive-OR-expression
    //logical-AND-expression && inclusive-OR-expression
}

bool is_conditional_expression() {
    //logical-OR-expression
    //logical-OR-expression ? expression : conditional-expression
}

bool is_expression() {

}

bool is_assignment_expression(const char** str) {
    //conditional-expression
    //unary-expression assignment-operator assignment-expression
}

struct generic_selection_t* is_generic_selection(const char* str) {
    pstring_t a = {8, (char[]){'_', 'G','e','n','e','r','i','c'}};
    bool flag1 = memcpr(str, a.size, a.body);
    skip_space(&str);
    if(*str != '(') {
        return NULL;
    }
    skip_space(&str);
    is_assignment_expression(&str);
    skip_space(&str);
    ',';
    skip_space(&str);

    {
        is_type_name();
        ':';
        is_assignment_expression(&str);

        (pstring_t){7, (char[]){'d', 'e', 'f', 'a', 'u', 'l', 't'}};
        ':';
        is_assignment_expression(&str);

    } //TODO: если есть ',' то снова попытка считать
    skip_space(&str);
    if(*str != ')') {
        //TODO: ошибка
    }
}

struct enum_specifier_t* is_enum_specifier(const char* str) {
    pstring_t a = {4, (char[]){'e','n','u','m'}};
    bool flag1 = memcpr(str, a.size, a.body);
    str += a.size;
    if(!flag1) {
        return NULL;
    }

    skip_space(&str);
    char* identifier = is_identifier(&str);

    if(identifier) {
        //TODO: придумать что если дальше нет {
    }

    skip_space(&str);
    if((*str) != '{') {
        //TODO: something wrong
    }

    char* identifier2;
    do {
        skip_space(&str);

        is_identifier(&str); //enumeration-constant
        if((*str) == '=') {
            skip_space(&str);
            is_conditional_expression(); //constant-expression
        }

        skip_space(&str);
        if((*str) == ',') {

        }
        //TODO: add enum's element

        skip_space(&str);

        identifier2 = is_identifier(str); //если идентифер то движемся иначе ок
    } while(identifier2); //TODO:

    if((*str) != '}') {
        //TODO: something wrong
    }
}

void is_comment(const char** str) {
    for(const char* ptr = str; *ptr != '\0'; ++ptr) {
        bool ol_commnet = false;
        bool ml_comment = false;

        if (memcpr(ptr, 2, (char[]) {'/', '/'})) {
            ol_commnet = true;
        }

        if (ol_commnet && *ptr == '\n') {
            ol_commnet = false;
        }

        if (memcpr(ptr, 2, (char[]) {'/', '*'})) {
            ml_comment = true;
        }

        if (ml_comment && memcpr(ptr, 2, (char[]) {'*', '/'})) {
            ml_comment = false;
        }
    }
}

bool is_s_char_sequence() {

}

struct str_literal_t* is_string_literal(const char** str) {
    typedef struct {
        pstring_t pattern;
        enum str_literal_prefix_t type_qualifier;
    } compliance_t;

    compliance_t patterns[] = {
            {
                    {2, (char[]){'u', '8'}},
                    STR_PREF_U8
            },
            {
                    {1, (char[]){'u'}},
                    STR_PREF_LC_U,
            },
            {
                    {1, (char[]){'U'}},
                    STR_PREF_UC_U
            },
            {
                    {1, (char[]){'L'}},
                    STR_PREF_L
            }
    };

    enum str_literal_prefix_t pref = STR_PREF_NONE;
    for(const compliance_t* p = patterns; p < patterns+(sizeof(patterns)/sizeof(compliance_t)+1); ++p){
        if(memcpr(str, p->pattern.size, p->pattern.body)) {
            pref = p->type_qualifier;
        }
    }

    if((*str) != '\"') {
        return NULL;
    }
    is_s_char_sequence();
    if((*str) != '\"') {
        return NULL;
    }

    struct str_literal_t* sl = new_str_literal();
    sl->data;
    sl->prefix = pref;

    return sl;
}

struct static_assert_t* if_static_assert(const char* str) {
    pstring_t pattern = {14, (char[]){'_', 'S', 't', 'a', 't', 'i', 'c', '_', 'a', 's', 's', 'e', 'r', 't'}};
    if(!memcpr(str, pattern.size, pattern.body)){
        return NULL;
    }
    str+=pattern.size;
    if((*str) != '(') {
        return NULL;
    }
//    is_constant_expression();
    str++;
    if((*str) != ',') {
        return NULL;
    }
//    struct str_literal_t* sl = is_string_literal(str);
    str++;
    if((*str) != ')') {
        return NULL;
    }
    str++;
    if((*str) != ';') {
        return NULL;
    }

    struct static_assert_t* sa = new_static_assert();
//    sa->string_literal = sl;

    return sa;
}

enum type_qualifier_t* is_type_qualifier(const char** str) {
    typedef struct {
        pstring_t pattern;
        enum type_qualifier_t type_qualifier;
    } compliance_t;

    compliance_t patterns[] = {
        {
            {5, (char[]){'c', 'o', 'n', 's', 't'}},
            CONST_QUALIFIER
        },
        {
            {8, (char[]){'r', 'e', 's', 't', 'r', 'i', 'c', 't'}},
            RESTRICT_QUALIFIER,
        },
        {
            {8, (char[]){'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'}},
            VOLATILE_QUALIFIER
        },
        {
            {7, (char[]){'_', 'A', 't', 'o', 'm', 'i', 'c'}},
            ATOMIC_QUALIFIER
        }
    };

    for(const compliance_t* p = patterns; p < patterns+(sizeof(patterns)/sizeof(compliance_t)+1); ++p){
        if(memcpr(str, p->pattern.size, p->pattern.body)) {
            enum type_qualifier_t* v = malloc(sizeof(enum type_qualifier_t));
            (*v) = p->type_qualifier;
            return v;
        }
    }

    return NULL;
}

struct pointer_t* is_pointer(const char** str) {
    if(*str != '*') {
        return NULL;
    }
    enum type_qualifier_t* tq = is_type_qualifier(str);
    struct pointer_t* v = new_pointer();
    v->qualifier = tq;

    return v;
}

bool is_compound_statement(const char* str) {
    if(*str != '{') {
        return false;
    }
    skip_space(&str);
    bool declaration, statement;
    do {
        declaration = is_declaration(&str);
        statement = is_statement(&str); //TODO: если декларатор равен нулю
    } while(declaration || statement);
    if(*str != '}'){
        return false;
    }
}

bool is_statement(const char** str) {
    
}

bool is_declaration(const char** str) {
    
}

enum storage_specifier_t* is_storage_class_specifier(const char* str) {
    typedef struct {
        pstring_t pattern;
        enum storage_specifier_t storage_class_specifier;
    } compliance_t;

    compliance_t patterns[] = {
            {
                { 7, (char[]) {'t', 'y', 'p', 'e', 'd', 'e', 'f'}},
                TYPEDEF_SPECIFIER,
            },
            {
                { 6, (char[]) {'e', 'x', 't', 'e', 'r', 'n'}},
                EXTERN_SPECIFIER,
            },
            {
                { 6, (char[]) {'s', 't', 'a', 't', 'i', 'c'}},
                STATIC_SPECIFIER,
            },
            {
                { 13, (char[]) {'_', 'T', 'h', 'r', 'e', 'a', 'd', '_', 'l', 'o', 'c', 'a', 'l'}},
                THREAD_LOCAL_SPECIFIER,
            },
            {
                { 4, (char[]) {'a', 'u', 't', 'o'}},
                AUTO_SPECIFIER,
            },
            {
                { 8, (char[]) {'r', 'e', 'g', 'i', 's', 't', 'e', 'r'}},
                REGISTER_SPECIFIER
            }
    };

    for(const compliance_t* p = patterns; p < patterns+(sizeof(patterns)/sizeof(compliance_t)+1); ++p){
        if(memcpr(str, p->pattern.size, p->pattern.body)) {
            enum storage_specifier_t* v = malloc(sizeof(enum storage_specifier_t));
            (*v) = p->storage_class_specifier;
            return v;
        }
    }

    return NULL;
}

bool is_declaration_specifier() {
//    return is_storage_class_specifier() || is_type_specifier() || is_type_qualifier();
}

bool is_function_definition() {
//    return is_declaration_specifier(); is_declarator(); is_declaration(); is_compound_statement();
}

bool is_external_declaration(const char* str) {
    return is_function_definition(str) || is_declaration(str);
}

bool parse_translation_unit(const char* str) {
    while(is_external_declaration(str)){}
}

struct translation_unit_t* parse(const char* str) {
    struct translation_unit_t* tu = new_translation_unit();
    struct static_assert_t* sa = if_static_assert(str);
    if(sa) {
        g_list_append(tu->static_asserts, sa);
    }

    return tu;
}
