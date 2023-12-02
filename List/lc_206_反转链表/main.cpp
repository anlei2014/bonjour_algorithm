#include <iostream>

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* pre = head;
        // 遍历链表，结束条件是pre指到最后的空
        while (pre != nullptr)
        {
            ListNode* tmp = pre->next;
            pre->next = cur;
            // 移动指针
            cur = pre;
            pre = tmp;
        }
        return cur;
    }
};

void test()
{
    /* 初始化链表 1 -> 2 -> 3 -> 4 -> 5 */
    // 初始化各个节点
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);

    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution s;
    s.reverseList(n0);

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
