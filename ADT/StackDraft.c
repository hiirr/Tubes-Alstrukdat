#include "StackDraft.h"
#include "../assets/Draft.h"
#include <stdio.h>
#include "boolean.h"

void create_stack_draft(StackDraft *s) {
    s->top = -1;
}

boolean is_stack_draft_empty(StackDraft *s) {
    return s->top == -1;
}

boolean is_stack_draft_full(StackDraft *s) {
    return s->top == STACK_DRAFT_CAPACITY - 1;
}

void push_stack_draft(StackDraft *s, Draft element) {
    ++(s->top);
    s->stack[s->top] = element;
}

void pop_stack_draft(StackDraft *s, Draft *element) {
    *element = s->stack[s->top];
    --(s->top);
}

Draft top_stack_draft(StackDraft *s) {
	return s->stack[s->top];
}

void print_stack_draft(StackDraft *s) {
    printf("[");
    for (int i = 0; i <= s->top - 1; ++i) {
        printf("%s,", s->stack[i].text);
    }
    if (!is_stack_draft_empty(s)) printf("%s", top_stack_draft(s).text);
    printf("], top = %d\n", s->top);
}