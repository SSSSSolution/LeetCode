#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int a = 1, b = 2;
        int ret;
        for (int i = 3; i <= n; i++) {
            ret = a+b;
            a = b;
            b = ret;
        }
        return ret;
    }
};

void test070()
{
    Solution s;
    cout << s.climbStairs(4) << endl;
}
