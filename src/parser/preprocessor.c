#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "preprocessor.h"

#define DEFAULT_LEXEMES_COUNT 128

//************************************************************

void preprocessor_lexeme_free(preprocessor_lexeme_t lexeme) {
    switch (lexeme.kind) {
    case PREPROCESSOR_LEXEME_INCLUDE:
        g_string_free(lexeme.data.include.filename, TRUE);
        break;
    case PREPROCESSOR_LEXEME_DEFINE_FUNCTIONAL:
        g_string_free(lexeme.data.define_functional.identifier, TRUE);
        g_string_free(lexeme.data.define_functional.body, TRUE);

        GArray *parameters = lexeme.data.define_functional.parameters;
        for (guint i = 0; i < parameters->len; i++) {
            g_string_free(g_array_index(parameters, GString *, i), TRUE);
        }
        break;
    default:
        g_string_free(lexeme.data.another.content, TRUE);
    }
}

//************************************************************

const char *
preprocessor_lexeme_kind_stringify(preprocessor_lexeme_kind_t kind) {
    switch (kind) {
    case PREPROCESSOR_LEXEME_DEFINE:
    case PREPROCESSOR_LEXEME_DEFINE_FUNCTIONAL:
        return "#define";
    case PREPROCESSOR_LEXEME_UNDEF:
        return "#undef";
    case PREPROCESSOR_LEXEME_IFDEF:
        return "#ifdef";
    case PREPROCESSOR_LEXEME_IFNDEF:
        return "#ifndef";

    case PREPROCESSOR_LEXEME_INCLUDE:
        return "#include";
    case PREPROCESSOR_LEXEME_PRAGMA:
        return "#pragma";
    case PREPROCESSOR_LEXEME_ERROR:
        return "#error";

    case PREPROCESSOR_LEXEME_IF:
        return "#if";
    case PREPROCESSOR_LEXEME_ELIF:
        return "#elif";
    case PREPROCESSOR_LEXEME_ELSE:
        return "#else";
    case PREPROCESSOR_LEXEME_ENDIF:
        return "#endif";
    }
}

//************************************************************

static char *find_double_apostrophe(const char *text) {
    return strchr(text, '\"');
}

static bool is_end_of_c_string(const char *apostrophe) {
    apostrophe--;

    size_t backslashes_count = 0;
    while (*apostrophe == '\\') {
        apostrophe--;
        backslashes_count++;
    }

    return backslashes_count % 2 == 0;
}

static void skip_c_string(const char **text) {
    assert(**text == '\"');
    *text += 1;

    char *next_double_apostrophe;
    while ((next_double_apostrophe = strchr(*text, '\"')) != NULL) {
        if (is_end_of_c_string(next_double_apostrophe)) {
            *text = next_double_apostrophe + 1;
            return;
        }
    }

    // TODO: logger_error(This C-string doesn't end with ");
    // exit(EXIT_FAILURE);
}

//************************************************************

static void convert_to_include(preprocessor_lexeme_t *lexeme) {
    // TODO
}

static void convert_to_define(preprocessor_lexeme_t *lexeme) {
    // TODO
}

static void convert_to_define_functional(preprocessor_lexeme_t *lexeme) {
    // TODO
}

static void correct_lexeme_kind(preprocessor_lexeme_t *lexeme) {
    switch (lexeme->kind) {
    case PREPROCESSOR_LEXEME_INCLUDE:
        convert_to_include(lexeme);
        break;
    case PREPROCESSOR_LEXEME_DEFINE:
        convert_to_define(lexeme);
        break;
    case PREPROCESSOR_LEXEME_DEFINE_FUNCTIONAL:
        convert_to_define_functional(lexeme);
        break;
    }
}

//************************************************************

static bool append_first_lexeme(GArray *lexemes, const char **text,
                                const char *end,
                                preprocessor_lexeme_kind_t kind) {
    const char *name = preprocessor_lexeme_kind_stringify(kind);

    char *occurrence = g_strstr_len(*text, end ? end - *text : -1, name);
    if (!occurrence) {
        return false;
    }

    GString *content = g_string_new(NULL);

    *text = occurrence + strlen(name) + 1;
    if (**text != '(' && kind == PREPROCESSOR_LEXEME_DEFINE_FUNCTIONAL) {
        return false;
    }

    while (**text != '\0' && **text != '\n') {
        if (**text == '\\') {
            g_string_append_c(content, ' ');
            *text += 2;
        } else {
            g_string_append_c(content, **text);
            *text += 1;
        }
    }

    preprocessor_lexeme_t lexeme = {
        .kind = kind,
        .data.another.content = content,
    };
    correct_lexeme_kind(&lexeme);
    g_array_append_val(lexemes, lexeme);

    return true;
}

static void append_all_lexemes(GArray *lexemes, const char *text,
                               const char *end,
                               preprocessor_lexeme_kind_t kind) {
    while (append_first_lexeme(lexemes, &text, end, kind))
        ;
}

//************************************************************

#define APPEND_ALL_LEXEMES(kind)                                               \
    do {                                                                       \
        append_all_lexemes(lexemes, temp, next_double_apostrophe, kind);       \
    } while (false)

GArray *preprocessor(const char *source) {
    GArray *lexemes = g_array_sized_new(
        FALSE, FALSE, sizeof(preprocessor_lexeme_t), DEFAULT_LEXEMES_COUNT);

    const char *next_double_apostrophe = source;
    while (true) {
        const char *const temp = next_double_apostrophe;
        next_double_apostrophe = find_double_apostrophe(next_double_apostrophe);

        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_DEFINE);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_DEFINE_FUNCTIONAL);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_UNDEF);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_IFDEF);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_IFNDEF);

        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_INCLUDE);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_PRAGMA);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_ERROR);

        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_IF);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_ELIF);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_ELSE);
        APPEND_ALL_LEXEMES(PREPROCESSOR_LEXEME_ENDIF);

        if (!next_double_apostrophe) {
            break;
        }

        skip_c_string(&next_double_apostrophe);
    }

    return lexemes;
}
