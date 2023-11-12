#include <stdio.h>
#include "Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"

Draft new_draft(char *text) {
    Draft d;

    d.text = text;
    d.datetime = current_time();
}

void print_draft(Draft *d) {
    printf("| %s\n", d->datetime);
    printf("| %s\n", d->text);
}