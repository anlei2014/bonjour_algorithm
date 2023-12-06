#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getsum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;

    }
    bool isHappy(int n)
    {
        int res;
        unordered_set<int> set;
        while (1)
        {
            res = getsum(n);
            if (res == 1)
            {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(res) != set.end())
            {
                return false;
            } else
            {
                set.insert(res);
            }
            n = res;
        }

    }
};

int main() {
    bool a;
    Solution s;
    a = s.isHappy(2);
    std::cout << a << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
