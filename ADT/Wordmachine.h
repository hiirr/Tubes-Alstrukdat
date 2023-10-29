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

extern boolean EndWord;
extern Word current_word;

void my_strlen(const char *str, size_t *len);

char *my_strcpy(char *str_destination, const char *str_source);

char *my_strcat(char *destination, const char *source);

int my_strcmp(const char *s1, const char *s2);

void my_getline(char *line, int size, FILE *file);

void remove_new_line(char* string);

void ignore_whitespaces();

// void read_word_with_limit(int limit);

// void copy_word_with_limit(int limit);

void copy_word();

void STARTWORD();

void ADVWORD();

void print_word();

boolean is_word_equal(char string[]);

#endif