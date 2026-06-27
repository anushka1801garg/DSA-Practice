/*
Problem: 3Sum
LeetCode: 15
Link: https://leetcode.com/problems/3sum/

Approach:
- Sort the array to enable the two-pointer technique.
- Iterate through each element and treat it as the first element of the triplet.
- Use two pointers to find the remaining two elements whose sum equals the negative of the current element.
- Skip duplicate elements for the first element as well as the two pointers to avoid duplicate triplets.
- Store every unique triplet whose sum is 0.

Time Complexity: O(n²)
Space Complexity: O(1) (excluding the output array)
*/

#include<bits.stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
    
            for (int i = 0; i < nums.size() - 2; i++) {
    
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;
    
                int j = i + 1;
                int k = nums.size() - 1;
    
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
    
                    if (sum == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
    
                        j++;
                        k--;
    
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                    else if (sum < 0) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
            }
    
            return ans;
        }
    };