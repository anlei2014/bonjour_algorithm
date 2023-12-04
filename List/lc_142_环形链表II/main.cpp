#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

void printListNode(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }

}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                //快慢指针重合的时候,记录指针的值
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};

int main() {

    ListNode *res = nullptr;
    ListNode* head1 = new ListNode(3);
    ListNode* head2 = new ListNode(2);
    ListNode* head3 = new ListNode(0);
    ListNode* head4 = new ListNode(4);

    //构造环形链表
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head2;

    Solution s;
    res->next = s.detectCycle(head1);

    printListNode(res);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
