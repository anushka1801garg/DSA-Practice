/*
Problem: Jump Game
LeetCode: 55
Link: https://leetcode.com/problems/jump-game/

Approach:
- Use a greedy approach to keep track of the farthest index that can be reached.
- Maintain `maxi`, which represents the maximum reachable index so far.
- Traverse the array from left to right.
- If the current index `i` is greater than `maxi`, it means this index cannot be reached, so return `false`.
- Otherwise, update `maxi` using `i + nums[i]` to find the farthest position reachable from the current index.
- If all indices can be reached during the traversal, return `true`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;


class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxi=0;
            for(int i=0;i<nums.size();i++){
                if(i>maxi) return false;
                maxi=max(maxi,i+nums[i]);
            }
            return true;
        }
    };