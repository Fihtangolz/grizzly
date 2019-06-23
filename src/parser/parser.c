#include <unistring/stdbool.h>
#include <ntsid.h>
#include <yara.h>
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

generic_selection_t* is_generic_selection(const char* str) {
    pstring_t a = {8, (char[]){'_', 'G','e','n','e','r','i','c'}};
    bool flag1 = memcpr(str, a.size, a.body);
    skip_space(&str);
    if(*str != '(') {
        //TODO: ошибка
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

enum_t* is_enum_specifier(const char* str) {
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

bool is_storage_class_specifier() {
    pstring_t a = {7, (char[]){'t', 'y', 'p', 'e', 'd', 'e', 'f'}};
    pstring_t a1 = {6, (char[]){'e', 'x', 't', 'e', 'r', 'n'}};
    pstring_t a2 = {6, (char[]){'s', 't', 'a', 't', 'i', 'c'}};
    pstring_t a3 = {13, (char[]){'_', 'T', 'h', 'r', 'e', 'a', 'd', '_', 'l', 'o', 'c', 'a', 'l'}};
    pstring_t a4 = {4, (char[]){'a', 'u', 't', 'o'}};
    pstring_t a5 = {8, (char[]){'r', 'e', 'g', 'i', 's', 't', 'e', 'r'}};

}

bool is_string_literal() {
    //encoding-prefix_opt
    pstring_t pref_u8 = {2, (char[]){'u', '8'}};
    pstring_t pref_u = {1, (char[]){'u'}};
    pstring_t pref_U = {1, (char[]){'U'}};
    pstring_t pref_L = {1, (char[]){'L'}};
    '\"';
    //s-char-sequence_opt
    '\"';
}

static_assertion_t* if_static_assert_declaration() {
    pstring_t sassert = {14, (char[]){'_', 'S', 't', 'a', 't', 'i', 'c', '_', 'a', 's', 's', 'e', 'r', 't'}};
     '(';
    is_constant_expression();
    ',';
    is_string_literal();
    ')';
    ';';

    return NULL; //TODO
}

type_qualifier_t* is_type_qualifier(const char* str) {
    typedef struct {
        pstring_t pattern;
        type_qualifier_t type_qualifier;
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
            return &p->type_qualifier;
        }
    }

    return NULL;
}

bool is_pointer(const char** str) {
    '*';
    type_qualifier_t* type_qualifier = is_type_qualifier(str); //TODO: optional
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

bool is_function_defenition() {

}

bool is_external_declaration(const char* str) {
    pstring_t a = {8, (char[]){'e','n','u','m'}};
    bool flag1 = memcpr(str, a.size, a.body);
    char* identifier = is_identifier(str);
    if(!identifier) {

    }
}

bool is_translation_unit(const char* str) {
    is_external_declaration(str);
    //translation-unit external-declaration
}

ast_tree_t parse(const char* str) {
    
}