// 合并有序链表
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0);
        ListNode  *p = &preHead, *p1 = l1, *p2 = l2;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = (p1 == NULL) ? p2 : p1;

        return preHead.next;
    }

    void printList(ListNode *head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode *l11 = new ListNode(1);
    ListNode *l12 = new ListNode(2);
    ListNode *l13 = new ListNode(4);
    l11->next = l12;
    l12->next = l13;
    l13->next = NULL;

    ListNode *l21 = new ListNode(1);
    ListNode *l22 = new ListNode(3);
    ListNode *l23 = new ListNode(4);
    l21->next = l22;
    l22->next = l23;
    l23->next = NULL;

    ListNode *head;
    Solution s;
    head = s.mergeTwoLists(l11, l21);
    s.printList(head);
}






















