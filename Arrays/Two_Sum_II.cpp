/*
Problem: Two Sum II - Input Array Is Sorted
LeetCode: 167
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Approach:
- Since the array is sorted, use two pointers.
- Start one pointer from the beginning and the other from the end.
- If the current sum equals the target, return the 1-based indices.
- If the sum is smaller than the target, move the left pointer forward.
- If the sum is larger than the target, move the right pointer backward.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <vector>
using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int i = 0, j = numbers.size() - 1;
    
            while (i < j) {
                int sum = numbers[i] + numbers[j];
    
                if (sum == target) {
                    return {i + 1, j + 1};
                }
                else if (sum < target) {
                    i++;
                }
                else {
                    j--;
                }
            }
    
            return {};
        }
    };