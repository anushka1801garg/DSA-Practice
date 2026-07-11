/*
Problem: Merge Sorted Array
LeetCode: 88
Link: https://leetcode.com/problems/merge-sorted-array/

Approach:
- Use two pointers to traverse the valid elements of both sorted arrays.
- Compare the current elements and append the smaller one to a temporary array.
- If both elements are equal, append one of them and move both pointers forward.
- After one array is exhausted, append the remaining elements from the other array.
- The temporary array contains the merged sorted sequence.

Time Complexity: O(m + n)
Space Complexity: O(m + n)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i=0,j=0;
            vector<int>ans;
            while(i<m && j<n){
                if(nums1[i]<nums2[j]){
                    ans.push_back(nums1[i]);
                    i++;
                }else if(nums1[i]>nums2[j]){
                    ans.push_back(nums2[j]);
                    j++;
                }else{
                    ans.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
            while(i<m){
                ans.push_back(nums1[i]);
                i++;
            }
            while(j<n){
                ans.push_back(nums2[j]);
                j++;
            }
            for(int i=0;i<ans.size();i++){
                cout<<ans[i];
            }
        }
    };