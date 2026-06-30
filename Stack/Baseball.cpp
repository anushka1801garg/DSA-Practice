/*
Problem: Baseball Game
LeetCode: 682
Link: https://leetcode.com/problems/baseball-game/

Approach:
- Use a stack to keep track of valid scores.
- Traverse each operation in the input list.
- If the operation is:
  - `"+"`, push the sum of the previous two valid scores.
  - `"D"`, push double the previous valid score.
  - `"C"`, remove the previous valid score.
  - Otherwise, convert the string to an integer and push it as a new score.
- After processing all operations, sum all the values remaining in the stack to obtain the final score.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<stack>
#include<String>
#include<vector>
using namespace std;

class Solution {
    public:
        int calPoints(vector<string>& operations) {
            stack<int>st;
            for(int i=0;i<operations.size();i++){
                if(operations[i]=="+"){
                    int top=st.top();
                    st.pop();
                    int newtop=st.top();
                    st.push(top);
                    int ans=top+newtop;
                    st.push(ans);
                }
                else if(operations[i]=="D"){
                    int top=st.top();
                    st.push(top*2);
                }
                else if(operations[i]=="C"){
                    st.pop();
                }
                else{
                    st.push(stoi(operations[i]));
                }
            }
            int ans = 0;
            while(st.size() != 0)
            {
                ans += st.top();
                st.pop();
            }
            return ans;
        }
    };