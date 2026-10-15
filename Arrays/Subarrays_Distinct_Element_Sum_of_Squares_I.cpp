/*
Problem: Sum of Counts of Subarrays
LeetCode: 2913
Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

Approach:
- Traverse the array using index `i` to select the starting point of each subarray.
- For each starting point, create an `unordered_set` to store distinct elements.
- Use a nested loop with index `j` to extend the subarray.
- Insert `nums[j]` into the set to maintain the distinct elements.
- Calculate the square of the set size and add it to `res` for every subarray.
- Return `res` after considering all possible subarrays.

Time Complexity: O(n²) average
Space Complexity: O(n)
*/


#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        int sumCounts(vector<int>& nums) {
            int n = nums.size(), res = 0;
            for (int i = 0; i < n; i++) {
                unordered_set<int> s;
                for (int j = i; j < n; j++) {
                    s.insert(nums[j]);
                    res += s.size() * s.size();
                }
            }
            return res;
        }
    };