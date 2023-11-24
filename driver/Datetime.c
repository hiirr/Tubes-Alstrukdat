#include "../ADT/Datetime.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *time_string = current_time();

    if (time_string != NULL) {

        printf("Current Time: %s\n", time_string);

        free(time_string);

    } else {

        printf("Failed to get the current time.\n");
    }

    return 0;
}
