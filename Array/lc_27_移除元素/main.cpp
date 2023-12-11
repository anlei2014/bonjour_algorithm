#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int slow = 0;

        for (int fast = 0; fast < n; ++fast) {

            //如果不是目标值，则两个指针都移动
            if (val != nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            // 如果是目标值，值移动快指针
            // ++fast;
        }
        return slow;
    }
};


int main() {
    vector<int> nums = {0,1,2,3,3,0,4,2};
    Solution solution;
    int a = solution.removeElement(nums,2);
    std::cout << a << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
