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

DATETIME get_current_DATETIME() {
    return string_to_DATETIME(current_time());
};

DATETIME string_to_DATETIME(char *string_dt) {
    DATETIME dt = {NULL, NULL, NULL, NULL, NULL};
    size_t len;
    int start = 0, end = 0;
    int field = 0;

    my_strlen(string_dt, &len);
    for (int i = 0; i <= len; ++i) {
        if (string_dt[i] == ' ' || string_dt[i] == '\0') {
            end = i;
            char* token = (char*)malloc((end - start + 1) * sizeof(char));
            for (int j = start, k = 0; j < end; ++j, ++k) {
                token[k] = string_dt[j];
            }
            token[end - start] = '\0';

            switch (field) {
                case 0: dt.day = token; break;
                case 1: dt.MM = token; break;
                case 2: dt.DD = token; break;
                case 3: dt.time = token; break;
                case 4: dt.YYYY = token; break;
            }

            field++;
            start = i + 1;
        }
    }

    return dt;
}


char *DATETIME_to_string(DATETIME dt) {
    size_t day_len, mm_len, dd_len, time_len, yyyy_len;
    my_strlen(dt.day, &day_len);
    my_strlen(dt.MM, &mm_len);
    my_strlen(dt.DD, &dd_len);
    my_strlen(dt.time, &time_len);
    my_strlen(dt.YYYY, &yyyy_len);

    size_t total_len = day_len + mm_len + dd_len + time_len + yyyy_len + 5;
    char *result = (char*)malloc(total_len * sizeof(char));
    
    my_strcpy(result, dt.day);
    result[day_len] = ' ';
    my_strcpy(result + day_len + 1, dt.MM);
    result[day_len + mm_len + 1] = ' ';
    my_strcpy(result + day_len + mm_len + 2, dt.DD);
    result[day_len + mm_len + dd_len + 2] = ' ';
    my_strcpy(result + day_len + mm_len + dd_len + 3, dt.time);
    result[day_len + mm_len + dd_len + time_len + 3] = ' ';
    my_strcpy(result + day_len + mm_len + dd_len + time_len + 4, dt.YYYY);
    result[total_len - 1] = '\0';

    return result;
}