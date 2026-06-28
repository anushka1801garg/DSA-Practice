/*
Problem: Remove Element
LeetCode: 27
Link: https://leetcode.com/problems/remove-element/

Approach:
- Use a pointer `k` to track the position where the next valid element should be placed.
- Traverse the array from left to right.
- If the current element is not equal to `val`, copy it to index `k` and increment `k`.
- Elements equal to `val` are skipped.
- After processing all elements, the first `k` positions contain the required elements.
- Return `k`, the count of elements not equal to `val`.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int k=0,count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=val){
                    nums[k]=nums[i];
                    k++;
                    count++;
                }
            }
            return k;
        }
    };