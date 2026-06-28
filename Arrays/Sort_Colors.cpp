/*
Problem: Sort Colors
LeetCode: 75
Link: https://leetcode.com/problems/sort-colors/

Approach:
- Use the Dutch National Flag algorithm with three pointers.
- Maintain:
  - `l` for the next position of 0.
  - `m` as the current element being processed.
  - `h` for the next position of 2.
- If the current element is 0, swap it with `l` and increment both `l` and `m`.
- If the current element is 2, swap it with `h` and decrement `h`.
- If the current element is 1, simply move `m` forward.
- Continue until `m` crosses `h`.

Time Complexity: O(n)
Space Complexity: O(1)
*/



#include <vector>
using namespace std;


class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int l=0;
            int m=0;
            int h=nums.size()-1;
    
            while(m<=h){
                if(nums[m]==0){
                    swap(nums[m],nums[l]);
                    m++;
                    l++;
                        
                    
                }
                else if(nums[m]==2){
                    swap(nums[m],nums[h]);
                    h--;
                }
                else m++;
            }
        }
    };