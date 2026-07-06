/*
Problem: Happy Number
LeetCode: 202
Link: https://leetcode.com/problems/happy-number/

Approach:
- Use a hash set to keep track of numbers encountered during the process.
- Repeatedly replace the current number with the sum of the squares of its digits.
- If the number becomes `1`, it is a happy number.
- If a number repeats, a cycle exists, so the number is not happy.
- Return `true` if `1` is reached; otherwise, return `false`.

Time Complexity: O(log n)
Space Complexity: O(log n)
*/

#include<unordered_set>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int>s;
            while(n!=1){
                if(s.count(n)){
                    return false;
                }
                else{
                    s.insert(n);
                    int temp=n;
                    int sum=0;
                    while(temp!=0){
                        int r=temp%10;
                        sum+=r*r;
                        temp/=10;
                    }
                    n=sum;
                }
            }
            return true;
        }
    };