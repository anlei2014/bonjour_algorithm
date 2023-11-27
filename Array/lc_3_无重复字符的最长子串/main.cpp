#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 3. 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
    输入: s = "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
    输入: s = "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
    输入: s = "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
    提示：
    0 <= s.length <= 5 * 104
    s 由英文字母、数字、符号和空格组成
 * */
 /*双指针*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int result = 0;
        int length = s.length();
        // 为了记录内存循环的位置
        int start = 0;
        // 双指针，i是快指针 ，j 是慢指针
        for (int i = 0; i < length; ++i) {
            for (int j = start; j < i; ++j) {
                if(s[i] == s[j]){
                    start = j + 1;
                    continue;
                }
            }
            result = max(result, i - start + 1);
        }
        return result;
    }
};

/* 滑动窗口*/
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        // 如果字符串为空，则返回0
        if (s.length() == 0)
        {
            return 0;
        }

        int start = 0;
        int end = 0;
        int len = 0;
        int res;
        // 创建哈希表，用于记录字符出现的位置
        unordered_map<char,int> map;

        while (end < s.size())
        {
            //find函数会返回迭代器，如果当前字符不重复，那么返回end()迭代器
            if (map.find(s[end]) != map.end())
            {
                start = map[s[end]] + 1;
                len = end - start;
            }
            map[s[end]] = end;

            end++;
            len++;
            res = max(res,len);
        }
        return res;
    }
};

void test()
{
    Solution s;
    string  s1 = "abcabcbb";
//    string  s1 = "abcdeafghi";
    int res =0;
    res = s.lengthOfLongestSubstring(s1);
    cout << res <<endl;

}
void test2()
{
    Solution s2;
    string  s1 = "abcabcbb";
//    string  s1 = "abcdeafghi";
    int res =0;
    res = s2.lengthOfLongestSubstring(s1);
    cout << res <<endl;

}
int main() {

    test();
    test2();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
