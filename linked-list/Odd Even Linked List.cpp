class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         if(head==NULL || head->next==NULL || head->next->next== NULL) return head;
        ListNode* head2 = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        while( odd->next!=NULL && even->next !=NULL){
            odd->next = even->next ;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = head2;
        return head;
    }
};
