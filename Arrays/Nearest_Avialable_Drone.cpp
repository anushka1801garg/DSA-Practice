/*
Problem: Nearest Drone
LeetCode: Weekly Contest Problem

Approach:
- Traverse all the drones one by one.
- Calculate the Manhattan distance between each drone's position and the target position.
- Check whether the calculated distance is within the drone's allowed range.
- If the drone can reach the target and its distance is smaller than the current minimum, update the minimum distance and store its index.
- Return the index of the nearest valid drone.
- If no drone can reach the target, return `-1`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
            int mini = INT_MAX;
            int ans = -1;
    
            for (int i = 0; i < drones.size(); i++) {
                int sum = 0;
    
                for (int j = 0; j < 2; j++) {
                    sum += abs(drones[i][j] - target[j]);
                }
    
                if (sum <= drones[i][2] && sum < mini) {
                    mini = sum;
                    ans = i;
                }
            }
    
            return ans;
        }
    };