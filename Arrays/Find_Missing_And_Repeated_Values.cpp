/*
Problem: Find Missing and Repeated Values
LeetCode: 2965
Link: https://leetcode.com/problems/find-missing-and-repeated-values/

Approach:
- Use a hash map to count the frequency of each value in the grid.
- Traverse the grid and update the frequency of every element.
- Iterate through the hash map to find the element that appears twice.
- Traverse the numbers from `1` to `n²` and identify the number that is not present in the hash map.
- Return a vector containing the repeated value followed by the missing value.

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int>ans;
            unordered_map<int,int>mp;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid.size();j++){
                    mp[grid[i][j]]++;
                }
            }
            for(auto it:mp){
                if(it.second==2){
                    ans.push_back(it.first);
                }
            }
            for(int i=1;i<=grid.size()*grid.size();i++){
                if(!mp.count(i)){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };