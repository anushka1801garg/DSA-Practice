/*
Problem: Maximum Subarray Length With Frequency Constraint
LeetCode: 2958
Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

Approach:
- Use the sliding window technique with two pointers.
- Maintain a hash map to store the frequency of each element in the current window.
- Expand the window by moving the `end` pointer and increasing the frequency of the current element.
- If the frequency of the current element becomes greater than `k`, move the `start` pointer forward until the frequency becomes valid again.
- Update `ans` with the maximum length of the valid window.
- Return the maximum length found.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
            int ans = 0, start = -1;
            unordered_map<int, int> frequency;
            
            for (int end = 0; end < nums.size(); end++) {
                frequency[nums[end]]++;
                while (frequency[nums[end]] > k) {
                    start++;
                    frequency[nums[start]]--;
                }
                ans = max(ans, end - start);
            }
            
            return ans;
        }
    };