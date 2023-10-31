#include "Datetime.h"
#include "Wordmachine.h"

#include <time.h>

char *current_time() {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    char *cur_time = asctime(time_info);
    remove_new_line(cur_time);

    return cur_time;
}