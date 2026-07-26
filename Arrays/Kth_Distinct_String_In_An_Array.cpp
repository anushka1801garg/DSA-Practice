/*
Problem: Kth Distinct String in an Array
LeetCode: 2053
Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/

Approach:
- Use a hash map to count the frequency of each string in the array.
- Traverse the array once to populate the frequency map.
- Traverse the array again in its original order.
- Count only the strings whose frequency is `1`.
- When the count reaches `k`, return the current string.
- If fewer than `k` distinct strings exist, return an empty string.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        string kthDistinct(vector<string>& arr, int k) {
            unordered_map<string,int>mp;
            for(auto i:arr){
                mp[i]++;
            }
            int count=0;
            for(auto i:arr){
                if(mp[i]==1){
                    count++;
                }
                if(count==k){
                    return i;
                }
            }
            return "\0";
        }
    };