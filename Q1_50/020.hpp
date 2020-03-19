#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                stack.push_back(s[i]);
            } else if (s[i] == ']') {
                if (stack.empty()) return false;
                if (stack.back() == '[')
                    stack.pop_back();
                else
                    return false;
            } else if (s[i] == '}') {
                if (stack.empty()) return false;
                if (stack.back() == '{')
                    stack.pop_back();
                else
                    return false;
            } else if (s[i] == ')') {
                if (stack.empty()) return false;
                if (stack.back() == '(')
                    stack.pop_back();
                else
                    return false;
            }
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
};

void test020()
{
    Solution s;
    string str("(((({{{{}}}}}))))[]]");
    cout << s.isValid(str) << endl;

    return 0;
}
