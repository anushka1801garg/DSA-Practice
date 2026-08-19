/*
Problem: Cinema Seat Allocation
LeetCode: 1386
Link: https://leetcode.com/problems/cinema-seat-allocation/

Approach:
- Represent the relevant seats from 2 to 9 of each row using a bitmask.
- Create three bitmasks representing the three possible groups of four seats:
  - Left group: seats 2 to 5.
  - Middle group: seats 4 to 7.
  - Right group: seats 6 to 9.
- Store the reserved seats of each affected row in an `unordered_map`.
- Rows without any reserved seats can accommodate two families, so initially add `(n - occupied.size()) * 2`.
- For each row containing reserved seats, check whether at least one valid group of four seats is available.
- If a valid group exists, add one family to the answer.
- Return the total number of families that can be seated.

Time Complexity: O(r)
Space Complexity: O(r)

where `r` is the number of reserved seats.
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
            int left = 0b11110000;
            int middle = 0b11000011;
            int right = 0b00001111;
    
            unordered_map<int, int> occupied;
            for (const vector<int>& seat : reservedSeats) {
                if (seat[1] >= 2 && seat[1] <= 9) {
                    occupied[seat[0]] |= (1 << (seat[1] - 2));
                }
            }
    
            int ans = (n - occupied.size()) * 2;
            for (auto& [row, bitmask] : occupied) {
                if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
                    ((bitmask | right) == right)) {
                    ++ans;
                }
            }
            return ans;
        }
    };