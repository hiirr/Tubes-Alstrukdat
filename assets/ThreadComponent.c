#include "ThreadComponent.h"
#include "../database/database.h"
#include "../ADT/Datetime.h"

#include <stdio.h>

// void print_utas(ThreadComponent *t, int spaces) {
//     for (int i = 0; i < spaces; ++i) printf(" ");
//     printf("INDEX: %d\n", t->idx);
//     for (int i = 0; i < spaces; ++i) printf(" ");
//     printf("%s\n", users[tweets[t->tweet_id].author_id].name);
//     for (int i = 0; i < spaces; ++i) printf(" ");
//     printf("%s\n", t->datetime);
//     for (int i = 0; i < spaces; ++i) printf(" ");
//     printf("%s\n", t->text);
//     printf("\n");
// }