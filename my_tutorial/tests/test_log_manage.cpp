#include "gtest/gtest.h"
#include "log_manage.h"

TEST(LogTest, CreateLog)
{
    create_log("Info message", "2021-01-01 12:00:00", INFO);
    SUCCEED(); // 如果函数运行没有崩溃，测试通过
}

TEST(LogTest, LogPrint)
{
    log_print();
    SUCCEED(); // 如果函数运行没有崩溃，测试通过
}
