/*
Problem: Intersection of Two Arrays II
LeetCode: 350
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

Approach:
- Use two hash maps to count the frequency of elements in both arrays.
- Traverse each array and update the corresponding frequency map.
- Iterate through the first hash map.
- For every element present in both maps, determine the minimum of the two frequencies.
- Add the element to the result as many times as the common frequency.
- Return the resulting intersection array.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
                    int commonFreq = min(it.second, mp1[it.first]);
                    for(int i = 0; i < commonFreq; i++){
                        result.push_back(it.first);
                    }
                }
            }
            return result;
        }
    };