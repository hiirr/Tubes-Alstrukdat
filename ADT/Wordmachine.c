#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "Wordmachine.h"

Word current_word;
boolean end_word;

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

void my_getline(char *line, int size, FILE *file) {
    fgets(line, size, file);
    remove_new_line(line);
}

boolean my_isspace(char c) {
    return (
        (c == ' ') ||
        (c == '\f') ||
        (c == '\n') ||
        (c == '\r') ||
        (c == '\t') ||
        (c == '\v')
    );
}

void ignore_whitespaces() {
    while ((my_isspace(current_char)) && current_char != MARK) {
        ADV();
    }
}

void copy_word() {
    int i = 0;
    while (current_char != MARK && !my_isspace(current_char) && i < WORD_CAPACITY) {
        current_word.word[i] = current_char;
        ADV();
        ++i;
    }
    while (current_char != MARK && !my_isspace(current_char)) ADV();
    current_word.length = i;

    if (current_char == MARK) end_word = true;
}

void copy_paragraph() {
    int i = 0;
    while (current_char != MARK && i < WORD_CAPACITY) {
        current_word.word[i] = current_char;
        ADV();
        ++i;
    }
    while (current_char != MARK && !my_isspace(current_char)) ADV();
    current_word.length = i;
}

void get_paragraph() {
    copy_paragraph();
}

void get_word() {
    ignore_whitespaces();
    if (current_char == MARK) {
        current_word.length = 0;
        end_word = true;
    } else {
        end_word = false;
        copy_word();
    }
}

void clear_new_line() {
    char c;
    scanf("%c", &c);
}

// void ADVWORD() {
//     ignore_whitespaces();
//     if (current_char == MARK) {
//         current_word.length = 0;
//         end_word = true;
//     } else {
//         copy_word();
//         ignore_whitespaces();
//     }
// }

// /* Baca baris input
//    leading BLANK dan newLine serta trailing BLANK dan newLine tidak disimpan ke current_word.word*/
// void read_word_with_limit(int limit) {
//     START();
//     ignore_characters();
//     copy_word_with_limit(limit);
// }

// void copy_word_with_limit(int limit) {
//     int i = 0;
//     while ((current_char != MARK) && (i < limit)) {
//         current_word.word[i] = current_char;
//         ADV();
//         i++;
//     }
//     current_word.length = i;
//     if (i == limit) {
//         while (current_char != MARK) {
//             ADV();
//         }
//     }
//     // ADV(); // consume newLine

//     // remove trailing BLANK and newLine
//     i = 0;
//     int idx = current_word.length - 1;
//     while (current_word.word[idx - i] == ' ' || current_word.word[idx - i] == '\n') {
//         current_word.length--;
//         i++;
//     }
    
// }

void print_input() {
    printf("(");
    for (int i = 0; i < current_word.length; i++) {
        printf("%c", current_word.word[i]);
    }
    printf(")\n");
}

// Check apakah kata pertama dari current_word sama dengan suatu string
boolean is_current_word_equal(char *string) {
    size_t length;
    my_strlen(string, &length);
    if (length != current_word.length) return false;
    for (int i = 0; i < length; ++i) {
        if (current_word.word[i] != string[i]) return false;
    }
    return true;
}

boolean is_two_string_equal(char *first, char *second) {
    size_t first_length, second_length;
    my_strlen(first, &first_length);
    my_strlen(second, &second_length);
    if (first_length != second_length) return false;
    for (int i = 0;i < first_length; ++i) {
        if (first[i] != second[i]) return false;
    }
    return true;
}