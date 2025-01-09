#include "./log_manage.h"
#include <stdio.h>

void create_log(char *message, char *time, enum log_level level)
{
    log_entry new_log;

    new_log.message = message;
    new_log.time = time;
    new_log.level = level;

    printf("[%s] %s\n", new_log.time, new_log.message);
}

void log_print()
{
    log_entry logs[] = {
        {"This is an info message", "2021-07-01 12:00:00", INFO},
        {"This is a warning message", "2021-07-01 12:01:00", WARNING},
        {"This is an error message", "2021-07-01 12:02:00", ERROR}};

    for (int i = 0; i < 3; i++)
    {
        printf("%s %s\n", logs[i].time, logs[i].message);
    }
}
