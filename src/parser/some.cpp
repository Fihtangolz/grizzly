#include <cstdlib>

struct expected_lexem_t {
    char* lexem;
    void* next;
};

void some() {
    (expected_lexem_t){"#", NULL};
}


