/*
Problem: Assign Cookies
LeetCode: 455
Link: https://leetcode.com/problems/assign-cookies/

Approach:
- Sort both the greed factors `g` and cookie sizes `s` in ascending order.
- Use two pointers:
  - `i` points to the current child.
  - `j` points to the current cookie.
- If the current cookie is large enough to satisfy the current child, assign it:
  - Increment the satisfied children count.
  - Move both pointers forward.
- If the cookie is too small, move `j` forward to try a larger cookie.
- Continue until either all children or all cookies have been processed.
- Return the total number of satisfied children.

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) excluding sorting space.
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int i=0;
            int j=0;
            int count=0;
            while(i<g.size()&& j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    i++;
                    j++;
                }else{
                    j++;
                }
            }
            return count;
        }
    };