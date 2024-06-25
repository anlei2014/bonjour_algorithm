#include <iostream>
#include <vector>

using namespace std;

/**
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 *
 *
 * */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // 横向
        int m = obstacleGrid.size();
        //纵向
        int n = obstacleGrid[0].size();

        // 如果在起点或者终点出现了障碍，则直接返回0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1]) {
            return 0;
        }

        //定义一个二维m行xn列的二维数组，存储值,初始化为0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //初始化
        // 注意代码里for循环的终止条件，一旦遇到obstacleGrid[i][0] == 1的情况就停止dp[i][0]的赋值1的操作，dp[0][j]同理
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }

        //遍历
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        return dp[m-1][n-1];
    }
};


int main() {

    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> err = {{0,0,0},
                               {0,1,0},
                               {0,0,0}};
    Solution s;
    auto m = s.uniquePathsWithObstacles(err);
    cout << m;
    return 0;
}
