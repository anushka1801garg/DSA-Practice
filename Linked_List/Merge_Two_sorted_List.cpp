/*
Problem: Reverse Linked List
LeetCode: 206
Link: https://leetcode.com/problems/reverse-linked-list/

Approach:
- Use three pointers to reverse the linked list iteratively.
- Traverse the list while storing the next node.
- Reverse the current node's `next` pointer to point to the previous node.
- Move all pointers forward until the end of the list.
- Return the previous pointer as the new head of the reversed list.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
            if(head1==NULL || head2==NULL){
                if(head1==NULL){
                    return head2;
                }
                else{
                    return head1;
                }
            }
            if(head1->val<=head2->val){
                head1->next=mergeTwoLists(head1->next,head2);
                return head1;
            }
            else{
                head2->next=mergeTwoLists(head1,head2->next);
                return head2;
            }
        }
    };