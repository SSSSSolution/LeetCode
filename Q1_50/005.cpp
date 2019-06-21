#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // 动态规划法
    string longestPalindrome1(string s) {
        int maxlen = 1;
        int head = 0;
        int tail = 0;

        bool **table = (bool **)malloc(sizeof(bool *)*s.size());
        for (int i = 0; i < s.size(); ++i) {
            table[i] = (bool *)calloc(s.size(), sizeof(bool));
        }
        for (int i = 0; i < s.size(); ++i) {
            table[i][i] = true;
            if (i < s.size()-1 && s[i] == s[i+1]) {
                table[i][i+1] = true;
                maxlen = 2;
                head = i;
                tail = i+1;
            }
        }

        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = s.size()-1; j >= 0; --j) {
                if (table[i][j] && i-1>= 0 && j+1 < s.size() && s[i-1] == s[j+1]) {
                    table[i-1][j+1] = true;
                    if (j+1-i+1+1 > maxlen) {
                        maxlen = j-i+3;
                        head = i-1;
                        tail = j+1;
                    }
                }
            }
        }
        string str = s.substr(head, tail-head+1);
        return str;
    }
    // 中心扩散法
    string longestPalindrome(string s) {
        int maxlen = 1;
        int curlen = 1;
        int head = 0, tail = 0;
        if (s.size() == 0)
            return string("");
        for (int i = 0; i < s.size(); i++) {
            int pBack, pFront;
            pBack = i-1; pFront = i+1;
            curlen = 1;
            while(pBack >= 0 && pFront < s.size()) {
                if (s[pBack--] == s[pFront++]) {
                    curlen+=2;
                    if (curlen > maxlen) {
                        maxlen = curlen;
//                        std::cout << "maxlen1" <<maxlen <<std::endl;
                        head = pBack+1;
                        tail = pFront-1;
                    }
                } else {
                    break;
                }
            }

            if (s[i] == s[i+1]) {
                curlen = 2;
                if (curlen > maxlen) {
                    maxlen = curlen;
                    head = i;
                    tail = i+1;
//                    std::cout << "maxlen2" <<maxlen << std::endl;
                }
                int pBack, pFront;
                pBack = i-1; pFront = i+2;
                while(pBack >= 0 && pFront < s.size()) {
                    if (s[pBack--] == s[pFront++]) {
                        curlen+=2;
                        if (curlen > maxlen) {
                            maxlen = curlen;
//                            std::cout << "maxlen2" <<maxlen << std::endl;
                            head = pBack+1;
                            tail = pFront-1;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        string str = s.substr(head, tail-head+1);
        return str;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome(string("ccc"))<< endl;

}
