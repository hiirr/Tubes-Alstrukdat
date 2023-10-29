#include "Charmachine.h"
#include <stdio.h>

char current_char;

static FILE *pita;
static int return_value;

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    return_value = fscanf(pita, "%c", &current_char);
}
