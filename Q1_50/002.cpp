#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution002 {
public:
    Solution002() {}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int curVal;
        int carry = 0;
        ListNode *head = NULL;
        ListNode *last = NULL;

        while (l1 != NULL && l2 != NULL) {
            curVal = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
//            ListNode *newNode = new ListNode(curVal);
            ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->val = curVal;
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
                last = head;
            } else {
                last->next = newNode;
                last = last->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            curVal = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
//            ListNode *newNode = new ListNode(curVal);
            ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->val = curVal;
            newNode->next = NULL;
            last->next = newNode;
            last = last->next;
            l1 = l1->next;
        }

        while (l2) {
            curVal = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
//            ListNode *newNode = new ListNode(curVal);
            ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->val = curVal;
            newNode->next = NULL;
            last->next = newNode;
            last = last->next;
            l2 = l2->next;
        }

        if (carry != 0) {
//            ListNode * newNode = new ListNode(carry);
            ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->val = carry;
            newNode->next = NULL;
            last->next  = newNode;
        }

        return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    ListNode *l11 = new ListNode(4);
    ListNode *l12 = new ListNode(3);
    l1->next = l11;
    l11->next = l12;

    ListNode *l2 = new ListNode(5);
    ListNode *l21 = new ListNode(6);
    ListNode *l22 = new ListNode(4);
    l2->next = l21;
    l21->next = l22;

    Solution002 s;
    ListNode *ret = s.addTwoNumbers(l1, l2);
    ListNode *p = ret;
    while (p != NULL) {
        std::cout << p->val;
        p=p->next;
    }

    return 0;
}
