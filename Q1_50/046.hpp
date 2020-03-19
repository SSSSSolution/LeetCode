#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        backTrace(ret, cur, nums);

        return ret;
    }

    void backTrace(vector<vector<int>> &ret, vector<int> &cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            ret.push_back(cur);
            cur.pop_back();
            return;
        }
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (!contain(cur, nums[i])) {
                cur.push_back(nums[i]);
                backTrace(ret, cur, nums);
            }
        }
        cur.pop_back();
    }

    bool contain(vector<int> &vec, int v) {
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == v)
                return true;
        }
        return false;
    }

    void printVector(vector<int>  &vec) {
        for (unsigned int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout <<endl;
    }
};

int test046() {
    Solution s;
    vector<vector<int>> ret;
    vector<int> nums {
        1, 2, 3
    };
    ret = s.permute(nums);
    for (int i = 0; i < ret.size(); ++i) {
        s.printVector(ret[i]);
    }
}






















