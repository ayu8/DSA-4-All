// https://leetcode.com/problems/add-two-numbers/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0; 
        ListNode * curr = NULL, *prev = NULL, *next = NULL, *head;
        curr = new ListNode();
        head = curr;

        while (l1 != NULL && l2 != NULL) {
            sum += (l1->val) + (l2->val);
            curr->val = sum % 10;
            sum /= 10;
            prev = curr;
            curr = new ListNode();
            curr->next = NULL;
            prev->next = curr;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            sum += l1->val;
            curr->val = sum % 10;
            sum /= 10;
            prev = curr;
            curr = new ListNode();
            curr->next = NULL;
            prev->next = curr;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            sum += l2->val;
            curr->val = sum % 10;
            sum /= 10;
            prev = curr;
            curr = new ListNode();
            curr->next = NULL;
            prev->next = curr;
            l2 = l2->next;
        }

        if (sum == 0) {
            prev->next  = NULL;
            delete curr;
        }

        else {
            curr->val = sum;
            curr->next = NULL;
        }

        return head;
    }
};