/*
Problem: Maximum Product of Two Elements in an Array
LeetCode: 1464
Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

Approach:
- Sort the array in non-decreasing order.
- The two largest elements will be at the end of the sorted array.
- Subtract `1` from each of the two largest elements.
- Compute and return their product.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            return ((nums[n-1]-1)*(nums[n-2]-1));
        }
    };