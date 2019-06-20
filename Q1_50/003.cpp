#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    struct Info {
        bool exist;
        int index;
    };
    Info infos[256];

    int lengthOfLongestSubstring(string s) {
        int max = 0, curmax = 0;

        clearInfos();
        for (unsigned int i = 0; i < s.size(); i++) {
            unsigned char c = (unsigned char)s[i];
            if (infos[c].exist) { //重复
                //更新infos
                updateInfos(infos[c].index);
                // 更新当前最大长度
                curmax = 1;
            } else { //没重复
                infos[c].exist = true;
                infos[c].index = i;
                curmax++;
                if (max < curmax)
                    max = curmax;
            }
        }
        return max;
    }

    void clearInfos() {
        for (int i = 0; i < 256; i++) {
            infos[i].exist = false;
            infos[i].index = -1;
        }
    }

    void updateInfos(int idx) {
        // 清理掉index小于idx的info
        for (int i = 0; i < 256; i++) {
            if (infos[i].index < idx)
                infos[i].exist = false;
        }
    }
};

int main() {
    Solution s;
    vector<string> strings {
        "abcabcbb",
        "bbbbb",
        "pwwkew"
    };

    for (unsigned int i = 0; i < strings.size(); i++ ) {
        std::cout << s.lengthOfLongestSubstring(strings[i]) << std::endl;
    }
}



















