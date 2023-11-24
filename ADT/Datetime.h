#ifndef DATETIME_H
#define DATETIME_H

#include "boolean.h"

typedef struct {
    char *day;
    char *MM;
    char *DD;
    char *time;
    char *YYYY;
} DATETIME;

char *current_time();

DATETIME get_current_DATETIME();

DATETIME string_to_DATETIME(char *string_dt);

char *DATETIME_to_string(DATETIME dt);

#endif
