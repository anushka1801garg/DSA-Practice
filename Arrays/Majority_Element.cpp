/*
Problem: Majority Element
LeetCode: 169
Link: https://leetcode.com/problems/majority-element/

Approach:
Use an unordered map to count the frequency
of each element in the array.
Traverse the map and return the element
whose frequency is greater than n/2.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int,int>mp;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            for(auto it:mp){
                if(it.second>floor(nums.size()/2)){
                    return it.first;
                }
            }
            return 0;
        }
    };