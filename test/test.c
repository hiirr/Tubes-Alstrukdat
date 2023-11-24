#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "boolean.h"
#include "../ADT/Datetime.h"

struct stat info;

int main()
{
    DATETIME d = get_current_DATETIME();
    char *s = DATETIME_to_string(d);
    printf("(%s)\n", s);

    return 0;
}