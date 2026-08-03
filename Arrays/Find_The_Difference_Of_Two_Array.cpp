/*
Problem: Find the Difference of Two Arrays
LeetCode: 2215
Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/

Approach:
- Create a helper function to find the unique elements present in the first array but not in the second.
- Traverse each element of the first array and check whether it exists in the second array.
- If an element is not found, insert it into a hash set to avoid duplicates.
- Convert the hash set into a vector and return it.
- Call the helper function twice:
  - Once to find elements unique to `nums1`.
  - Once to find elements unique to `nums2`.
- Return both result vectors.

Time Complexity: O(n × m)
Space Complexity: O(n + m)
*/

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> onlyInNums1;
            
            for (int num : nums1) {
                bool existInNums2 = false;
                for (int x : nums2) {
                    if (x == num) {
                        existInNums2 = true;
                        break;
                    }
                }
                
                if (!existInNums2) {
                    onlyInNums1.insert(num);
                }
            }
            return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
        }
        
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
        }
    };