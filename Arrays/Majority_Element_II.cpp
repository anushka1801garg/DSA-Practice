/*
Problem: Majority Element II
LeetCode: 229
Link: https://leetcode.com/problems/majority-element-ii/

Approach:
- Use a hash map to count the frequency of each element in the array.
- Traverse the array and update the frequency of every element.
- Iterate through the hash map and collect all elements whose frequency is greater than ⌊n/3⌋.
- Return the list of all such majority elements.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            unordered_map<int,int>mp;
            vector<int>ans;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            for(auto it:mp){
                if(it.second>floor(nums.size()/3)){
                    ans.push_back(it.first);
                }
            }
            return ans;
        }
    };