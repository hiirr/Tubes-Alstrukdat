#include <stdio.h>
#include <stdlib.h>
#include "Wordmachine.h"

Word currentWord;

void my_strlen(const char *str, size_t *len) {
    for (*len = 0; str[*len]; (*len)++);
}

char *my_strcpy(char *str_destination, const char *str_source) {
    char *temp = str_destination;
    while ( (*(str_destination++) = *(str_source++)) );
    return temp;
}

char *my_strcat(char *destination, const char *source) {
    char *r_destination = destination;
    while (*destination) destination++;
    while ((*destination++ = *source++));
    return r_destination;
}

int my_strcmp(const char *s1, const char *s2) {
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void remove_new_line(char* string) {
    size_t length;
    my_strlen(string, &length);
    if((length > 0) && (string[length-1] == '\n')) {
        string[length-1] ='\0';
    }
}

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