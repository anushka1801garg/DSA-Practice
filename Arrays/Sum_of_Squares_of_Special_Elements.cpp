/*
Problem: Sum of Squares of Special Elements
LeetCode: 2778
Link: https://leetcode.com/problems/sum-of-squares-of-special-elements/

Approach:
- Find the size of the array `n`.
- Traverse the array using index `i`.
- Check whether `n` is divisible by `i + 1`, since array positions are 1-indexed for this condition.
- If divisible, add the square of `nums[i]` to `ans`.
- Return `ans` after checking all elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include<vector>
using namespace std;

class Solution {
    public:
        int sumOfSquares(vector<int>& nums) {
            int ans=0;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(n%(i+1)==0) ans+=nums[i]*nums[i];
            }
            return ans;
        }
    };