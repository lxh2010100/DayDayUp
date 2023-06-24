#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "gtest/gtest.h"

TEST(testcase1,should_equal)
{
    EXPECT_EQ(1+2,3);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}