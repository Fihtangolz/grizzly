#include "ast_tree.h"
#include <stdlib.h>

#define node_constructor(type, type_name, node_type_val, node_init)  \
    type type_name ## _t* new_ ## type_name () { \
        type type_name ## _t* node = malloc(sizeof(type type_name ## _t));    \
        node->node_type = node_type_val; \
        (node_init); \
        return node;    \
    }  \

node_constructor(struct, translation_unit, TRANSLATION_UNIT, {
    node->static_asserts = g_list_alloc();
})
node_constructor(struct, pointer, POINTER,{})
node_constructor(struct, float_literal, FLOAT_CONST_STMT, {})
node_constructor(struct, enum_specifier, ENUMERATION, {})
node_constructor(struct, struct, STRUCTURE, {})
node_constructor(struct, union, UNION, {})
node_constructor(struct, initializer_list, INITILIAZER_LIST, {})
node_constructor(struct, compound_statement, COMPOUND_STMT, {})
node_constructor(struct, compound_literal, COMPOUND_LITERAL, {})
node_constructor(struct, do_while_stmt, DO_WHILE_STMT, {})
node_constructor(struct, for_stmt, FOR_STMT, {})
node_constructor(struct, while_stmt, WHILE_STMT, {})
node_constructor(struct, goto_stmt, GOTO_STMT, {})
node_constructor(struct, continue_stmt, CONTINUE_STMT, {})
node_constructor(struct, break_stmt, BREAK_STMT, {})
node_constructor(struct, static_assert, STATIC_ASSERT, {})
node_constructor(struct, labeled_stmt, LABELED_STMT, {})
node_constructor(struct, default_stmt, DEFAULT_STMT, {})
node_constructor(struct, case_stmt, CASE_STMT, {})
node_constructor(struct, return_stmt, RET_STMT, {})
node_constructor(struct, if_stmt, IF_STMT, {})
node_constructor(struct, if_else_stmt, IF_ELSE_STMT, {})
node_constructor(struct, switch_stm, SWITCH_STMT, {})
node_constructor(struct, generic_selection, GENERIC_EXPR, {})
node_constructor(struct, identifier, IDENTIFIER_STMT, {})
node_constructor(struct, str_literal, STR_CONST_STMT, {})
node_constructor(struct, int_literal, INT_CONST_STMT, {})






