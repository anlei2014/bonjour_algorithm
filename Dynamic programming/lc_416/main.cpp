#include <iostream>
#include <vector>

using namespace std;

//416. 分割等和子集
/*给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

    示例 1：

    输入：nums = [1,5,11,5]
    输出：true
    解释：数组可以分割成 [1, 5, 5] 和 [11] 。
    示例 2：

    输入：nums = [1,2,3,5]
    输出：false
    解释：数组不能分割成两个元素和相等的子集。

 */

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        // 计算总和
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        //奇数没办法拆分，直接返回
        if (sum % 2 == 1) return false;
        // 一半
        int target = sum / 2;

        //初始化
        vector<int> dp(target + 1, 0);

        //开始01背包
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) { // 第i个元素一定比j小才能放进去，并且每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

//        for (int i:dp) {
//            cout << i <<endl;
//        }
        //集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
        return false;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> v = {1,5,11,5};
    Solution s;
    cout << s.canPartition(v);
    return 0;
}
