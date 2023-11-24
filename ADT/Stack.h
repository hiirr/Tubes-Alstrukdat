#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 1000

#include "boolean.h"

typedef struct Stack { 
	int stack[STACK_CAPACITY];
	int top;
} Stack;

void create_stack(Stack *s);

boolean is_stack_empty(Stack *s);

boolean is_stack_full(Stack *s);

void push_stack(Stack *s, int element);

void pop_stack(Stack *s, int *element);

int top_stack(Stack *s);

void print_stack(Stack *s);

#endif
