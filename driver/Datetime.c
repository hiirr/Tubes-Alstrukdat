#include "ADT/Datetime.h"
#include <stdio.h>


int main()
{
    char *t = current_time();
    printf("%s", t);
    return 0;
}