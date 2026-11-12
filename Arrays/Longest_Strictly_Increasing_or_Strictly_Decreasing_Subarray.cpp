/*
Problem: Longest Strictly Increasing or Strictly Decreasing Subarray
LeetCode: 3105
Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

Approach:
- Maintain two counters:
  - `count` for the length of the strictly increasing subarray.
  - `count1` for the length of the strictly decreasing subarray.
- Initialize both counters and `ans` to 1.
- Traverse the array from the second element.
- If the current element is greater than the previous element:
  - Increment `count`.
  - Reset `count1` to 1.
- If the current element is smaller than the previous element:
  - Increment `count1`.
  - Reset `count` to 1.
- If both elements are equal, reset both counters to 1.
- Update `ans` with the maximum of the two counters.
- Return `ans`.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include<vector>
using namespace std;

class Solution {
    public:
        int longestMonotonicSubarray(vector<int>& nums) {
            int count = 1, count1 = 1;
            int ans = 1;
    
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] > nums[i-1]) {
                    count++;
                    count1 = 1;
                }
                else if(nums[i] < nums[i-1]) {
                    count1++;
                    count = 1;
                }
                else {
                    count = 1;
                    count1 = 1;
                }
    
                ans = max(ans, max(count, count1));
            }
    
            return ans;
        }
    };