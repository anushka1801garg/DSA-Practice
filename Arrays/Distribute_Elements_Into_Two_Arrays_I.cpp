/*
Problem: Distribute Elements Into Two Arrays I
LeetCode: 3069
Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/

Approach:
- Create two separate arrays, `ans1` and `ans2`.
- Place the first element of `nums` in `ans1` and the second element in `ans2`.
- Starting from the third element, compare the last elements of both arrays.
- If the last element of `ans1` is greater than the last element of `ans2`, add the current element to `ans1`.
- Otherwise, add the current element to `ans2`.
- After processing all elements, append all elements of `ans2` to `ans1`.
- Return `ans1` as the final result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> resultArray(vector<int>& nums) {
            vector<int>ans1,ans2;
            int m=0,n=0;
            ans1.push_back(nums[0]);
            if(nums.size()>1){
                ans2.push_back(nums[1]);
                for(int i=2;i<nums.size();i++){
                    if(ans1[m]>ans2[n]){
                        ans1.push_back(nums[i]);
                        m++;
                    }else{
                        ans2.push_back(nums[i]);
                        n++;
                    }
                }
            }
            for(int i=0;i<ans2.size();i++){
                ans1.push_back(ans2[i]);
            }
            return ans1;
        }
    };