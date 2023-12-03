#include <iostream>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;

        while (curA != NULL)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA) {
            swap (lenA, lenB);
            swap (curA, curB);
        }

        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }

        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};


int main() {
    ListNode* headA = new ListNode(4);
    ListNode* headA1 = new ListNode(1);
    ListNode* headA2 = new ListNode(8);
    ListNode* headA3 = new ListNode(4);
    ListNode* headA4 = new ListNode(5);

    ListNode* headB = new ListNode(5);
    ListNode* headB1 = new ListNode(0);
    ListNode* headB2 = new ListNode(1);
    ListNode* headB3 = new ListNode(8);
    ListNode* headB4 = new ListNode(4);
    ListNode* headB5 = new ListNode(5);

    //连接链表
    headA->next = headA1;
    headA1->next = headA2;
    headA2->next = headA3;
    headA3->next = headA4;

    headB->next = headB1;
    headB1->next = headB2;
    headB2->next = headB3;
    headB3->next = headB4;
    headB4->next = headB5;

    ListNode* res;
    Solution s;
    res = s.getIntersectionNode(headA,headB);

    std::cout << res->val << std::endl;
    std::cout << s.getIntersectionNode(headA,headB)->val << std::endl;
    return 0;
}
