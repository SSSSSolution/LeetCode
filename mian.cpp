#include "header.h"

#define TEST_NUM 009
#define TEST(NUM) CONCAT(test, NUM)()

#define TEST_NUM_FILE(a, b) STRINGIFY(CONCAT(a,b))
#include TEST_NUM_FILE(TEST_NUM, .hpp)

int main()
{
    TEST(TEST_NUM);
}
