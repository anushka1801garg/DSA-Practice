/*
Problem: Minimum Value of Merged Integers
LeetCode: 4097
Link: https://leetcode.com/problems/minimum-value-of-merged-integers/

Approach:
- Initialize `ans` with INT_MAX to store the minimum merged integer.
- Traverse the array in pairs using `i += 2`.
- Convert both elements of each pair into strings.
- Concatenate the strings to form the merged integer.
- Convert the concatenated string back to an integer using `stoi()`.
- Update `ans` with the minimum value among all merged integers.
- Return `ans`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        int minMergedInteger(vector<int>& nums) {
            int ans=INT_MAX;
            for(int i=0;i<nums.size()-1;i+=2){
                string st=to_string(nums[i])+to_string(nums[i+1]);
                ans=min(ans,stoi(st));
            }
            return ans;
        }
    };