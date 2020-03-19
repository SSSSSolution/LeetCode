#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedian(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1);
    }

    double findMedian(vector<int> &a, int aStart, int aEnd, vector<int> &b, int bStart, int bEnd) {
        std::cout << aStart <<"," <<aEnd <<","<<bStart<<","<<bEnd << std::endl;
        if (aEnd < aStart) { // a为空，b不为空
            std::cout << "a is null" << std::endl;
            return median(b, bStart, bEnd);
        } else if (bEnd < bStart) { // b为空，　a 不为空
            std::cout << "b is null" << std::endl;
            return median(a, aStart, aEnd);
        } else {
            if (aStart - aEnd == 0 && bEnd - bStart == 0) {
                return (1.0*a[(aStart+aEnd)/2] + 1.0*b[(bStart+bEnd)/2])/2.0;
            }
            int aM, bM, aL, aR, bL, bR;
            aL = aM = (aEnd+aStart)/2;
            bL = bM = (bEnd+bStart)/2;
            aR = (aEnd+aStart)/2+1;
            bR = (bEnd+bStart)/2+1;
            //a和b的个数都是奇数
            if (((aEnd-aStart+1)%2 == 1) && ((bEnd-bStart+1)%2 == 1)) {
                std::cout << "a and b are odd" << std::endl;
                if (a[aM] == b[bM]) {
                    return (double)a[aM];
                } else if (a[aM] > a[bM]) {
                    aEnd = aM;
                    bStart = bM;
                } else {
                    aStart = aM;
                    bEnd = bM;
                }
              // a和b的个数都是偶数
            } else if (((aEnd-aStart+1)%2 == 0) && ((bEnd-bStart+1)%2 == 0)) {
                std::cout << "a and b are even" << std::endl;
                if (b[bR] < a[aL]) {
                    bStart = bR;
                    aEnd = aL;
                } else if (a[aR] < b[bL]) {
                    aStart = aR;;
                    bEnd = bL;
                } else { // aL, aR, bL, bR四个数相等
                    return (double)a[aL];
                }
                // a奇数b偶数
            } else if (((aEnd-aStart+1)%2 == 1) && ((bEnd-bStart+1)%2 == 0) ) {
                std::cout << "a is odd, b is even" << std::endl;
                if (b[bR] <= a[aM]) {
                    aEnd = aM;
                    bStart = bR;
                } else if (b[bL] >= a[aM]) {
                    aStart = aM;
                    bEnd = bL;
                } else {
                    return (double)a[aM];
                }
                // b奇数a偶数
            } else {
                std::cout << "a is even, b is odd" << std::endl;
                if (a[aR] <= b[bM]) {
                    bEnd = bM;
                    aStart = aR;
                } else if (a[aL] >= b[bM]) {
                    bStart = bM;
                    aEnd = aL;
                } else {
                    return (double)a[bM];
                }
            }
            return findMedian(a, aStart, aEnd, b, bStart, bEnd);
        }
    }

    double median(vector<int> &a, int s, int e) {
        if ((e-s+1)%2 == 1) {
            return a[s+(e-s+1)/2];
        } else {
            return (1.0*a[s+(e-s)/2] + 1.0*a[s+(e-s)/2+1])/2.0;
        }
    }
};

void test004()
{
    Solution s;
    vector<int> v1{1,3};
    vector<int> v2{2};

    std::cout << s.findMedianSortedArrays(v1, v2) << std::endl;
}

