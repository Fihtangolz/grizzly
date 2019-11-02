#ifndef GRIZZLY_AST_TREE_H
#define GRIZZLY_AST_TREE_H

#include <stddef.h>

typedef enum {
    IDENTIFIER_STMT,
    COMPOUND_STMT,
    STRUCTURE,
    UNION,
    ENUMERATION,
    ALIGNMENT_SPEC,
//Constants
    INT_CONST_STMT,
    FLOAT_CONST_STMT,
    CHAR_CONST_STMT,
    STR_CONST_STMT,
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

struct base_node_t {
    node_type_t node_type;
};

union declaration_t {
    //TODO: Other
    struct static_assert_t* static_assert;
};

struct translation_unit_t {
    struct func_definition_t** func_definitions;
    union declaration_t** declarations;
};

struct array_type_t {
    BASE_NODE_LAYOUT
    void* type;
    void* expr; //constant-expression repr length
};

struct struct_el_t {
    void* type;
    char* identifier;
};

struct bitfield_el_t {
    void* type;
    char* identifier;
    void* expr; //constant-expression repr width
};

struct type_alias_t {
    BASE_NODE_LAYOUT
    void* type;
    char* new_identifier;
};

struct signature_t {
    void* ret_type;
    void* params;
};

typedef struct {
    BASE_NODE_LAYOUT
    struct signature_t signature;
//    statement_t** body;
} func_definition_t;

typedef struct {
    BASE_NODE_LAYOUT
    char* identifier;
    void* type;
} variable_t;

typedef struct {
//    type_qualifier_t qualifier;

} pointer_t;

//////////////////////////////////////////////////////////////////
//// Declarations ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

struct type_specifier_t {
    BASE_NODE_LAYOUT
    enum {
        VOID,
        CHAR,
        SHORT,
        INT,
        LONG,
        FLOAT,
        DOUBLE,
        SIGNED,
        UNSIGNED,
        BOOL,
        COMPLEX
    };

};

struct alignment_specifier_t {
    BASE_NODE_LAYOUT
    union {
        //type-name
        //constant_expression
    };
};

union declaration_specifier_t {
    enum storage_specifier_t* storage_specifier;
    struct type_specifier_t* type_specifier;
    enum type_qualifier_t* type_qualifier_t;
    enum func_specifier_t* func_specifier;
    struct alignment_specifier_t* alignment_specifier_t;
};

struct atomic_type_specifier_t {
    BASE_NODE_LAYOUT
    void* type_name;
};

enum func_specifier_t {
    INLINE,
    NORETURN
};

enum storage_specifier_t {
    TYPEDEF_SPECIFIER,
    EXTERN_SPECIFIER,
    STATIC_SPECIFIER,
    THREAD_LOCAL_SPECIFIER,
    AUTO_SPECIFIER,
    REGISTER_SPECIFIER,
};

enum type_qualifier_t {
    CONST_QUALIFIER,
    RESTRICT_QUALIFIER,
    VOLATILE_QUALIFIER,
    ATOMIC_QUALIFIER,
};

struct enumerator_t {
    char* identifier;
    int* value;
};

struct enum_specifier_t {
    BASE_NODE_LAYOUT
    char* identifier;
    struct enumerator_t* enumerator_list;
};

struct struct_or_union_t {
    BASE_NODE_LAYOUT
    void** structure_declaration_list_t;
    char* identifier;
};

struct static_assert_t {
    BASE_NODE_LAYOUT
    void* constant_expression;
    char* string_literal;
};

struct designator_t {
    enum {
        EXPR,
        IDENT,
    } tag;
    union {
        void* expr;
        char* identifier;
    };
};

struct field_initialize_t {
    struct designator_t** designator;
    void* initializer;
};

struct initializer_list_t {
    BASE_NODE_LAYOUT
    struct field_initialize_t** field_int;
};

//////////////////////////////////////////////////////////////////
//// Statements //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

struct labeled_stmt_t {
    BASE_NODE_LAYOUT
    char* identifier;
    void* stmt;
};

struct default_stmt_t {
    BASE_NODE_LAYOUT
    void* stmt;
};

struct case_stmt_t {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
};

struct if_stmt_t {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
};

struct if_else_stmt_t {
    BASE_NODE_LAYOUT
    void* expr;
    void* if_stmt;
    void* else_stmt;
};

struct switch_stm_t {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
};

struct compound_statement_t {
    BASE_NODE_LAYOUT
    void** stmts;
};

struct goto_stmt_t {
    BASE_NODE_LAYOUT
    char* identifier;
};

struct continue_stmt_t {
    BASE_NODE_LAYOUT
};

struct break_stmt_t {
    BASE_NODE_LAYOUT
};

struct return_stmt_t {
    BASE_NODE_LAYOUT
    void* expr;
};

struct while_stmt_t {
    BASE_NODE_LAYOUT
    void* expr;
    void* stmt;
};

struct do_while_stmt_t {
    BASE_NODE_LAYOUT
    void* stmt;
    void* expr;
};

struct for_stmt_t {
    BASE_NODE_LAYOUT
    //TODO
};

//////////////////////////////////////////////////////////////////
//// Expression //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

struct compound_literal_t {
    BASE_NODE_LAYOUT
    void* type_name;
    void** initializer_list ;
};

struct generic_selection_t {
    BASE_NODE_LAYOUT
    //TODO
};

struct binary_operator_t {
    BASE_NODE_LAYOUT
    void* lhs;
    void* rhs;
};

struct ternary_operator_t {
    BASE_NODE_LAYOUT
    void* expr;
    void* lhs;
    void* rhs;
};

struct unary_operator_t {
    BASE_NODE_LAYOUT
    void* expr;
};

//////////////////////////////////////////////////////////////////
//// Literals ////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

struct str_literal_t {
    BASE_NODE_LAYOUT
    char* str;
};

struct int_literal_t{
    BASE_NODE_LAYOUT
};

#endif //GRIZZLY_AST_TREE_H
