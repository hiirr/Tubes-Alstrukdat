#include "Charmachine.h"
#include <stdio.h>

char current_char;

static FILE *pita;
static int return_value;


void SET_STDIN() {
    pita = stdin;
    current_char = ' ';
}

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    return_value = fscanf(pita, "%c", &current_char);
}
