#include "Stack.h"
#include <stdio.h>
#include "boolean.h"

void create_stack(Stack *s) {
    s->top = -1;
}

boolean is_stack_empty(Stack *s) {
    return s->top == -1;
}

boolean is_stack_full(Stack *s) {
    return s->top == STACK_CAPACITY - 1;
}

void push_stack(Stack *s, int element) {
    ++(s->top);
    s->stack[s->top] = element;
}

void pop_stack(Stack *s, int *element) {
    *element = s->stack[s->top];
    --(s->top);
}

int top_stack(Stack *s) {
	return s->stack[s->top];
}

void print_stack(Stack *s) {
    printf("[");
    for (int i = 0; i <= s->top - 1; ++i) {
        printf("%d,", s->stack[i]);
    }
    if (!is_stack_empty(s)) printf("%d", top_stack(s));
    printf("], top = %d\n", s->top);
}