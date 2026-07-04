/*
Problem: Find Lucky Integer in an Array
LeetCode: 1394
Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/

Approach:
- Use a hash map to count the frequency of each element in the array.
- Traverse the array and update the frequency of every element.
- Iterate through the hash map and collect all elements whose value is equal to its frequency.
- If any lucky integers exist, return the largest one.
- Otherwise, return `-1`.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int findLucky(vector<int>& arr) {
            unordered_map<int,int>mp;
            vector<int>ans;
            for(int i=0;i<arr.size();i++){
                mp[arr[i]]++;
            }
            for(auto it:mp){
                if(it.first==it.second){
                    ans.push_back(it.first);
                }
            }
            if(!ans.empty()){
                sort(ans.rbegin(),ans.rend());
                return ans[0];
            }else{
                return -1;
            }
        }
    };