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

void parse(const char* str) {
    for(const char* ptr = str; *ptr != '\0'; ++ptr){
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

        
    }
}