class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int> q;
        ListNode* p = head;
        int count =0;
        while(p!=NULL){
            count++;
            q.push_back(p->val);
            p=p->next;
        }
        int a[count/2];
        int i =0;
        while(!q.empty()){
            int x = q.front();
            int y = q.back();
            q.pop_front();
            q.pop_back();
            a[i++] = x+y;
        }
        
        return *max_element(a,a+count/2);
    }
};
