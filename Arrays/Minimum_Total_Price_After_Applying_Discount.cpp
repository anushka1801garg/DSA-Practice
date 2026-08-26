/*
Problem: Minimum Price With Discounts
LeetCode: Weekly Contest Problem

Approach:
- Sort both `prices` and `discounts` in descending order.
- Match the largest discounts with the highest-priced items to maximize the total discount.
- If there are enough discounts for all products, apply one discount to each price.
- If there are fewer discounts than products:
  - Apply the available discounts to the most expensive products.
  - Add the remaining product prices without any discount.
- Calculate each discounted price using:
  `price * (100 - discount) / 100`.
- Return the total minimum price.

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) excluding the sorting space.
*/

#include<vector>
using namespace std;

class Solution {
    public:
        double minPrice(vector<int>& prices, vector<int>& discounts) {
            sort(prices.rbegin(),prices.rend());
            sort(discounts.rbegin(),discounts.rend());
            double sum=0;
            if(prices.size()<=discounts.size()){
                for(int i=0;i<prices.size();i++){
                double discount=(prices[i]*(100.0-discounts[i]))/100.0;
                sum+=discount;
                }
                return sum;
            }else{
                for(int i=0;i<discounts.size();i++){
                    double discount=(prices[i]*(100.0-discounts[i]))/100.0;
                    sum+=discount;
                }
                for(int i=discounts.size();i<prices.size();i++){
                    sum+=prices[i];
                }
                return sum;
            }
        }
    };