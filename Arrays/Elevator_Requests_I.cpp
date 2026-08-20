/*
Problem: Elevator Requests
LeetCode: Weekly Contest Problem

Approach:
- Start by adding the distance from the ground floor to the first requested floor.
- Traverse the remaining requests one by one.
- For each request, calculate the absolute difference between the current floor and the previous requested floor.
- Add this distance to the total number of floors travelled.
- Return the total distance travelled by the elevator.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int elevatorRequests(int n, vector<int>& requests) {
            int sum=0;
            sum+=requests[0];
            for(int i=1;i<requests.size();i++){
                sum+=abs(requests[i]-requests[i-1]);
            }
            return sum;
        }
    };