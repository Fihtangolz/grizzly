#include "ast_tree.h"
#include "stdio.h"

char* node_type_stringify(enum node_type_t nt) {
    switch(nt) {
        case IDENTIFIER_STMT:
            return "IDENTIFIER_STMT";
        case COMPOUND_STMT:
            return "COMPOUND_STMT";
        case COMPOUND_LITERAL:
            return "STRUCTURE";
        case UNION:
            return "UNION";
        case ENUMERATION:
            return "ENUMERATION";
        case ALIGNMENT_SPEC:
            return "TRANSLATION_UNIT";
        case GENERIC_EXPR:
            return "GENERIC_EXPR";
        case STATIC_ASSERT:
            return "STATIC_ASSERT";
        case INITILIAZER_LIST:
            return "INITILIAZER_LIST";
        case INT_CONST_STMT:
            return "INT_CONST_STMT";
        case FLOAT_CONST_STMT:
            return "FLOAT_CONST_STMT";
        case CHAR_CONST_STMT:
            return "CHAR_CONST_STMT";
        case STR_CONST_STMT:
            return "STR_CONST_STMT";
        case LABELED_STMT:
            return "LABELED_STMT";
        case CASE_STMT:
            return "CASE_STMT";
        case DEFAULT_STMT:
            return "DEFAULT_STMT";
        case DO_WHILE_STMT:
            return "DO_WHILE_STMT";
        case FOR_STMT:
            return "FOR_STMT";
        case RET_STMT:
            return "RET_STMT";
        case BREAK_STMT:
            return "BREAK_STMT";
        case CONTINUE_STMT:
            return "CONTINUE_STMT";
        case GOTO_STMT:
            return "GOTO_STMT";
        case IF_STMT:
            return "IF_STMT";
        case IF_ELSE_STMT:
            return "IF_ELSE_STMT";
        case SWITCH_STMT:
            return "SWITCH_STMT";
        case BASIC_ASSIGNMENT:
            return "BASIC_ASSIGNMENT";
        case ADDITION_ASSIGNMENT:
            return "ADDITION_ASSIGNMENT";
        case SUBTRACTION_ASSIGNMENT:
            return "SUBTRACTION_ASSIGNMENT";
        case MULTIPLICATION_ASSIGNMENT:
            return "MULTIPLICATION_ASSIGNMENT";
        case DIVISION_ASSIGNMENT:
            return "DIVISION_ASSIGNMENT";
        case MODULO_ASSIGNMENT:
            return "MODULO_ASSIGNMENT";
        case BITWISE_AND_ASSIGNMENT:
            return "BITWISE_AND_ASSIGNMENT";
        case BITWISE_OR_ASSIGNMENT:
            return "BITWISE_OR_ASSIGNMENT";
        case BITWISE_XOR_ASSIGNMENT:
            return "BITWISE_XOR_ASSIGNMENT";
        case BITWISE_LEFT_SHIFT_ASSIGNMENT:
            return "BITWISE_LEFT_SHIFT_ASSIGNMENT";
        case BITWISE_RIGHT_SHIFT_ASSIGNMENT:
            return "BITWISE_RIGHT_SHIFT_ASSIGNMENT";
        case POSTFIX_INCREMENT:
            return "POSTFIX_INCREMENT";
        case POSTFIX_DECREMENT:
            return "POSTFIX_DECREMENT";
        case PREFIX_INCREMENT:
            return "PREFIX_INCREMENT";
        case PREFIX_DECREMENT:
            return "PREFIX_DECREMENT";
        case UNARY_PLUS:
            return "UNARY_PLUS";
        case UNARY_MINUS:
            return "UNARY_MINUS";
        case ADDITION:
            return "ADDITION";
        case SUBTRACTION:
            return "SUBTRACTION";
        case PRODUCT:
            return "PRODUCT";
        case DIVISION:
            return "DIVISION";
        case MODULO:
            return "MODULO";
        case BITWISE_NOT:
            return "BITWISE_NOT";
        case BITWISE_AND:
            return "BITWISE_AND";
        case BITWISE_OR:
            return "BITWISE_OR";
        case BITWISE_XOR:
            return "BITWISE_XOR";
        case BITWISE_LEFT_SHIFT:
            return "BITWISE_LEFT_SHIFT";
        case BITWISE_RIGHT_SHIFT:
            return "BITWISE_RIGHT_SHIFT";
        case LOGICAL_NOT:
            return "LOGICAL_NOT";
        case LOGICAL_AND:
            return "LOGICAL_AND";
        case LOGICAL_OR:
            return "LOGICAL_OR";
        case EQUAL_TO:
            return "EQUAL_TO";
        case NOT_EQUAL_TO:
            return "NOT_EQUAL_TO";
        case LESS_THAN:
            return "LESS_THAN";
        case GREATER_THAN:
            return "GREATER_THAN";
        case LESS_THAN_OR_EQUAL_TO:
            return "LESS_THAN_OR_EQUAL_TO";
        case GREATER_THAN_OR_EQUAL_TO:
            return "GREATER_THAN_OR_EQUAL_TO";
        case ARRAY_SUBSCRIPT:
            return "ARRAY_SUBSCRIPT";
        case POINTER_DEREFERENCE:
            return "POINTER_DEREFERENCE";
        case ADDRESS_OF:
            return "ADDRESS_OF";
        case MEMBER_ACCESS:
            return "MEMBER_ACCESS";
        case MEMBER_ACCESS_THROUGH_POINTER:
            return "MEMBER_ACCESS_THROUGH_POINTER";
        case FUNCTION_CALL:
            return "FUNCTION_CALL";
        case COMMA_OPERATOR:
            return "COMMA_OPERATOR";
        case TYPE_CAST:
            return "TYPE_CAST";
        case CONDITIONAL_OPERATOR:
            return "CONDITIONAL_OPERATOR";
        case SIZEOF_OPERATOR:
            return "SIZEOF_OPERATOR";
        case ALIGNOF_OPERATOR:
            return "ALIGNOF_OPERATOR";
    }
}

void ast_dump(const struct translation_unit_t* tu, FILE* output) {
    //'|';'-';'`';'-';
}
