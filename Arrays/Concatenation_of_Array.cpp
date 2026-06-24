/*
Problem: Concatenation of Array
LeetCode: 1929
Link: https://leetcode.com/problems/concatenation-of-array/

Approach:
Create a new array of size 2*n.
Traverse the original array once:
- Store nums[i] at index i.
- Store nums[i] again at index i+n.
Return the concatenated array.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            int n=nums.size();
            vector<int>ans(2*n);
            for(int i=0;i<n;i++){
                ans[i]=nums[i];
                ans[i+n]=nums[i];
            }
            return ans;
        }
    };