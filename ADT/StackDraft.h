#ifndef STACK_DRAFT_H
#define STACK_DRAFT_H

#define STACK_DRAFT_CAPACITY 1000

#include "../assets/Draft.h"
#include "boolean.h"

typedef struct StackDraft { 
	Draft stack[STACK_DRAFT_CAPACITY];
	int top;
} StackDraft;

void create_stack_draft(StackDraft *s);

boolean is_stack_draft_empty(StackDraft *s);

boolean is_stack_draft_full(StackDraft *s);

void push_stack_draft(StackDraft *s, Draft element);

void pop_stack_draft(StackDraft *s, Draft *element);

Draft top_stack_draft(StackDraft *s);

void print_stack_draft(StackDraft *s);

#endif
