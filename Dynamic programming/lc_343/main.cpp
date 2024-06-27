#include <iostream>
#include <vector>

using namespace std;

/*给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积 。

示例 1:
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

 示例 2:
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

提示:
2 <= n <= 58
*/

/*动规五部曲，分析如下：
1:确定dp数组（dp table）以及下标的含义
    dp[i]：分拆数字i，可以得到的最大乘积为dp[i]。
2:确定递推公式
    可以想 dp[i]最大乘积是怎么得到的呢？
    其实可以从1遍历j，然后有两种渠道得到dp[i].
    一个是j * (i - j) 直接相乘。
    一个是j * dp[i - j]，相当于是拆分(i - j)，对这个拆分不理解的话，可以回想dp数组的定义。
    dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
 */
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    cout << s.integerBreak(10);
    return 0;
}
