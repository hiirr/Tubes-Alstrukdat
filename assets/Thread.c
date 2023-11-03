#include "Thread.h"
#include "../database/database.h"
#include "../ADT/Datetime.h"

void print_utas(Thread *t) {
    printf("INDEX: %d\n", t->idx);
    printf("%s\n", users[current_user].name);
    printf("%s\n", t->datetime);
    printf("%s\n", t->text);
    printf("\n");
}