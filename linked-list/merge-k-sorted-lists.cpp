// Problem LINK: https://leetcode.com/problems/merge-k-sorted-lists/

// Problem Statement
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/

/* Algorithm Explained with Complexity
During 1st iteration, we merge two lists(every list is N) into one, this will make K down to K / 2.

During 2nd iteration, we merge two lists(every list is 2N) into one, this will make K / 2 down to k /4.

During 3rd iteration, we merge two lists(every list is 4N) into one, this will make K / 4 down to k /8.

And so forth...

I think when we merge two lists, the complexity is O(list1.length) + O(list2.length).

So the total complexity is:

(2N) * (K / 2) + 
(4N) * (K / 4) + 
(8N) * (K / 8) + 
.............. + 
(2^logK*N) * (K / (2 ^logK)) 

= logK*KN
*/

#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    // allocate node
    struct Node* new_node = new Node();
  
    // put in the data
    new_node->data = data;
    new_node->next = NULL;
  
    return new_node;
}
    struct compare 
    {
    bool operator()(
        struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};
  
// function to merge k sorted linked lists
struct Node* mergeKSortedLists(struct Node* arr[], int k)
{
    priority_queue<Node*, vector<Node*>, compare> p;
  
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            p.push(arr[i]);
            if (p.empty())
        return NULL;
    
      struct Node *dummy = newNode(0);
      struct Node *last = dummy;
    
    while (!p.empty()) 
    {
  
        struct Node* curr = p.top();
        p.pop();
         last->next = curr;
          last = last->next;  
        
        if (curr->next != NULL)
            // push the next node of top node in 'p'
            p.push(curr->next);
    }
      return dummy->next;
}
  
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
  
int main()
{
    int k = 3; // Number of linked lists
    int n = 3; // Number of elements
     Node* arr[k];
  
    arr[0] = newNode(1);
    arr[0]->next = newNode(4);
    arr[0]->next->next = newNode(5);
  
    arr[1] = newNode(1);
    arr[1]->next = newNode(3);
    arr[1]->next->next = newNode(4);
  
    arr[2] = newNode(2);
    arr[2]->next = newNode(6);
  
    // merge the k sorted lists
    struct Node* head = mergeKSortedLists(arr, k);
  
    // print the merged list
    printList(head);
  
    return 0;
}

