#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//#define min(a, b) (((a) < (b)) ? (a) : (b))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int cap;
        for (unsigned int i = 0; i < height.size()-1; ++i) {
            for (unsigned int j = 1; j < height.size(); ++j) {
                cap = min(height[i], height[j]) * abs(i-j);
                if (cap > max)
                    max = cap;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> height {
        1,8,6,2,5,4,8,3,7
    };
    cout << s.maxArea(height) << endl;
}
