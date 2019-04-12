#include <unistring/stdbool.h>
#include <ntsid.h>
#include "parser.h"


typedef enum {
    PARSE_COMMENT
} state;

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
//file
//line slice
//comment
};

typedef struct {
    size_t size;
    char* body;
} pstring_t;

bool is_assignment_operator(const char* str) {
    const pstring_t ass[] = {
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
    for(const pstring_t* p = ass; p < ass+(sizeof(ass)/sizeof(pstring_t)+1); ++p){
        flag = memcpr(str, p->size, p->body);
    }

    return flag;
}

bool is_unary_expression(const char* str) {

}

bool is_postfix_expression(const char* str) {

}

void parse(const char* str) {
    for(const char* ptr = str; *ptr != '\0'; ++ptr) {
        bool ol_commnet = false;
        bool ml_comment = false;

        if(memcpr(ptr, 2, (char[]){'/', '/'})) {
            ol_commnet = true;
        }

        if(ol_commnet && *ptr == '\n'){
            ol_commnet = false;
        }

        if(memcpr(ptr, 2, (char[]){'/', '*'})) {
            ml_comment = true;
        }

        if(ml_comment && memcpr(ptr, 2, (char[]){'*', '/'})) {
            ml_comment = false;
        }

        //function-definition


        //type-specifier
        (char[]){'v', 'o', 'i', 'd'};
        (char[]){'c', 'h', 'a', 'r'};
        (char[]){'s', 'h', 'o', 'r', 't'};
        (char[]){'i', 'n', 't'};
        (char[]){'l', 'o', 'n', 'g'};
        (char[]){'f', 'l', 'o', 'a', 't'};
        (char[]){'d', 'o', 'u', 'b', 'l', 'e'};
        (char[]){'s', 'i', 'g', 'n', 'e', 'd'};
        (char[]){'u', 'n', 's', 'i', 'g', 'n', 'e', 'd'};
        // -- struct-or-union-specifier
        // -- enum-specifier
        // -- typedef-name


        //unary-operator
        (char[]){'&'};
        (char[]){'*'};
        (char[]){'+'};
        (char[]){'-'};
        (char[]){'~'};
        (char[]){'!'};

        //unary-expression

        //cast-expression
        // -- unary-expression
        //( <type-name> ) <cast-expression>

        //conditional-expression
        // -- logical-OR-expression
        // -- logical-OR-expression ? expression : conditional-expression

        is_assignment_operator(str);
    }
}