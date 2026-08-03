/*
Problem: Maximum Pair Strength
LeetCode: Weekly Contest Problem

Approach:
- Iterate through all possible pairs of elements in the array.
- For each pair, compute their GCD.
- Calculate the pair strength using the formula:
  `(nums[i] * nums[j]) / (gcd(nums[i], nums[j])²)`.
- Keep track of the maximum pair strength encountered.
- Return the maximum value after checking all pairs.

Time Complexity: O(n² × log(max(nums)))
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        long long maxPairStrength(vector<int>& nums) {
            long long maxi = LLONG_MIN;
    
            for(int i = 0; i < nums.size(); i++) {
                for(int j = i + 1; j < nums.size(); j++) {
                    long long val = (1LL * nums[i] * nums[j]) / pow(gcd(nums[i], nums[j]),2);
                    maxi = max(maxi, val);
                }
            }
    
            return maxi;
        }
    };