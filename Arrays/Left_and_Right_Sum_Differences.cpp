/*
Problem: Left and Right Sum Differences
LeetCode: 2574
Link: https://leetcode.com/problems/left-and-right-sum-differences/

Approach:
For each index:
- Calculate sum of elements on the left side.
- Calculate sum of elements on the right side.
- Store both sums in separate arrays.
- Compute absolute difference between left and right sums.

Time Complexity: O(n²)
Space Complexity: O(n)
*/

#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> leftRightDifference(vector<int>& nums) {
            vector<int> ans1, ans2, final;
    
            for(int i = 0; i < nums.size(); i++) {
    
                int leftsum = 0;
                int rightsum = 0;
    
                for(int j = 0; j < i; j++) {
                    leftsum += nums[j];
                }
    
                ans1.push_back(leftsum);
    
                for(int j = i + 1; j < nums.size(); j++) {
                    rightsum += nums[j];
                }
    
                ans2.push_back(rightsum);
            }
    
            for(int i = 0; i < nums.size(); i++) {
                final.push_back(abs(ans1[i] - ans2[i]));
            }
    
            return final;
        }
    };