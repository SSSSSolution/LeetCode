// 6. Z字形变换
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 迭代法
    string convert1(string s, int numRows) {
        if (numRows == 1)
            return s;
        if (s.empty())
            return s;

        int groupSize = 2*numRows-2;
        int groupNum = s.length()/groupSize + (s.length()%(groupSize) != 0);

        string ret;
        ret.resize(s.length());

        int index = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < groupNum; j++) {
                if (j*groupSize+i < s.length()) {
                    ret[index++] = s[j*groupSize+i];
                }
                if (i >= 1 && i <numRows-1) {
                    if (j*groupSize+groupSize-i < s.length())
                        ret[index++] = s[j*groupSize+groupSize-i];
                }
            }
        }
        return ret;
    }

    // 排列法
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        if (s.empty())
            return s;

        vector<vector<char> > vectors;
        for (unsigned int i = 0; i < numRows; i++) {
            vector<char> vec;
            vectors.push_back(vec);
        }

        for (unsigned int i = 0; i < s.size(); i++) {
            vectors[whichRow(i, numRows)].push_back(s[i]);
        }

        string ret;
        for (int i = 0; i < vectors.size(); i++) {
            for (int j = 0; j < vectors[i].size(); j++) {
                ret.push_back(vectors[i][j]);
            }
        }
        return ret;
    }

    inline int whichRow(int index, int numRows) {
        if (index%(2*numRows-2) < numRows) {
            return index%(2*numRows-2);
        } else {
            return 2*numRows -2 - (index%(2*numRows-2));
        }
    }
};

int main() {
    Solution s;
    string str("PAYPALISHIRING");
    cout << s.convert(str, 3) << endl;
}
