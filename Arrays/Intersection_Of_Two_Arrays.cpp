/*
Problem: Intersection of Two Arrays
LeetCode: 349
Link: https://leetcode.com/problems/intersection-of-two-arrays/

Approach:
- Use two hash maps to store the unique elements (or frequencies) of both arrays.
- Traverse the first array and insert its elements into the first hash map.
- Traverse the second array and insert its elements into the second hash map.
- Iterate through the first hash map and check whether each element exists in the second hash map.
- If an element is present in both maps, add it to the result.
- Return the list of common unique elements.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_map<int,int>mp,mp1;
            vector<int>result;
            for(int i=0;i<nums1.size();i++){
                mp[nums1[i]]++;
            }
            for(int i=0;i<nums2.size();i++){
                mp1[nums2[i]]++;
            }
            for(auto it : mp){
                if(mp1.count(it.first)){
                    result.push_back(it.first);
                }
            }
            return result; 
        }
    };