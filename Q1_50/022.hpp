// 22括号生成
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> stack;
        vector<string> ret;
        process(n ,'(', 2*n, stack, 0, ret);
        return ret;
    }

    void process(int n, char c, int depth, vector<char> &stack, int moreLeft, vector<string> &ret) {
        if (c == '(') {
            if (depth == 1)
                return;
            if (moreLeft >= n)
                return;
            stack.push_back(c);
            moreLeft++;
            process(n, '(', depth-1, stack, moreLeft, ret);
            process(n, ')', depth-1, stack, moreLeft, ret);
        } else {
            if (moreLeft == 0)
                return;
            stack.push_back(c);
            if (depth == 1) {
                if (moreLeft == 1)
                    ret.push_back(genStringFromStack(stack));
            } else if (moreLeft > 0) {
                moreLeft--;
                process(n, '(', depth-1, stack, moreLeft, ret);
                process(n, ')', depth-1, stack, moreLeft, ret);
            }
        }
        stack.pop_back();
        return;
    }

    string genStringFromStack(vector<char> &stack) {
        string ret;
        for (int i = 0; i < stack.size(); i++) {
            ret.push_back(stack[i]);
        }
        return ret;
    }

    void printStack(vector<char> &stack) {
        for (int i = 0; i < stack.size(); i++) {
            cout << stack[i];
        }
        cout <<endl;
    }
};

void test022()
{
    Solution s;
    vector<string> ret;
    ret = s.generateParenthesis(4);
    for (string str : ret) {
        cout << str << endl;
    }
}
