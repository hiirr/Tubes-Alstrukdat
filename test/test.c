#include "../ADT/Wordmachine.h"

void debug_input() {
    printf("(");
    for (int i = 0; i < current_input.length; ++i) {
        printf("%c", current_input.input[i]);
    }
    printf(")");
}

int main() {
    // while (true) { 
    START();
    // get_word();
    // debug_input();
    // get_word();
    // debug_input();
    // get_word();
    // debug_input();

    get_paragraph();
    debug_input();
    get_paragraph();
    debug_input();
    // }
}