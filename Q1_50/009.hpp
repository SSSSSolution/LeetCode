#include <iostream>
#include <math.h>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        int digitCount = 0;
        int tmp = x;
        while(tmp != 0) {
            tmp /= 10;
            digitCount++;
        }
//        std::cout << "digitCount: " << digitCount << std::endl;

        if (digitCount == 1)
            return true;

        int begin = 1;
        int end = digitCount;
        bool isPa = true;
        while(begin < end) {
            int a = pow(10, begin - 1);
            int b = pow(10, end - 1) ;
            if ( (x / a % 10) != (x / b % 10) ) {
                isPa = false;
                break;
            }
            begin++;
            end--;
        }
        return isPa;
    }
};

void test009() {
    Solution s;

    std::cout << s.isPalindrome(1001) << std::endl;
    std::cout << s.isPalindrome(-121) << std::endl;
    std::cout << s.isPalindrome(11) << std::endl;
}
