/*
Problem: Missing Number
LeetCode: 268
Link: https://leetcode.com/problems/missing-number/

Approach:
- Store all elements of the array in a hash set for O(1) lookups.
- Traverse the numbers from `0` to `n`, where `n` is the size of the array.
- Check whether each number exists in the hash set.
- Return the first number that is not present in the set.
- If all numbers are present, return `-1` (though this case does not occur under the given constraints).

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> s(nums.begin(), nums.end());
    
            for(int i = 0; i <= n; i++){
                if(s.count(i) == 0){
                    return i;
                }
            }
            return -1;
        }
    };