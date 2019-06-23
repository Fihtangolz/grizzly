#ifndef GRIZZLY_AST_TREE_H
#define GRIZZLY_AST_TREE_H

#include <stddef.h>

typedef struct {

} ast_tree_t;

typedef struct {
    char* identifier;
    int value;
} enumerator_t;

typedef struct {
    char* identifier;
    enumerator_t* enumerator_list;
} enum_t;

typedef struct {
    char** errors;
} compile_errors_t;

typedef struct {

} generic_selection_t;

typedef struct {
    //type_t
    char* new_identifier;
} type_alias_t;

typedef enum {
    INLINE,
    NORETURN
} func_specifier_t;

typedef struct {
    //specifiers
    //ret type
    //params
} signature_t;

typedef enum {
    LABELED_STMT,
    COMPOUND_STMT,
    EXPRESSION_STMT,
    SELECTION_STMT,
    ITERATION_STMT,
    JMP_STMT
} stmt_tag_t;

typedef struct {
//    initializer;
//    condition;
//    stepper;
} iteration_stmt_t;

typedef struct {
    stmt_tag_t tag;
//    labeled_stmt_t* labeled;
//    compound_stmt_t* compound;
//    expression_stmt_t* expression;
//    selection_stmt_t* selection;
    iteration_stmt_t* iteration;
//    jmp_stmt_t* jmp;
} statement_t ;

typedef struct {
    signature_t signature;
    statement_t* body;
} func_defenition_t;

typedef struct {
    char* identifier;
//    type_t
} variable_t;

typedef struct {
//    expression
    char* message;
} static_assertion_t;

typedef enum {
    CONST_QUALIFIER,
    RESTRICT_QUALIFIER,
    VOLATILE_QUALIFIER,
    ATOMIC_QUALIFIER,
} type_qualifier_t;

#endif //GRIZZLY_AST_TREE_H
