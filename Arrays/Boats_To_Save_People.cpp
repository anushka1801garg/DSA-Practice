/*
Problem: Boats to Save People
LeetCode: 881
Link: https://leetcode.com/problems/boats-to-save-people/

Approach:
- Sort the array of people's weights.
- Use two pointers:
  - One at the lightest person.
  - One at the heaviest person.
- If the lightest and heaviest person can share a boat without exceeding the weight limit, move both pointers inward.
- Otherwise, assign a boat to the heaviest person alone and move the right pointer.
- Count each boat used during the process.
- If one person remains after the loop, allocate one additional boat.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


#include<vector>
using namespace std;

class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(),people.end());
            int i=0,j=people.size()-1;
            int count=0;
            while(i<j){
                int sum=people[i]+people[j];
                if(sum<=limit){
                    i++;
                    j--;
                    count++;
                }else if(sum>limit){
                    j--;
                    count++;
                }else{
                    i++;
                    count++;
                }
            }
            if(i==j) return count+1;
            else return count;
        }
    };