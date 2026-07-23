/*
Problem: Minimum Size Subarray Sum
LeetCode: 209
Link: https://leetcode.com/problems/minimum-size-subarray-sum/

Approach:
- Use the sliding window technique with two pointers.
- Expand the window by moving the right pointer and adding the current element to the running sum.
- Once the sum becomes greater than or equal to the target, shrink the window from the left while maintaining the condition.
- Update the minimum window length whenever a valid subarray is found.
- Return the minimum length of such a subarray, or `0` if no valid subarray exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int i = 0, j = 0;
            int mini = INT_MAX, sum = 0;
    
            while (j < nums.size()) {
                sum += nums[j];
    
                while (sum >= target) {
                    mini = min(mini, j - i + 1);
                    sum -= nums[i];
                    i++;
                }
    
                j++;
            }
    
            if (mini == INT_MAX)
                return 0;
    
            return mini;
        }
    };