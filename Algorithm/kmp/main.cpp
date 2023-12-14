#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    void getNext (int* next, const string& s){

        // 
        next[0] = 0;
        int j = 0;
        for(int i = 1;i < s.size(); i++){
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
