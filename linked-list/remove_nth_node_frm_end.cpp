// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include<iostream>
#include<bits/stdc++.h>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL) return head;
        ListNode *p = head;
        int size = 0;
        while (p != NULL)
        {
            p = p->next;
            size++;
        }

        if (n==size)
        {
            head = head->next;
            return head;
        }

        if (n > size) return head;
        p = head;
        size = size - n;
        for (int i=0; i<size-1; i++)
        {
            p = p->next;
        }
        p->next = (p->next)->next;

        return head;
    }
};

int main()
{
    Solution s;
    ListNode *head;
    s.removeNthFromEnd(head, 3);

    return 0;
}
 