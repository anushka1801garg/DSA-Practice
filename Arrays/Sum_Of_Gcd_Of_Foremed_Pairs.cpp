/*
Problem: GCD Pair Sum
LeetCode: Weekly Contest Problem

Approach:
- Traverse the array and build a prefix maximum array.
- For each index, compute the GCD of the current element and the corresponding prefix maximum.
- Store all the computed GCD values in a separate array.
- Sort the GCD array in non-decreasing order.
- Use two pointers, one at the beginning and one at the end of the sorted array.
- Compute the GCD of each pair formed by the two pointers and add it to the answer.
- Continue until the two pointers meet or cross.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        long long gcdSum(vector<int>& nums) {
            int n = nums.size();
    
            vector<int> mx;
            int prefixMax = INT_MIN;
    
            for (int x : nums) {
                prefixMax = max(prefixMax, x);
                mx.push_back(prefixMax);
            }
    
            vector<int> prefixGcd;
            for (int i = 0; i < n; ++i) {
                prefixGcd.push_back(gcd(nums[i], mx[i]));
            }
    
            ranges::sort(prefixGcd);
    
            long long ans = 0;
            int left = 0, right = n - 1;
            while (left < right) {
                ans += gcd(prefixGcd[left], prefixGcd[right]);
                ++left;
                --right;
            }
    
            return ans;
        }
    };