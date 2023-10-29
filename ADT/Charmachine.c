#include "Charmachine.h"
#include <stdio.h>

char currentChar;

static FILE *pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
}
