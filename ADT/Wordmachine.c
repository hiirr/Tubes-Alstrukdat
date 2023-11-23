#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "Wordmachine.h"
#include "DynamicList.h"

Input current_input;

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

void get_paragraph() {
    int i = 0;
    while (current_char != MARK && i < INPUT_CAPACITY) {
        current_input.input[i] = current_char;
        ADV();
        ++i;
    }
    while (current_char != MARK && !my_isspace(current_char)) ADV();
    current_input.length = i;
    ADV(); // Advance mark.
}

void get_word() {
    ignore_whitespaces();
    if (current_char == MARK) {
        current_input.length = 0;
    } else {
        int i = 0;
        while (current_char != MARK && !my_isspace(current_char) && i < INPUT_CAPACITY) {
            current_input.input[i] = current_char;
            ADV();
            ++i;
        }
        while (current_char != MARK && !my_isspace(current_char)) ADV();
        current_input.length = i;
    }
    ADV(); // Advance mark.
}

void clear_next_character() {
    ADV();
}

void print_input() {
    printf("(");
    for (int i = 0; i < current_input.length; i++) {
        printf("%c", current_input.input[i]);
    }
    printf(")\n");
}

// Check apakah kata pertama dari current_input sama dengan suatu string
boolean is_input_equal(char *string) {
    size_t length;
    my_strlen(string, &length);
    if (length != current_input.length) return false;
    for (int i = 0; i < length; ++i) {
        if (current_input.input[i] != string[i]) { 
            return false;
        }
    }
    return true;
}

boolean is_two_string_equal(char *first, char *second) {
    size_t first_length, second_length;
    my_strlen(first, &first_length);
    my_strlen(second, &second_length);
    if (first_length != second_length) { 
        return false;
    }
    for (int i = 0;i < first_length; ++i) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}

int input_to_int() {
    int num = 0;
    for (int i = 0; i < current_input.length; ++i) {
        if (current_input.input[i] == '-') {
            continue;
        }
        num = 10 * num + (current_input.input[i] - '0');
    }
    if (current_input.input[0] == '-') {
        num *= -1;
    }
    return num;
}

char *input_to_string() {
    char *string = malloc((current_input.length + 1) * sizeof(char));
    for (int i = 0; i < current_input.length; ++i) {
        string[i] = current_input.input[i];
    }
    string[current_input.length] = '\0';
    return string;
}

char *input_to_string_limited() {
    char *string = malloc(281 * sizeof(char));

    for (int i = 0; i < 280; ++i) {
        string[i] = current_input.input[i];
    }

    string[280] = '\0';
    return string;
}

boolean is_all_int(char *string) {
    size_t length;
    my_strlen(string, &length);
    for (int i = 0; i < length; ++i) {
        if (!(current_input.input[i] == '0' || 
            current_input.input[i] == '1' ||
            current_input.input[i] == '2' ||
            current_input.input[i] == '3' ||
            current_input.input[i] == '4' ||
            current_input.input[i] == '5' ||
            current_input.input[i] == '6' ||
            current_input.input[i] == '7' ||
            current_input.input[i] == '8' ||
            current_input.input[i] == '9')) {
            return false;
        }
    }
    return true;
}

boolean is_all_space(char *string) {
    size_t length;
    my_strlen(string, &length);
    for (int i = 0; i < length; ++i) {
        if (!my_isspace(string[i])) {
            return false;
        }
    }
    return true;
}

char to_lower(char c) {
    if ('a' <= c && c <= 'z'){
        return c;
    } else if ('A' <= c && c <= 'Z'){
        return c + 'a' - 'A';
    } else {
        return '\0';
    }
}

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

void my_getline(char *line, int size, FILE *file) {
    fgets(line, size, file);
    remove_new_line(line);
}


void remove_new_line(char* string) {
    size_t length;
    my_strlen(string, &length);
    if((length > 0) && (string[length-1] == '\n')) {
        string[length-1] ='\0';
    }
}

DynamicList split_to_ints(char *string) {
    DynamicList result;
    create_dynamic_list(&result, 1);

    boolean is_positive = true;
    int num = 0;
    size_t len;
    my_strlen(string, &len);
    for (int i = 0; i < len; ++i) {
        if (string[i] == '-') {
            is_positive = !is_positive;
        } else if (string[i] - '0' >= 0 && string[i] - '0' <= 9) {
            int digit = string[i] - '0';
            num = 10 * num + digit;
        } else if (string[i] == ' ') {
            if (!is_positive) {
                num = -num;
            }
            insert_last_dynamic_list(&result, num);
            num = 0;
            is_positive = true;
        } else {
            printf("Unknown character in parsing.\n");
        }
    }
    if (!is_positive) {
        num = -num;
    }
    insert_last_dynamic_list(&result, num);
    return result;
}
