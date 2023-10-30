#ifndef WORDMACHINE_H
#define WORDMACHINE_H

#include "boolean.h"
#include "Charmachine.h"
#include <stdio.h>
#include <stdlib.h>

#define WORD_CAPACITY 1000

typedef struct Word {
	char word[WORD_CAPACITY];
	int length;
} Word;

extern boolean end_word;
extern Word current_word;

void my_strlen(const char *str, size_t *len);

char *my_strcpy(char *str_destination, const char *str_source);

char *my_strcat(char *destination, const char *source);

int my_strcmp(const char *s1, const char *s2);

void my_getline(char *line, int size, FILE *file);

void remove_new_line(char* string);

boolean my_isspace(char c);

void ignore_whitespaces();

// void read_word_with_limit(int limit);

// void copy_word_with_limit(int limit);

void copy_word();

void copy_paragraph();

void get_paragraph();

void get_word();

void clear_next_character();

// void ADVWORD();

void print_input();

boolean is_current_word_equal(char *string);

boolean is_two_string_equal(char *first, char *second);

int word_to_int();

#endif