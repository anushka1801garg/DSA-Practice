/*
Problem: Uniform Parity Array II
LeetCode: 3876
Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/

Approach:
- Sort the array first.
- Count the number of even and odd elements.
- If all elements have the same parity, return true.
- Otherwise, find the minimum odd element.
- Keep odd elements unchanged.
- For every even element, subtract the minimum odd element.
- If the resulting value is less than 1, return false.
- If all elements satisfy the condition, return true.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool uniformArray(vector<int>& nums1) {
            sort(nums1.begin(),nums1.end());
            int min=INT_MAX;
            vector<int>ans;
            int count=0,count1=0;
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]%2==0) count++;
            }
            if(count==nums1.size()) return true;
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]%2!=0) count1++;
            }
            if(count1==nums1.size()) return true;
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]%2!=0){
                    ans.push_back(nums1[i]);
                    if(nums1[i]<min) min=nums1[i];
                }
                else{
                    if((nums1[i]-min)<1) return false;
                    else ans.push_back(nums1[i]-min);
                }
            }
            return true;
        }
    };