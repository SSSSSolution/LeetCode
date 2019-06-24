#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0, right = height.size()-1;
        while(left != right) {
            int minH = min(height[left], height[right]);
            int curMax = (right-left) * minH;
            if (curMax > max) {
                max = curMax;
            }
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> vec {
        1,8,6,2,5,4,8,3,7
    };

    cout << s.maxArea(vec) << endl;
}
