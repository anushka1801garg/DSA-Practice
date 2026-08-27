/*
Problem: Count Primes
LeetCode: 204
Link: https://leetcode.com/problems/count-primes/

Approach:
- Use a helper function `isprime()` to check whether a number is prime.
- A number is considered prime if it is greater than 1 and has no divisor other than 1 and itself.
- In `isprime()`, check all numbers from `2` to `n - 1`.
- If any number divides `n`, then `n` is not prime.
- In `countPrimes()`, iterate through all numbers from `2` to `n - 1`.
- For every prime number, increment the count.
- Return the total number of prime numbers less than `n`.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int i=0;
            int j=0;
            int count=0;
            while(i<g.size()&& j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    i++;
                    j++;
                }else{
                    j++;
                }
            }
            return count;
        }
    };