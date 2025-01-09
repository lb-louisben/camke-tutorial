#include <gtest/gtest.h>
#include "sub.h"

TEST(SubTest, PositiveNumbers)
{
    EXPECT_EQ(sub(5, 3), 2);
    EXPECT_EQ(sub(0, 0), 0);
}

TEST(SubTest, NegativeNumbers)
{
    EXPECT_EQ(sub(-5, -3), -2);
    EXPECT_EQ(sub(-1, 1), -2);
}
