#ifndef WORDMACHINE_H
#define WORDMACHINE_H

#include "boolean.h"
#include "charmachine.h"
#include <stdlib.h>

#define NMax 279
#define BLANK ' '

typedef struct {
   char TabWord[NMax];
   int Length;
} Word;

extern boolean EndWord;
extern Word currentWord;


void my_strlen(const char *str, size_t *len);

char *my_strcpy(char *str_destination, const char *str_source);

char *my_strcat(char *destination, const char *source);

int my_strcmp(const char *s1, const char *s2);

void remove_new_line(char* string);

void IgnoreBlanksAndNewLine();

void READWORD();

void CopyWord();

void printCurrentWord();

boolean isCWordEqual(char string[]);

#endif