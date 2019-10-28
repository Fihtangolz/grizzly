#ifndef GRIZZLY_AST_TREE_H
#define GRIZZLY_AST_TREE_H

#include <stddef.h>

typedef enum {
//
    COMPOUND_STMT,
    STRUCTURE,
    UNION,
    ENUMERATION,
//Labeled statement
    LABELED_STMT,
    CASE_STMT,
    DEFAULT_STMT,
//Iteration statement
    WHILE_STMT,
    DO_WHILE_STMT,
    FOR_STMT,
//Jump statement
    RET_STMT,
    BREAK_STMT,
    CONTINUE_STMT,
    GOTO_STMT,
//Selection statements
    SWITCH_STMT,
    IF_STMT,
    IF_ELSE_STM,
//Operators
    //Assignment
    BASIC_ASSIGNMENT,
    ADDITION_ASSIGNMENT,
    SUBTRACTION_ASSIGNMENT,
    MULTIPLICATION_ASSIGNMENT,
    DIVISION_ASSIGNMENT,
    MODULO_ASSIGNMENT,
    BITWISE_AND_ASSIGNMENT,
    BITWISE_OR_ASSIGNMENT,
    BITWISE_XOR_ASSIGNMENT,
    BITWISE_LEFT_SHIFT_ASSIGNMENT,
    BITWISE_RIGHT_SHIFT_ASSIGNMENT,
    //Inc/Dec
    POSTFIX_INCREMENT,
    POSTFIX_DECREMENT,
    PREFIX_INCREMENT,
    PREFIX_DECREMENT,
    //Arithmetic
    UNARY_PLUS,
    UNARY_MINUS,
    ADDITION,
    SUBTRACTION,
    PRODUCT,
    DIVISION,
    MODULO,
    BITWISE_NOT,
    BITWISE_AND,
    BITWISE_OR,
    BITWISE_XOR,
    BITWISE_LEFT_SHIFT,
    BITWISE_RIGHT_SHIFT,
    //Logical
    LOGICAL_NOT,
    LOGICAL_AND,
    LOGICAL_OR,
    //Comparison
    EQUAL_TO,
    NOT_EQUAL_TO,
    LESS_THAN,
    GREATER_THAN,
    LESS_THAN_OR_EQUAL_TO,
    GREATER_THAN_OR_EQUAL_TO,
    //Member access
    ARRAY_SUBSCRIPT,
    POINTER_DEREFERENCE,
    ADDRESS_OF,
    MEMBER_ACCESS,
    MEMBER_ACCESS_THROUGH_POINTER,
    //Other
    FUNCTION_CALL,
    COMMA_OPERATOR,
    TYPE_CAST,
    CONDITIONAL_OPERATOR,
    SIZEOF_OPERATOR,
    ALIGNOF_OPERATOR,
} node_type_t;

#define BASE_NODE_LAYOUT node_type_t node_type;

typedef struct {
    node_type_t node_type;
} base_node_t;

typedef struct {
    struct func_definition_t** func_definitions;
    void* declarations;
} translation_unit_t;

typedef enum {
    INLINE,
    NORETURN
} func_specifier_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* type;
    void* expr; //constant-expression repr length
} array_type_t;

typedef struct {
    void* type;
    char* identifier;
} struct_el_t;

typedef struct {
    void* type;
    char* identifier;
    void* expr; //constant-expression repr width
} bitfield_el_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* type;
    char* new_identifier;
} type_alias_t;

typedef struct {
    void* ret_type;
    void* params;
} signature_t;

typedef struct {
    BASE_NODE_LAYOUT
    signature_t signature;
    statement_t** body;
} func_definition_t;

typedef struct {
    BASE_NODE_LAYOUT
    char* identifier;
    void* type;
} variable_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* constant_expression;
    char* string_literal;
} static_assert_declaration_t;

typedef struct {
    type_qualifier_t qualifier;

} pointer_t;

//////////////////////////////////////////////////////////////////
//// Declarations ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

typedef struct {
    union {

    };
    void* initializer;
};

//typedef struct {
//    void** declaration_specifiers;
//} declaration_t;

//typedef enum {
//    VOID,
//    CHAR,
//    SHORT,
//    INT,
//    LONG,
//    FLOAT,
//    DOUBLE,
//    SIGNED,
//    UNSIGNED,
//    BOOL,
//    COMPLEX
//} type_specifier_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* type_name;
} atomic_type_specifier_t;

typedef enum {
    TYPEDEF_SPECIFIER,
    EXTERN_SPECIFIER,
    STATIC_SPECIFIER,
    THREAD_LOCAL_SPECIFIER,
    AUTO_SPECIFIER,
    REGISTER_SPECIFIER,
} storage_specifier_t;

typedef enum {
    CONST_QUALIFIER,
    RESTRICT_QUALIFIER,
    VOLATILE_QUALIFIER,
    ATOMIC_QUALIFIER,
} type_qualifier_t;

typedef struct {
    char* identifier;
    int* value;
} enumerator_t;

typedef struct {
    BASE_NODE_LAYOUT
    char* identifier;
    enumerator_t* enumerator_list;
} enum_specifier_t;

typedef struct {
    BASE_NODE_LAYOUT
    void** structure_declaration_list_t;
    char* identifier;
} struct_or_union_t;

//////////////////////////////////////////////////////////////////
//// Statements //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

typedef struct {
    BASE_NODE_LAYOUT
    char* identifier;
    void* stmt;
} labeled_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* stmt;
} default_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
} case_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
} if_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
    void* if_stmt;
    void* else_stmt;
} if_else_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
} switch_stm_t;

typedef struct {
    BASE_NODE_LAYOUT
    void** stmts;
} compound_statement_t;

typedef struct {
    BASE_NODE_LAYOUT
    char* identifier;
} goto_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
} continue_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
} break_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
} return_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
} while_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* stmt;
    void* expr;
} do_while_stmt_t;

typedef struct {
    BASE_NODE_LAYOUT
    //TODO
} for_stmt_t;

//////////////////////////////////////////////////////////////////
//// Expression //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

typedef struct {
    BASE_NODE_LAYOUT
    void* type_name;
    void** initializer_list ;
} compound_literal_t;

typedef struct {
    BASE_NODE_LAYOUT
    //TODO
} generic_selection_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* lhs;
    void* rhs;
} binary_operator_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
    void* lhs;
    void* rhs;
} ternary_operator_t;

typedef struct {
    BASE_NODE_LAYOUT
    void* expr;
} unary_operator_t;

#endif //GRIZZLY_AST_TREE_H
