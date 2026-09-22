/*
Problem: Contains Duplicate II
LeetCode: 219
Link: https://leetcode.com/problems/contains-duplicate-ii/

Approach:
- Use a sliding window with two pointers `i` and `j`.
- Maintain an `unordered_set` containing the elements currently inside the window.
- Traverse the array using pointer `j`.
- If `nums[j]` is already present in the set, a duplicate exists within distance `k`, so return true.
- Insert `nums[j]` into the set.
- If the window size becomes greater than `k`, remove `nums[i]` and move `i` forward.
- If no valid duplicate is found, return false.

Time Complexity: O(n) average
Space Complexity: O(k)
*/

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int i=0,j=0;
            unordered_set<int>s;
            while(j<nums.size()){
               if(s.find(nums[j])!=s.end()){
                return true;    
               }
               s.insert(nums[j]);
               if(j-i+1>k){
                s.erase(nums[i]);
                i++;
               }
               j++;
            }
            return false;
        }
    };

