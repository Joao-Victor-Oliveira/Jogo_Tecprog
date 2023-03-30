#include <stdio.h>
#include <gtest/gtest.h>

int Soma(int a, int b) {
    return a + b;
}

#include <gtest/gtest.h>

TEST(TesteSoma, SomaPositivos) {
    EXPECT_EQ(Soma(2, 3), 5);
}

TEST(TesteSoma, SomaNegativos) {
    EXPECT_EQ(Soma(-2, -3), -5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

