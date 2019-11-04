#include "ast_tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <gmodule.h>

struct callbacks {
    void(*handler_int_literal)(struct int_literal_t*);
    void(*handler_float_literal)(struct float_literal_t*);
    void(*handler_char_literal)(struct char_literal_t*);
    void(*handler_str_literal)(struct str_literal_t*);
    void(*handler_if_stmt)(struct if_stmt_t*);
    void(*handler_if_else_stmt)(struct if_else_stmt_t*);
    void(*handler_switch_stmt)(struct switch_stm_t*);
    void(*handler_initializer_list)(struct initializer_list_t*);
    void(*handler_generic_selection)(struct generic_selection_t*);
    void(*handler_translation_unit)(struct translation_unit_t*);
    void(*handler_alignment_specifier)(struct alignment_specifier_t*);
    void(*handler_enum_specifier)(struct enum_specifier_t*);
    void(*handler_union)(struct union_t*);
    void(*handler_struct)(struct struct_t*);
    void(*handler_identifier)(struct identifier_t*);
    void(*handler_for_stmt)(struct for_stmt_t*);
    void(*handler_compound_literal)(struct compound_literal_t*);
    void(*handler_ternary_operator)(struct ternary_operator_t*);
    void(*handler_unary_operator)(struct unary_operator_t*);
    void(*handler_binary_operator)(struct binary_operator_t*);
    void(*handler_compound_stmt)(struct compound_statement_t*);
    void(*handler_static_assert)(struct static_assert_t*);
};

void cast_to(const struct base_node_t* bn, struct callbacks* cb) {
    switch(bn->node_type) {
        case FOR_STMT: {
            struct for_stmt_t* fs = (struct for_stmt_t*)bn;
            cb->handler_for_stmt(fs);
            break;
        }

        case IDENTIFIER_STMT: {
            struct identifier_t* id = (struct identifier_t*)bn;
            cb->handler_identifier(id);
            break;
        }

        case COMPOUND_STMT: {
            struct compound_literal_t* cl = (struct compound_statement_t*)bn;
            cb->handler_compound_literal(cl);
            break;
        }

        case COMPOUND_LITERAL: {
            struct compound_statement_t* cs = (struct compound_statement_t*)bn;
            cb->handler_compound_stmt(cs);
            break;
        }

        case STRUCTURE: {
            struct struct_t* st = (struct struct_t*)bn;
            cb->handler_struct(st);
            break;
        }

        case UNION: {
            struct union_t* un = (struct union_t*)bn;
            cb->handler_union(un);
            break;
        }

        case ENUMERATION: {
            struct enum_specifier_t* es = (struct enum_specifier_t*)bn;
            cb->handler_enum_specifier(es);
            break;
        }

        case ALIGNMENT_SPEC: {
            struct alignment_specifier_t* as = (struct alignment_specifier_t*)bn;
            cb->handler_alignment_specifier(as);
            break;
        }

        case TRANSLATION_UNIT: {
            struct translation_unit_t* tu = (struct translation_unit_t*)bn;
            cb->handler_translation_unit(tu);
            break;
        }

        case GENERIC_EXPR: {
            struct generic_selection_t* gs = (struct generic_selection_t*)bn;
            cb->handler_generic_selection(gs);
            break;
        }

        case STATIC_ASSERT: {
            struct static_assert_t* sa = (struct static_assert_t*)bn;
            cb->handler_static_assert(sa);
            break;
        }

        case INITILIAZER_LIST: {
            struct initializer_list_t* il = (struct initializer_list_t*)bn;
            cb->handler_initializer_list(il);
            break;
        }

        case INT_CONST_STMT: {
            struct int_literal_t* il = (struct int_literal_t*)bn;
            cb->handler_int_literal(il);
            break;
        }

        case FLOAT_CONST_STMT: {
            struct float_literal_t* fl = (struct float_literal_t*)bn;
            cb->handler_float_literal(fl);
            break;
        }

        case CHAR_CONST_STMT: {
            struct char_literal_t* cl = (struct char_literal_t*)bn;
            cb->handler_char_literal(cl);
            break;
        }

        case STR_CONST_STMT: {
            struct str_literal_t* sl = (struct str_literal_t*)bn;
            cb->handler_str_literal(sl);
            break;
        }

        case IF_STMT: {
            struct if_stmt_t* is = (struct if_stmt_t*)bn;
            cb->handler_if_stmt(is);
            break;
        }

        case IF_ELSE_STMT: {
            struct if_else_stmt_t* ies = (struct if_else_stmt_t*)bn;
            cb->handler_if_else_stmt(ies);
            break;
        }

        case SWITCH_STMT: {
            struct switch_stm_t* ss = (struct switch_stm_t*)bn;
            cb->handler_switch_stmt(ss);
            break;
        }

        case BASIC_ASSIGNMENT:
        case ADDITION_ASSIGNMENT:
        case SUBTRACTION_ASSIGNMENT:
        case MULTIPLICATION_ASSIGNMENT:
        case DIVISION_ASSIGNMENT:
        case MODULO_ASSIGNMENT:
        case BITWISE_AND_ASSIGNMENT:
        case BITWISE_OR_ASSIGNMENT:
        case BITWISE_XOR_ASSIGNMENT:
        case BITWISE_LEFT_SHIFT_ASSIGNMENT:
        case BITWISE_RIGHT_SHIFT_ASSIGNMENT:
        case ADDITION:
        case SUBTRACTION:
        case PRODUCT:
        case DIVISION:
        case MODULO:
        case BITWISE_AND:
        case BITWISE_OR:
        case BITWISE_XOR:
        case BITWISE_LEFT_SHIFT:
        case BITWISE_RIGHT_SHIFT:
        case LOGICAL_AND:
        case LOGICAL_OR:
        case EQUAL_TO:
        case NOT_EQUAL_TO:
        case LESS_THAN:
        case GREATER_THAN:
        case LESS_THAN_OR_EQUAL_TO:
        case GREATER_THAN_OR_EQUAL_TO:
        case ARRAY_SUBSCRIPT:
        case MEMBER_ACCESS:
        case MEMBER_ACCESS_THROUGH_POINTER:
        case COMMA_OPERATOR:
        case TYPE_CAST: {
            struct binary_operator_t* bo = (struct binary_operator_t*)bn;
            cb->handler_binary_operator(bo);
            break;
        }

        case POSTFIX_INCREMENT:
        case POSTFIX_DECREMENT:
        case PREFIX_INCREMENT:
        case PREFIX_DECREMENT:
        case UNARY_PLUS:
        case UNARY_MINUS:
        case BITWISE_NOT:
        case LOGICAL_NOT:
        case POINTER_DEREFERENCE:
        case ADDRESS_OF:
        case SIZEOF_OPERATOR:
        case ALIGNOF_OPERATOR: {
            struct unary_operator_t* uo = (struct unary_operator_t*)bn;
            cb->handler_unary_operator(uo);
            break;
        }

        case FUNCTION_CALL: {
            //TODO
            break;
        }

        case CONDITIONAL_OPERATOR: {
            struct ternary_operator_t* to = (struct ternary_operator_t*)bn;
            cb->handler_ternary_operator(to);
            break;
        }
    }
}

void filler_translation_unit(struct translation_unit_t* tu) {
//    tu->enum_defs;
    tu->func_decs;
//    tu->func_defs;
    tu->struct_decs;
    tu->struct_defs;
    tu->union_decs;
    tu->union_defs;
    tu->var_decs;
    tu->var_defs;
}

void filler_if_stmt(struct if_stmt_t* is) {
    is->expr;
    is->stmt;
};

void filler_if_else_stmt(struct if_else_stmt_t* ies) {
    ies->expr;
    ies->if_stmt;
    ies->else_stmt;
}

struct callbacks cr = {
        .handler_translation_unit = filler_translation_unit,
        .handler_if_stmt = filler_if_stmt,
        .handler_if_else_stmt = filler_if_else_stmt,
};

//TODO: add matcher
//TODO: add route to node
//TODO: if we kwon road - lenght
void ast_visitor(const struct base_node_t* bn) {
    GQueue* queue = g_queue_new();
    g_queue_push_tail(queue, bn);

    struct base_node_t* cur;
    while(g_queue_is_empty(queue)) {
        cur = g_queue_pop_tail(queue);
        cast_to(cur, &cr);
    }

    g_queue_free(queue);
}

