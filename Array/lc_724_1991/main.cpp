#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.cn/problems/find-pivot-index/solutions/1645928/by-jyd-9265/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = 0;
        int left = 0;
        // 先遍历容器，得到总和
        for (int num : nums) {
            sum += num;
        }

        // 前缀和思想
        // 思路：左求和*2+中心索引值 = 总和
        for (int i = 0; i < nums.size(); ++i) {
            // 这里一定要先进行判断，满足前缀和，则返回
            if (2 * left + nums[i]== sum)
            {
                return i;
            }
            // 进行左侧数值的累加
            left+=nums[i];
        }
        return -1;
    }
};

void test()
{
    int a;
    Solution s;
//    vector<int> nums = {1, 7, 3, 6, 5, 6};
    vector<int> nums = {-1,-1,-1,0,1,1};
    a = s.pivotIndex(nums);
    cout << a << endl;
}




int main() {

    test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
