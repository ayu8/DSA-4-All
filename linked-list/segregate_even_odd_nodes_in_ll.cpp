// C++ program to segregate even and
// odd nodes in a Linked List
#include <bits/stdc++.h>
using namespace std;

/* a node of the singly linked list */
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
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning */
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data <<" ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Let us create a sample linked list as following
	0->2->4->6->8->10->11 */

	push(&head, 11);
	push(&head, 10);
	push(&head, 8);
	push(&head, 6);
	push(&head, 4);
	push(&head, 2);
	push(&head, 0);

	cout << "Original Linked list ";
	printList(head);

	segregateEvenOdd(head);

	cout << "\nModified Linked list ";
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra
