#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

Word currentWord;

void IgnoreBlanksAndNewLine(){
    while (currentChar == BLANK || currentChar == '\n') {
        ADV();
    }
};

void CopyWord(int NChar){
    int i = 0;
    while ((currentChar != MARK) && (i < NChar)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
    if (i == NChar) {
        while (currentChar != MARK) {
            ADV(); // consume sisa character hingga MARK jika input character >280;
        }
    }
    ADV(); // consume newLine
    // remove trailing BLANK and newLine
    i = 0;
    int idx = currentWord.Length - 1;
    while (currentWord.TabWord[idx - i] == BLANK || currentWord.TabWord[idx - i] == '\n') {
        currentWord.Length--;
        i++;
    }
    
};

/* Baca baris input
   leading BLANK dan newLine serta trailing BLANK dan newLine tidak disimpan ke currentWord.Tabword*/
void READWORD(int NChar) {
    START();
    IgnoreBlanksAndNewLine();
    CopyWord(NChar);
};

void printCurrentWord() {
    int i;
    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
}

//check apakah kata pertama dari currentWord sama dengan suatu string
boolean isCWordEqual(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        if (currentWord.TabWord[i] != string[i]) {
            return false;
        }
        i++;
    }
    return true;
}