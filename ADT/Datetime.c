#include "Datetime.h"

#include <time.h>

char *current_time() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return asctime(timeinfo);
}