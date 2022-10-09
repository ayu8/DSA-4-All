// Problem Link : https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

// Problem Statement :

// Given K sorted linked lists of size N each, merge them and print the sorted output.

// Examples: 

// Input: k = 3, n =  4
// list1 = 1->3->5->7->NULL
// list2 = 2->4->6->8->NULL
// list3 = 0->9->10->11->NULL

// Output: 0->1->2->3->4->5->6->7->8->9->10->11
// Merged lists in a sorted order 
// where every element is greater 
// than the previous element.

// Input: k = 3, n =  3
// list1 = 1->3->7->NULL
// list2 = 2->4->8->NULL
// list3 = 9->10->11->NULL

// Output: 1->2->3->4->7->8->9->10->11
// Merged lists in a sorted order 
// where every element is greater 
// than the previous element.

// *****************************************************************************************
// Code


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void printList(Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

Node* mergeKLists(Node* arr[], int last)
{
	for (int i = 1; i <= last; i++) {
		while (true) {
			Node *head_0 = arr[0], *head_i = arr[i];
			if (head_i == NULL)
				break;

			if (head_0->data >= head_i->data) {
				arr[i] = head_i->next;
				head_i->next = head_0;
				arr[0] = head_i;
			}
			else
				while (head_0->next != NULL) {
					if (head_0->next->data
						>= head_i->data) {
						arr[i] = head_i->next;
						head_i->next = head_0->next;
						head_0->next = head_i;
						break;
					}
					head_0 = head_0->next;

					if (head_0->next == NULL) {
						arr[i] = head_i->next;
						head_i->next = NULL;
						head_0->next = head_i;
						head_0->next->next = NULL;
						break;
					}
				}
		}
	}

	return arr[0];
}

Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int main()
{
	// Number of linked lists
	int k = 3;

	// Number of elements in each list
	int n = 4;

	// an array of pointers storing the
	// head nodes of the linked lists
	Node* arr[k];

	arr[0] = newNode(1);
	arr[0]->next = newNode(3);
	arr[0]->next->next = newNode(5);
	arr[0]->next->next->next = newNode(7);

	arr[1] = newNode(2);
	arr[1]->next = newNode(4);
	arr[1]->next->next = newNode(6);
	arr[1]->next->next->next = newNode(8);

	arr[2] = newNode(0);
	arr[2]->next = newNode(9);
	arr[2]->next->next = newNode(10);
	arr[2]->next->next->next = newNode(11);

	// Merge all lists
	Node* head = mergeKLists(arr, k - 1);

	printList(head);

	return 0;
}
