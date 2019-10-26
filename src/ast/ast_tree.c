#include <stdbool.h>
#include "ast_tree.h"

//Restore implicit enum's constant values
void do_numbering(enum_specifier_t* target) {
    for(enumerator_t* cur_el = target->enumerator_list; cur_el != NULL; ++cur_el) {

    }
}

//bool is_constant_expression(const conditional_expression_t* target) {
//TODO: implementation
//}

