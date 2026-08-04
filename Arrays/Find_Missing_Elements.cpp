/*
Problem: Find Missing Elements
LeetCode: Weekly Contest Problem

Approach:
- Store all elements of the array in a hash set for fast lookups.
- Traverse the array to determine the minimum and maximum values.
- Iterate through all numbers in the range from the minimum to the maximum value.
- For each number, check whether it exists in the hash set.
- If a number is not present, add it to the result.
- Return the list of all missing elements.

Time Complexity: O(n + (max - min))
Space Complexity: O(n)
*/

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        vector<int> findMissingElements(vector<int>& nums) {
            vector<int>ans;
            unordered_set<int>s(nums.begin(),nums.end());
            int maxi=INT_MIN,mini=INT_MAX;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }
            for(int i=0;i<nums.size();i++){
                mini=min(mini,nums[i]);
            }
            for(int i=mini;i<=maxi;i++){
                if(s.find(i)==s.end()){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };