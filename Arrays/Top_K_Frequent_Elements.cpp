/*
Problem: Top K Frequent Elements
LeetCode: 347
Link: https://leetcode.com/problems/top-k-frequent-elements/

Approach:
Use an unordered map to count the
frequency of each element.
Store frequency and element as pairs
in a vector.
Sort the vector in descending order
based on frequency.
Return the first k elements.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


#include<bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            vector<int>ans;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            vector<pair<int,int>>v;
            for(auto it:mp){
                v.push_back({it.second,it.first});
            }
            sort(v.rbegin(),v.rend());
            for(int i=0;i<k;i++){
                ans.push_back(v[i].second);
            }
            return ans;
        }
    };