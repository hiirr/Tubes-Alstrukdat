#ifndef DRAFT_H
#define DRAFT_H

typedef struct Draft {
    char *datetime;
    char *text;
} Draft;

Draft create_draft();

Draft new_draft(char *text);

void delete_draft(Draft *d);

void print_draft(Draft *d);

#endif