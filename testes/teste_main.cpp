#include <stdio.h>
#include <gtest/gtest.h>

int Soma(int a, int b) {
    return a + b;
}

#include <gtest/gtest.h>


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}

