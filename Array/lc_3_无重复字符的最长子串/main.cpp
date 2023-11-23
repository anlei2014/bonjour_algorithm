#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0, length = s.length();
        int start = 0, end = 0;
        while(end <= length){
            // 发现有重复字符时，可以直接把左指针移动到重复字符的下一个位置
            for(int i = start; i < end; i++){
                if(s[i] == s[end]){
                    start = i+1;
                    break;
                }
            }
            result = max(result, end-start+1);
            end++;
        }
        return result;
    }
};

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

void test()
{
    Solution s;
    string  s1 = "abcabcbb";
//    string  s1 = "abcdeafghi";
    int res =0;
    res = s.lengthOfLongestSubstring(s1);
    cout << res <<endl;

}

int main() {

    test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
