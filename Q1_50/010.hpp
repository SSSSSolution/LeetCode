#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        bool match = true;

        auto sIter = s.begin();
        for (auto iter = p.begin(); iter != p.end(); ++iter) {
            if (sIter == s.end()) {
                match = false;
                break;
            }
            switch (*iter) {
            case '.':

                break;
            case '*':
                break;
            default:
                break;
            }
        }

        return match;
    }
};
