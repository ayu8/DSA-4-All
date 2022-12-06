// LEETCODE
// Link: https://leetcode.com/problems/odd-even-linked-list/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *evenStart=even;
        while(odd->next!=NULL && even->next!=NULL)
        {
            odd->next=even->next;
            even->next=odd->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenStart;
        return head;
    }
};
