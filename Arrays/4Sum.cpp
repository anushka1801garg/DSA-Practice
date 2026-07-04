/*
Problem: 4Sum
LeetCode: 18
Link: https://leetcode.com/problems/4sum/

Approach:
- Sort the array to enable the two-pointer technique.
- Fix the first two elements of the quadruplet using two nested loops.
- Use two pointers (`left` and `right`) to find the remaining two elements whose sum matches the target.
- Skip duplicate values for both fixed elements and the two pointers to avoid duplicate quadruplets.
- Use `long long` while calculating the sum to prevent integer overflow.
- Store every unique quadruplet whose sum equals the target.

Time Complexity: O(n³)
Space Complexity: O(1) (excluding the output array)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            vector<vector<int>>ans;
            for(int i=0;i<n-3;i++){
                if(i>0 && nums[i]==nums[i-1]) continue;
                for(int j=i+1;j<n-2;j++){
                    if(j>i+1  && nums[j]==nums[j-1]) continue;
                    int left=j+1,right=nums.size()-1;
                    while(left<right){
                        long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                        if(sum==target){
                            ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                            left++;
                            right--;
                            while(left<right && nums[left]==nums[left-1]) left++;
                            while(left<right && nums[right]==nums[right+1]) right--;
                        }
                        else if(sum<target) left++;
                        else right--;
                    }
                }
            }
            return ans;
        }
    };