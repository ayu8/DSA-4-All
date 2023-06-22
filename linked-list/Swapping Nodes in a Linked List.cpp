class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*p = head;
        ListNode* q = head;
        int count = 0;
        while(p!=NULL){
            count++;
            p=p->next;
        }
        p = head;
        for(int i = 0;i<k-1;i++){
            p = p->next;
        }
        for(int i =0;i<count-k;i++){
            q = q->next;
        }
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        return head;
    }
};
