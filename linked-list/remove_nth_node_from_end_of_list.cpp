// LeetCode Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nl = new ListNode();
        nl->next=head;
        ListNode *temp=nl,*temp1=nl;
        while(n--){
            temp=temp->next;
        }
        while(temp->next != NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        temp1->next = temp1->next->next;
        return nl->next;
    }
};