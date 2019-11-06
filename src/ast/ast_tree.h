#ifndef GRIZZLY_AST_TREE_H 
#define GRIZZLY_AST_TREE_H

#include <stddef.h>
#include <glib.h>

enum node_type_t {
    POINTER,
    IDENTIFIER_STMT,
    COMPOUND_STMT,
    COMPOUND_LITERAL,
    STRUCTURE,
    UNION,
    ENUMERATION,
    ALIGNMENT_SPEC,
    TRANSLATION_UNIT,
    GENERIC_EXPR,
    STATIC_ASSERT,
    INITILIAZER_LIST,
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
    IF_STMT,
    IF_ELSE_STMT,
    SWITCH_STMT,
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
};

#define BASE_NODE_LAYOUT enum node_type_t node_type;

struct base_node_t {
    BASE_NODE_LAYOUT
};

typedef struct func_definition_t** func_defenitions_t;
typedef struct func_declaration_t** func_declarations_t;

typedef struct variable_definition_t** var_definitions_t;
typedef struct variable_declaration_t** var_declarations_t;

typedef struct struct_definition_t** struct_definitions_t;
typedef struct struct_declaration_t** struct_declarations_t;

typedef struct union_definition_t** union_definitions_t;
typedef struct union_declaration_t** union_declarations_t;

typedef struct enum_definition_t** enum_definitions;

typedef GList* static_asserts_t;

struct translation_unit_t {
    BASE_NODE_LAYOUT
    func_defenitions_t func_defs;
    func_declarations_t func_decs;
    var_declarations_t var_decs;
    var_definitions_t var_defs;
    struct_declarations_t struct_decs;
    struct_definitions_t struct_defs;
    union_declarations_t union_decs;
    union_definitions_t union_defs;
//    enum_definitions_t enum_defs;
    static_asserts_t static_asserts;
};

struct array_type_t {
    BASE_NODE_LAYOUT
    void* type;
    void* expr; //constant-expression repr length
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

struct func_definition_t {
    BASE_NODE_LAYOUT
    struct signature_t signature;
    struct statement_t** body;
};

struct variable_t {
    BASE_NODE_LAYOUT
    char* identifier;
    void* type;
};

struct pointer_t {
    BASE_NODE_LAYOUT
    enum type_qualifier_t* qualifier;
};

//////////////////////////////////////////////////////////////////
//// Generic /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

struct identifier_t {
    BASE_NODE_LAYOUT
    char* data;
};

//////////////////////////////////////////////////////////////////
//// Declarations ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

union declaration_t {
    //TODO: Other
    struct static_assert_t* static_assert;
};

struct {
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
        COMPLEX,
        IMAGINARY
    } type;
} fundamental_type_t;

struct type_specifier_t {
    BASE_NODE_LAYOUT
    struct atomic_type_specifier_t* atomic_type_specifier;
    struct struct_or_union_t* struct_or_union;
    struct enum_specifier_t* enum_specifier;
    struct identifier_t* identifier;
};

struct alignment_specifier_t {
    BASE_NODE_LAYOUT
    union {
        //type-name
        //constant_expression
    };
};

union declaration_specifier_t {
    struct fundamental_type_t* fundamental_type;
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

struct struct_element_t {
    void* type;
    char* identifier;
};

struct bitfield_element_t {
    void* type;
    char* identifier;
    void* expr; //constant-expression repr width
};

struct struct_t {
    BASE_NODE_LAYOUT
    void** structure_declaration_list_t;
    char* identifier;
};

struct union_t {
    BASE_NODE_LAYOUT
    void** structure_declaration_list_t;
    char* identifier;
};

struct static_assert_t {
    BASE_NODE_LAYOUT
    void* constant_expression;
    struct str_literal_t* string_literal;
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
    struct field_initialize_t** field_initialize;
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
    void*  assignment_expression;
    void* generic_assoc_list;
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

struct call_operator_t {
    BASE_NODE_LAYOUT
    void** expr;
};

//////////////////////////////////////////////////////////////////
//// Literals ////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

enum char_literal_prefix_t {
    CHAR_PREF_NONE,
    CHAR_PREF_L,
    CHAR_PREF_LC_U,
    CHAR_PREF_UC_U,
};

struct char_literal_t {
    BASE_NODE_LAYOUT
    void* data;
    enum char_literal_prefix_t prefix;
};

enum str_literal_prefix_t {
    STR_PREF_NONE,
    STR_PREF_U8,
    STR_PREF_LC_U,
    STR_PREF_UC_U,
    STR_PREF_L,
};

struct str_literal_t {
    BASE_NODE_LAYOUT
    void* data;
    enum str_literal_prefix_t prefix;
};

enum float_literal_suffix_t {
    FLOAT_SUF_NONE,
    FLOAT_SUF_F,
    FLOAT_SUF_L,
};

struct float_literal_t {
    BASE_NODE_LAYOUT
    void* data;
    enum float_literal_suffix_t suffix;
};

enum int_literal_suffix_t {
    INT_SUF_NONE,
    INT_SUF_U,
    INT_SUF_L,
    INT_SUF_UL,
    INT_SUF_LL,
    INT_SUF_ULL
};

struct int_literal_t {
    BASE_NODE_LAYOUT
    void* data;
    enum int_literal_suffix_t suffix;
};


struct translation_unit_t* new_translation_unit();
struct pointer_t* new_pointer();
struct identifier_t* new_identifier();
struct enum_specifier_t* new_enum_specifier();
struct struct_t* new_struct();
struct union_t* new_union();
struct static_assert_t* new_static_assert();
struct initializer_list_t* new_initializer_list();
struct labeled_stmt_t* new_labeled_stmt();
struct default_stmt_t* new_default_stmt();
struct case_stmt_t* new_case_stmt();
struct if_stmt_t* new_if_stmt();
struct if_else_stmt_t* new_if_else_stmt();
struct switch_stm_t* new_switch_stm();
struct compound_statement_t* new_compound_statement();
struct goto_stmt_t* new_goto_stmt();
struct continue_stmt_t* new_continue_stmt();
struct break_stmt_t* new_break_stmt();
struct return_stmt_t* new_return_stmt();
struct while_stmt_t* new_while_stmt();
struct do_while_stmt_t* new_do_while_stmt();
struct for_stmt_t* new_for_stmt();
struct compound_literal_t* new_compound_literal();
struct generic_selection_t* new_generic_selection();
struct binary_operator_t* new_binary_operator();
struct ternary_operator_t* new_ternary_operator();
struct unary_operator_t* new_unary_operator();
struct str_literal_t* new_str_literal();
struct int_literal_t* new_int_literal();
struct float_literal_t* new_float_literal();

#endif //GRIZZLY_AST_TREE_H
