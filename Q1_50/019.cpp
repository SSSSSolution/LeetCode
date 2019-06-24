#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pPre = NULL, *p = head, *pN = head;
        for (int i = 0; i < n; i++) {
            pN = pN->next;
        }
        while (pN != NULL) {
            pPre = p;
            p = p->next;
            pN = pN->next;
        }
        if (pPre != NULL) {
            pPre->next = p->next;
        } else {
            head = p->next;
        }
        delete p;

        return head;
    }

    void printList(ListNode *head) {
        ListNode *p = head;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    Solution s;
    s.printList(head);

    head = s.removeNthFromEnd(head, 5);
    s.printList(head);

    return 0;
}

























