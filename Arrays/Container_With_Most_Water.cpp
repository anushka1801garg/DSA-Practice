/*
Problem: Container With Most Water
LeetCode: 11
Link: https://leetcode.com/problems/container-with-most-water/

Approach:
- Use two pointers, one at the beginning and one at the end of the array.
- Calculate the area formed by the two lines using the minimum height and the distance between them.
- Update the maximum area found so far.
- Move the pointer pointing to the shorter line inward, since moving the taller line cannot increase the area.
- Continue until the two pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n=height.size();
            int left=0,right=n-1,ans=0;
            while(left<right){
                int width=right-left;
                int h=min(height[left],height[right]);
                ans=max(ans,width*h);
                if(height[left]<height[right]) left++;
                else right--;
            }
            return ans;
        }
    };