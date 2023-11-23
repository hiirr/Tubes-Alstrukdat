#ifndef WORDMACHINE_H
#define WORDMACHINE_H

#include "boolean.h"
#include "Charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "DynamicList.h"

#define INPUT_CAPACITY 1000

typedef struct Input {
	char input[INPUT_CAPACITY];
	int length;
} Input;



extern Input current_input;

boolean my_isspace(char c);

void ignore_whitespaces();

void get_paragraph();

void get_word();

void clear_next_character();

void print_input();

boolean is_input_equal(char *string);

boolean is_two_string_equal(char *first, char *second);

int input_to_int();

char *input_to_string();

char *input_to_string_limited(int limit);

boolean is_all_int(char *string);

boolean is_all_space(char *string);

char to_lower(char c);

void my_strlen(const char *str, size_t *len);

char *my_strcpy(char *str_destination, const char *str_source);

char *my_strcat(char *destination, const char *source);

int my_strcmp(const char *s1, const char *s2);

void my_getline(char *line, int size, FILE *file);

void remove_new_line(char* string);

DynamicList split_to_ints(char *string);

#endif