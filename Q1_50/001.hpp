#include <vector>
#include <map>
#include <ext/hash_map>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;


class Solution001 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        hash_map<int, int> map1;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = map1.find(nums[i]);
            if (it == map1.end()) {
                int index = target - nums[i];
                map1.insert(make_pair(index, i));
            } else {
                ret.push_back(it->second);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};

void test001()
{
    Solution001 s;
    vector<int> input;
    input.push_back(5);
    input.push_back(5);
    input.push_back(11);
    input.push_back(15);
    int target = 16;
    vector<int> ret = s.twoSum(input, target);
    cout << ret[0] << ", " << ret[1] << endl;
}
