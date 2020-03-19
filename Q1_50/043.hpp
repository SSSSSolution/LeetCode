#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 清晰模拟数乘
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return string("");
        if (num1 == "0" || num2 == "0")
            return string("0");
        vector<string> multRet;
        string ret;
        inverse(num1);
        inverse(num2);

        for (unsigned int i = 0; i < num1.size(); ++i) {
            string tmp = multiply(num2, num1[i]);
            inverse(tmp);
            for (int j = i; j > 0; --j) {
                tmp.push_back('0');
            }
            inverse(tmp);
            multRet.push_back(tmp);
        }
        ret = multRet[0];
        for (unsigned int i = 1; i < multRet.size(); ++i) {
            ret = plus(ret, multRet[i]);
        }
        inverse(ret);
        return ret;
    }

    string multiply(const string &num, char c) {
        string str;
        char carry = 0;
        for (unsigned int i = 0; i < num.size(); ++i) {
            char ret = (num[i]-'0') * (c - '0') + carry;
            str.push_back(ret%10+'0');
            carry = ret/10;
        }
        if (carry > 0)
            str.push_back(carry+'0');

        return str;
    }

    string plus(const string &num1, const string &num2) {
        string str;
        char carry = 0;
        unsigned int i = 0;
        for ( ; i < num1.size() && i < num2.size(); ++i) {
            char ret = (num1[i]-'0') + (num2[i]-'0') + carry;
            str.push_back(ret%10+'0');
            carry = ret/10;
        }
        while ( i < num1.size()) {
            char ret = (num1[i]-'0' + carry);
            str.push_back(ret%10 + '0');
            carry = ret/10;
            i++;
        }
        while ( i < num2.size()) {
            char ret = (num2[i]-'0' + carry);
            str.push_back(ret%10 + '0');
            carry = ret/10;
            i++;
        }

        if (carry > 0) {
            str.push_back(carry+'0');
        }

        return str;
    }

    void inverse(string &str) {
        for (unsigned int i = 0; i < str.size()/2; ++i) {
            char tmp = str[i];
            str[i] = str[str.size()-i-1];
            str[str.size()-i-1] = tmp;
        }
    }
};

void test043() {
    Solution s;
    string str("");
    string str1("4");
    cout << s.multiply(str, str1) << endl;
}
