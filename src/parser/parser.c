#include <stdbool.h>
#include <setjmp.h>
#include <string.h>
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

static bool is_starts_with(const char * restrict string, const char *restrict prefix) {
    return strncmp(string, prefix, strlen(prefix)) == 0;
}

void skip_space(const char **str) {
    while((**str) == ' ' || (**str) == '\n'){
        ++(*str);
    }
}

bool is_assignment_operator(const char* str) {
    const char * const patterns[] = {
        "*=",
        "/=",
        "%=",
        "+=",
        "-=",
        "<<=",
        ">>=",
        "&=",
        "^=",
        "|=",
    };

    for(int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++){
        if (is_starts_with(str, patterns[i])) {
            return true;
        }
    }

    return false;
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
    const char *const  patterns[] = {
            "++",
            "--",
    };
}

bool is_unary_operator(const char* str) {
    const char patterns[] = {
            '&',
            '*',
            '+',
            '-',
            '~',
            '!',
    };

    for(int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
        if (str[0] == patterns[i]) {
            return true;
        }
    }

    return false;
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
    bool flag = strcmp(str, "_Alignas");
    bool type_name = is_type_name();
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
    const char *pattern = "_Generic";
    bool flag1 = is_starts_with(str, pattern);
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

        "default";
        ':';
        is_assignment_expression(&str);

    } //TODO: если есть ',' то снова попытка считать
    skip_space(&str);
    if(*str != ')') {
        //TODO: ошибка
    }
}

struct enum_specifier_t* is_enum_specifier(const char* str) {
    const char * const pattern = "enum";
    bool flag1 = is_starts_with(str, pattern);
    str += strlen(pattern);
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

        if (is_starts_with(ptr, "//")) {
            ol_commnet = true;
        }

        if (ol_commnet && *ptr == '\n') {
            ol_commnet = false;
        }

        if (is_starts_with(ptr, "/*")) {
            ml_comment = true;
        }

        if (ml_comment && is_starts_with(ptr, "*/")) {
            ml_comment = false;
        }
    }
}

bool is_s_char_sequence() {

}

struct str_literal_t* is_string_literal(const char** str) {
    typedef struct {
        const char *pattern;
        enum str_literal_prefix_t type_qualifier;
    } compliance_t;

    compliance_t patterns[] = {
            {
                    "u8",
                    STR_PREF_U8
            },
            {
                    "u",
                    STR_PREF_LC_U,
            },
            {
                    "U",
                    STR_PREF_UC_U
            },
            {
                    "L",
                    STR_PREF_L
            }
    };

    enum str_literal_prefix_t pref = STR_PREF_NONE;
    for(int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
        if(is_starts_with(str, patterns[i].pattern)) {
            pref = patterns[i].type_qualifier;
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
    const char *pattern = "_Static_assert";

    if(is_starts_with(str, pattern)){
        return NULL;
    }
    str+=strlen(pattern);
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
        const char *pattern;
        enum type_qualifier_t type_qualifier;
    } compliance_t;

    compliance_t patterns[] = {
        {
            "const",
            CONST_QUALIFIER
        },
        {
            "restrict",
            RESTRICT_QUALIFIER,
        },
        {
            "volatile",
            VOLATILE_QUALIFIER
        },
        {
            "_Atomic",
            ATOMIC_QUALIFIER
        }
    };

    for(int i = 0; i < sizeof(patterns)/sizeof(patterns[0]); i++){
        if(is_starts_with(str, patterns[i].pattern)) {
            enum type_qualifier_t* v = malloc(sizeof(enum type_qualifier_t));
            (*v) = patterns[i].type_qualifier;
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
        const char *pattern;
        enum storage_specifier_t storage_class_specifier;
    } compliance_t;

    compliance_t patterns[] = {
            {
                "typedef",
                TYPEDEF_SPECIFIER,
            },
            {
                "extern",
                EXTERN_SPECIFIER,
            },
            {
                "static",
                STATIC_SPECIFIER,
            },
            {
                "_Thread_local",
                THREAD_LOCAL_SPECIFIER,
            },
            {
                "auto",
                AUTO_SPECIFIER,
            },
            {
                "register",
                REGISTER_SPECIFIER
            }
    };

    for(int i = 0; i < sizeof(patterns)/sizeof(patterns[0]); i++){
        if(is_starts_with(str, patterns[i].pattern)) {
            enum storage_specifier_t* v = malloc(sizeof(enum storage_specifier_t));
            (*v) = patterns[i].storage_class_specifier;
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
