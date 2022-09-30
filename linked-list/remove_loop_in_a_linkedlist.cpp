 void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        
        Node *slow = head, *fast = head;
        
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                Node *ptr1 = slow;
                Node *ptr2 = slow;
                
                int num = 1;
                while (ptr1->next != ptr2) {
                    ptr1 = ptr1->next;
                    num++;
                }
                
                ptr1 = head;
                ptr2 = head;
                
                for (int i=0; i<num; i++) {
                    ptr2 = ptr2->next;
                }
                
                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                    //cout << ptr1->data << ", and " << ptr2->data;
                }
                    
                while (ptr2->next != ptr1)
                    ptr2 = ptr2->next;
                    
                ptr2->next = NULL;
            }
                
        }
            
    }

// question link:
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
