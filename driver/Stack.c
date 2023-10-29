#include <stdio.h>
#include "ADT/Stack.h"


int main() {
    Stack s;
    create_stack(&s);
    print_stack(&s);
    if (is_stack_empty(&s)) {
        printf("is_stack_empty == true\n");
    }
    push_stack(&s, 5);
    push_stack(&s, 6);
    push_stack(&s, 7);
    print_stack(&s);

    int popped;
    pop_stack(&s, &popped);
    printf("Popped %d\n", popped);
    print_stack(&s);
    pop_stack(&s, &popped);
    printf("Popped %d\n", popped);
    print_stack(&s);
    pop_stack(&s, &popped);
    printf("Popped %d\n", popped);
    print_stack(&s);
}