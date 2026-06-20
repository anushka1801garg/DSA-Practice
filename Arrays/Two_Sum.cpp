/*
Problem: Two Sum
Platform: LeetCode
Difficulty: Easy

Approach:
Use a hashmap to store previously seen numbers.
For each element, check if (target - current element)
already exists.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++) {

            int rem = target - nums[i];

            if(mp.count(rem))
                return {mp[rem], i};

            mp[nums[i]] = i;
        }

        return {};
    }
};