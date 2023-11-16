#include <stdio.h>
#include "Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"

Draft create_draft() {
    Draft d;
    d.text = NULL;
    d.datetime = NULL;
    return d;
}

Draft new_draft(char *text) {
    Draft d;

    d.text = text;
    d.datetime = current_time();
    return d;
}

void delete_draft(Draft *d) {
    if (d->text == NULL) {
        return;
    }
    free(d->text);
    free(d->datetime);
    d->text = NULL;
    d->datetime = NULL;
}

void print_draft(Draft *d) {
    printf("| %s\n", d->datetime);
    printf("| %s\n", d->text);
}