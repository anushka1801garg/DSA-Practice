/*
Problem: Linked List Cycle
LeetCode: 141
Link: https://leetcode.com/problems/linked-list-cycle/

Approach:
- Use Floyd's Cycle Detection (Tortoise and Hare) algorithm.
- Initialize two pointers, `slow` and `fast`, at the head of the list.
- Move `slow` one step and `fast` two steps in each iteration.
- If the two pointers meet, a cycle exists in the linked list.
- If `fast` or `fast->next` becomes `NULL`, the list has no cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include<bits.stdc++.h>

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *slow=head;
            ListNode *fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    return true;
                }
            }
            return false;
            
        }
    };