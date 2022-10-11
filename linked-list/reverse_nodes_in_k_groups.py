#Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    #  pre, a ListNode
    # current, a ListNode
    #  k, an integer
    # return a ListNode
    def _reverseNextK(self, pre, current, k):
        # Not enough nodes to reverse
        if current == None:             return None, None
        # Last node to reverse
        if k == 1:
            nextNode = current.next
            current.next = pre
            return current, nextNode
        # Recursively reverse the remaining nodes
        newHead, nextHead = self._reverseNextK(current, current.next, k-1)
        if newHead == None:
            # Not enough nodes to reverse
            return None, None
        else:
            # Reversing
            current.next = pre
            return newHead, nextHead
    # head, a ListNode
    #  k, an integer
    #  a ListNode
    def reverseKGroup(self, head, k):
        newHead, nextHead = self._reverseNextK(None, head, k)
        if newHead == None:             return head         # Not enough nodes to reverse
        else:                           result = newHead    # Record the new head node
        preTail = head
        # As long as there are enough nodes to reverse, do it.
        while nextHead != None:
            currentNode = nextHead
            # Reverse the nodes inside the next K-group
            newHead, nextHead = self._reverseNextK(None, currentNode, k)
            if newHead != None:         preTail.next = newHead      # Reversed
            else:                       preTail.next = currentNode  # Not reversed
            preTail = currentNode
        return result
