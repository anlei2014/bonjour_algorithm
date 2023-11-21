#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
 * 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 *
 *  示例 1：
    输入：intervals = [[1,3],
                      [2,6],
                      [8,10],
                      [15,18]]
    输出：[[1,6],[8,10],[15,18]]
    解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
    示例 2：
    输入：intervals = [[1,4],[4,5]]
    输出：[[1,5]]
    解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *  提示：
    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104
 *
 * */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //先定义一个集合，当做返回值
        vector<vector<int>> vec;
        int j = 0;
        if (intervals.size() == 1)
            return intervals;

        // 对容器进行排序
        sort(intervals.begin(),intervals.end());
        //小技巧，这里先把第一个元素放进新的集合，方便后面做比较，通过数组的下表修改值
        vec.push_back(intervals[0]);

        for (int i = j + 1; i < intervals.size(); ++i)
        {
            // 比较前一个数组的第二个元素比后一个数组的第一个元素大，则进行合并
            if (vec[j][1] >= intervals[i][0])
            {
                // 合并的时候要去最大值，因为有可能前一个数组的第二个元素，比后一个数组的第二个元素还大
                vec[j][1] = max(vec[j][1],intervals[i][1]);
            }
            else
            {
                vec.push_back(intervals[i]);
                j++;
            }
        }
        return vec;
    }
};

void test()
{
    Solution s;
    vector<vector<int>> v2;
    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    v2 = s.merge(v1);
    for(vector<int> v : v2)
    {
        cout << v[0] << ":" << v[1] <<endl;
    }


}

int main() {
    test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
