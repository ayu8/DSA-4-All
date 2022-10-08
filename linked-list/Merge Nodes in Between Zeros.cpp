class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p!=NULL){
            if(p->val == 0){
                count++;
            }
            p=p->next;
        }
        p = head;
        int a[count-1];
        int i =0;
        p=p->next;
        while(p!=NULL){
            int sum = 0;
            while(p->val!=0){
                sum = sum+p->val;
                p=p->next;
            }
            a[i++]= sum;
            p=p->next;
        }
        ListNode* list = new ListNode(a[0]);
        ListNode* u = list;
        for(int i =1;i<count-1;i++){
           ListNode* t = new ListNode(a[i]) ;
            u->next = t;
            u = t;
        }
        return list;
    }
};
