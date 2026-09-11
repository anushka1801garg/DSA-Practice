/*
Problem: Form Smallest Number From Two Digit Arrays
LeetCode: 3270
Link: https://leetcode.com/problems/find-the-key-of-the-numbers/

Approach:
- Use three nested loops to select three different positions from the `digits` array.
- The first digit cannot be `0`, because the number must be a three-digit number.
- The last digit must be even, so check `digits[k] % 2 == 0`.
- Ensure that the same array index is not used more than once.
- Construct the three-digit number using:
  `digits[i] * 100 + digits[j] * 10 + digits[k]`.
- Use a boolean array `vis` to avoid counting duplicate numbers formed using repeated digits.
- Increment `ans` whenever a new three-digit even number is found.

Time Complexity: O(n³)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution {
    public:
        int totalNumbers(vector<int>& digits) {
            int n = digits.size();
            bool vis[1000]{};
            int ans = 0;
    
            for (int i = 0; i < n; ++i) {
                if (digits[i] == 0) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (j == i) {
                        continue;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j || digits[k] % 2 != 0) {
                            continue;
                        }
                        int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (!vis[x]) {
                            vis[x] = true;
                            ++ans;
                        }
                    }
                }
            }
    
            return ans;
        }
    };