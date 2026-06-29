/*
Problem: Reverse Linked List
LeetCode: 206
Link: https://leetcode.com/problems/reverse-linked-list/

Approach:
- Handle the edge cases where the list is empty or has only one node.
- Traverse the linked list using three pointers:
  - `temp` for the current node.
  - `prev` for the previous node.
  - `front` to store the next node before changing links.
- Reverse the `next` pointer of each node to point to its previous node.
- Move all pointers one step forward until the end of the list.
- Return `prev`, which becomes the new head of the reversed list.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include<bits/stdc++.h>

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head==NULL || head->next==NULL)
            {
                return head;
            }
    
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp != NULL)
            {
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }
            return prev;
        }
    };