/*
Problem: Move Zeroes
LeetCode: 283
Link: https://leetcode.com/problems/move-zeroes/

Approach:
Use two pointers.
Place non-zero elements first,
then fill remaining positions with 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>

using namespace std;

class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {

        int k = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {
                swap(nums[k], nums[i]);
                k++;
            }
        }
    }
};