/*
Problem: Gas Station
LeetCode: 134
Link: https://leetcode.com/problems/gas-station/

Approach:
- Calculate the total amount of gas and total cost.
- If total gas is less than total cost, completing the circuit is impossible, so return -1.
- Use a greedy approach to find the starting station.
- Maintain `tank` to store the current remaining gas while traversing the stations.
- If `tank` becomes negative at any station, the current starting point cannot be valid.
- Set the next station (`i + 1`) as the new starting point and reset `tank` to 0.
- If the total gas is sufficient, the final `start` index is the valid starting station.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
            int totalgas = 0;
            int totalcost = 0;
    
            for(int i = 0; i < gas.size(); i++) {
                totalgas += gas[i];
                totalcost += cost[i];
            }
    
            if(totalgas < totalcost)
                return -1;
    
            int tank = 0;
            int start = 0;
    
            for(int i = 0; i < gas.size(); i++) {
    
                tank += gas[i] - cost[i];
    
                if(tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
    
            return start;
        }
    };