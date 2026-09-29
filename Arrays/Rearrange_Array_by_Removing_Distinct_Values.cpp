/*
Problem: Rearrange Array Elements by Sign
LeetCode: 2149
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

Approach:
- Sort the array to group equal elements together.
- Use a `map` to store the frequency of each element.
- Traverse the array size times.
- In each iteration, traverse the map and take every element whose frequency is not zero.
- Add the selected element to `ans` and decrease its frequency.
- Continue until all elements are added to the result.

Time Complexity: O(n²)
Space Complexity: O(n)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int>ans;
            sort(nums.begin(),nums.end());
            map<int,int>mp;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            for(int i=0;i<nums.size();i++){
                for(auto &it:mp){
                    if(it.second!=0){
                        ans.push_back(it.first);
                        it.second--;
                    }else continue;
                }
            }
            return ans;   
        }
    };