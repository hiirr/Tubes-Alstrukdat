#include "../ADT/Wordmachine.h"

void debug_input() {
    printf("(");
    for (int i = 0; i < current_input.length; ++i) {
        printf("%c", current_input.input[i]);
    }
    printf(")");
}

int main() {
    // int a[3][3];
    // int (*p)[3][3] = a;
    
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
    clear_next_character();
    get_paragraph();
    debug_input();
    // }
}