#ifndef LOG_MANAGE_H
#define LOG_MANAGE_H

#include <stdio.h>

// 定义日志级别
typedef enum log_level
{
    INFO,
    WARNING,
    ERROR
} log_level;

// 定义日志条目
typedef struct log_entry
{
    char *message;
    char *time;
    log_level level;
} log_entry;

// 函数声明
void create_log(char *message, char *time, log_level level);
void log_print();

#endif
