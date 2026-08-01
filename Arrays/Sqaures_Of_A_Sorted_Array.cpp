/*
Problem: Squares of a Sorted Array
LeetCode: 977
Link: https://leetcode.com/problems/squares-of-a-sorted-array/

Approach:
- Traverse the array and replace each element with its square.
- Sort the array after squaring all the elements.
- Return the sorted array of squared values.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
            }
            sort(nums.begin(),nums.end());
            return nums;
        }
    };