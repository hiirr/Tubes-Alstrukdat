#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../boolean.h"
#include "charmachine.h"

#define NMax 279
#define BLANK ' '

typedef struct
{
   char TabWord[NMax];
   int Length;
} Word;

extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanksAndNewLine();

void READWORD();

void CopyWord();

void printCurrentWord();

boolean isCWordEqual(char string[]);

#endif