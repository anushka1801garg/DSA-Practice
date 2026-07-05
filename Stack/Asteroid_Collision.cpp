/*
Problem: Asteroid Collision
LeetCode: 735
Link: https://leetcode.com/problems/asteroid-collision/

Approach:
- Use a stack to keep track of the asteroids that remain after collisions.
- Traverse each asteroid in the array.
- A collision occurs only when the top of the stack is moving right and the current asteroid is moving left.
- Compare the sizes of the colliding asteroids:
  - If the current asteroid is larger, remove the top asteroid and continue checking.
  - If both are the same size, remove the top asteroid and discard the current one.
  - If the top asteroid is larger, discard the current asteroid.
- If the current asteroid survives all possible collisions, push it onto the stack.
- After processing all asteroids, the stack contains the final state of the remaining asteroids.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<stack>
using namespace std;

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> st;
    
            for (int a : asteroids) {
                bool destroyed = false;
    
                while (!st.empty() && st.top() > 0 && a < 0) {
                    if (st.top() < -a) {
                        st.pop();          
                    }
                    else if (st.top() == -a) {
                        st.pop();          
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true;  
                        break;
                    }
                }
    
                if (!destroyed) {
                    st.push(a);
                }
            }
    
            vector<int> res;
            while (!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };
    