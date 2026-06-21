/*
Problem: Best Time to Buy and Sell Stock
LeetCode: 121

Approach:
Track minimum price seen so far.
At every step calculate current profit
and update maximum profit.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int mini = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            profit = max(profit, prices[i] - mini);

            mini = min(mini, prices[i]);
        }

        return profit;
    }
};