#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char,int> map;
        for (int i = 0; i < s.length(); ++i)
        {
            map[s[i]]++;
            map[t[i]]--;
        }
        for (auto kv : map) {
            if (kv.second != 0)
                return false;
        }
        return true;
    }
};

int main() {

    bool a;
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    a = solution.isAnagram(s,t);
    std::cout << a << std::endl;
    return 0;
}
