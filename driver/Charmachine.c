#include "../ADT/Charmachine.h"
#include <stdio.h>
#include <assert.h>

int main() {
    
    SET_STDIN();
   
    START();
    
    while (current_char != MARK) {
        if (current_char != '\n') {
            printf("Character read: %c\n", current_char);
        } else {
            printf("Character read: newline character\n");
        }
        ADV();
    }

    printf("End of input or MARK character found.\n");

    return 0;
}
