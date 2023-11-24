#include "../ADT/Datetime.h"
#include "../ADT/Wordmachine.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *time_str = current_time();
    printf("Current time: %s\n", time_str);
    assert(time_str != NULL);

    DATETIME dt = string_to_DATETIME(time_str);
    printf("Converted DATETIME: %s %s %s %s %s\n", dt.day, dt.MM, dt.DD, dt.time, dt.YYYY);
    assert(dt.day != NULL && dt.MM != NULL && dt.DD != NULL && dt.time != NULL && dt.YYYY != NULL);

    char *dt_str = DATETIME_to_string(dt);
    printf("DATETIME to string: %s\n", dt_str);
    assert(my_strcmp(dt_str, time_str) == 0);
    
    DATETIME current_dt = get_current_DATETIME();

    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);

    char day[10], month[10], date[3], year[5];
    strftime(day, sizeof(day), "%a", time_info);
    strftime(month, sizeof(month), "%b", time_info);
    strftime(date, sizeof(date), "%d", time_info);
    strftime(year, sizeof(year), "%Y", time_info);

    assert(my_strcmp(current_dt.day, day) == 0);
    assert(my_strcmp(current_dt.MM, month) == 0);
    assert(my_strcmp(current_dt.DD, date) == 0);
    assert(my_strcmp(current_dt.YYYY, year) == 0);

    printf("get_current_DATETIME test passed.\n");
    printf("DATETIME from get_current_DATETIME: %s %s %s %s %s\n", current_dt.day, current_dt.MM, current_dt.DD, current_dt.time, current_dt.YYYY);

    free(time_str);
    free(dt.day);
    free(dt.MM);
    free(dt.DD);
    free(dt.time);
    free(dt.YYYY);
    free(dt_str);

    printf("All tests passed successfully.\n");

    return 0;
}