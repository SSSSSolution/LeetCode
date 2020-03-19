#ifndef H007_HPP
#define H007_HPP

// 7.整数反转(Easy)
/* example:
 *  in: 123     out:321
 *  in: -123    out:-321
 *  in: 120     out:21
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int reverse1(int x) {
        long long oldX = x;
        if (oldX == 0) return oldX;
        bool positive;
        if (oldX < 0) {
            positive = false;
        } else {
            positive = true;
        }

        if (!positive)
            oldX = -oldX;

        std::vector<int> digits;
        // 将x的每位分解出来
        parseInter(oldX, digits);

        // 计算过程中newX有可能超过INT范围
        long long newX = 0;
        for (auto iter = digits.begin(); iter != digits.end(); ++iter) {
            newX = newX * 10 + *iter;
        }

        if (!positive)
            newX = -newX;

        long long min = 1;
        min = -1*(min << 31);

        long long max = 1;
        max = (max << 31) -1;
//        std::cout << min << std::endl;
//        std::cout << max << std::endl;
        if (newX < min || newX > max)
            return 0;
        return newX;
    }

    int reverse(int x){
        long count=0;
        while(x!=0){
            count=count*10+x%10;
            x=x/10;
        }
        return count>2147483647||count<-2147483648?0:count;
    }

private:
    void parseInter(long long  x, std::vector<int> &digits)
    {
        digits.clear();
        while(x != 0) {
            digits.push_back(x % 10);
            x = x / 10;
        }
    }
};

void test007()
{
    Solution s;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-1534236469) << std::endl;
    std::cout << s.reverse(1534236469) << std::endl;
}
#endif // H007_HPP
