/*
Problem: Trapping Rain Water
LeetCode: 42
Link: https://leetcode.com/problems/trapping-rain-water/

Approach:
- Use two pointers, one at the beginning and one at the end of the array.
- Maintain the maximum height seen so far from the left (`mxleft`) and the right (`mxright`).
- Compare the two maximum heights:
  - If `mxleft` is smaller, calculate the water trapped at the left pointer and move it forward.
  - Otherwise, calculate the water trapped at the right pointer and move it backward.
- Accumulate the trapped water until the two pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int l=0,r=height.size()-1;
            int mxleft=0,mxright=0,curr=0;
            while(l<r){
                mxleft=max(mxleft,height[l]);
                mxright=max(mxright,height[r]);
                if(mxleft<mxright){
                    curr+=(min(mxleft,mxright)-height[l]);
                    l++;
                }else{
                    curr+=(min(mxleft,mxright)-height[r]);
                    r--;
                }
            }
            return curr;
        }
    };