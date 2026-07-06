/*
Problem: Divide Array Into Equal Pairs
LeetCode: 2206
Link: https://leetcode.com/problems/divide-array-into-equal-pairs/

Approach:
- Use a hash map to count the frequency of each element in the array.
- Traverse the array and update the frequency of every element.
- Iterate through the hash map and check the frequency of each element.
- If any element has an odd frequency, it cannot be paired, so return `false`.
- If all frequencies are even, the array can be divided into equal pairs, so return `true`.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int,int>mp;
            int ans=nums.size()/2;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            int count=0;
            for(auto it:mp){
                if(it.second%2!=0){
                    return false;
                }
            }
            return true;
        }
    };