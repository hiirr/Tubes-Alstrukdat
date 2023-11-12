#ifndef DRAFT_H
#define DRAFT_H

typedef struct Draft {
    char *datetime;
    char *text;
} Draft;

Draft new_draft(char *text);

void print_draft(Draft *d);

#endif