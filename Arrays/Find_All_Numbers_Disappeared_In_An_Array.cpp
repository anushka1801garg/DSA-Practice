/*
Problem: Find All Numbers Disappeared in an Array
LeetCode: 448
Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Approach:
- Store all elements of the array in a hash set for fast lookup.
- Traverse the numbers from `1` to `n`, where `n` is the size of the array.
- For each number, check whether it exists in the hash set.
- If a number is not present, add it to the result.
- Return the list of all missing numbers.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int n=nums.size();
            vector<int>ans;
            unordered_set<int>s(nums.begin(),nums.end());
            for(int i=1;i<=n;i++){
                if(s.count(i)==0){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };