#include <iostream>
#include <string>
#include <limits.h>
#include <ctype.h>

class Solution {
public:
    enum status { HEAD_UNFIND, HEAD_FIND };

    int myAtoi(std::string str)
    {
        long long ret = 0;
        bool positive = true;
        bool isEnd = false;

        status s = HEAD_UNFIND;
        for (auto iter = str.begin(); iter != str.end(); ++iter) {
            if (isEnd) break;

            switch(s) {
            case HEAD_UNFIND:
                if (isspace(*iter)) {
                    continue;
                } else if (*iter == '-') {
                    s = HEAD_FIND;
                    positive = false;
                } else if (*iter == '+') {
                    s = HEAD_FIND;
                } else if (isdigit(*iter)) {
                    s = HEAD_FIND;
                    ret = *iter - '0';
                } else {
                    isEnd = true;
                }
                break;
            case HEAD_FIND:
                if (isdigit(*iter)) {
                    ret = ret * 10 + *iter - '0';
                    if (ret > INT_MAX)
                        isEnd = true;
                } else {
                    isEnd = true;
                }
                break;
            }
        }

        if (!positive)
            ret = -1 * ret;

        if (ret < INT_MIN)
            return INT_MIN;
        if (ret > INT_MAX)
            return INT_MAX;
        return ret;
    }
};


void test008()
{
    Solution s;
    std::cout << s.myAtoi(std::string("42")) << std::endl;
    std::cout << s.myAtoi(std::string("-42")) << std::endl;
    std::cout << s.myAtoi(std::string("4193 with words")) << std::endl;
    std::cout << s.myAtoi(std::string("words and 987")) << std::endl;
    std::cout << s.myAtoi(std::string("-91283472332")) << std::endl;
}
