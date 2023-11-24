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

    size_t len;
    my_strlen(cur_time, &len);
    char *result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    for (int i = 0; i < len; ++i) {
        result[i] = cur_time[i];
    }

    return result;
}