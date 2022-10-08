//GFG code Link : - https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

class Node
{
	public:
	int data;
	Node *next;
};

Node* segregateEvenOdd(Node *head){
        // code here
       Node* even = NULL;
       Node* odd = NULL;
       Node* e =NULL;
       Node* o = NULL;

       while(head){
           if(head->data%2 ==0 ){
               if(even == NULL){
                   even = head;
                   e = head;
               }
               else{
                   e->next = head;
                   e = e->next;
               }
           }
           else{
               if(odd == NULL){
                   odd = head;
                   o = head;
               }
               else{
                   o->next = head;
                   o = o->next;
               }
           }
           head = head->next;
       }
        if(e) e->next = odd;
        if(o) o->next = NULL;
        if(even) return even;
        return odd;
}

void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data <<" ";
		node = node->next;
	}
}
