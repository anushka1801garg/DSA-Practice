/*
Problem: Evaluate Reverse Polish Notation
LeetCode: 150
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

Approach:
- Use a stack to evaluate the Reverse Polish Notation (RPN) expression.
- Traverse each token in the input.
- If the token is a number, convert it to an integer and push it onto the stack.
- If the token is an operator (`+`, `-`, `*`, `/`):
  - Pop the top two operands from the stack.
  - Perform the corresponding operation in the correct order.
  - Push the result back onto the stack.
- After processing all tokens, the top of the stack contains the final result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<Stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int>st;
            for(int i=0;i<tokens.size();i++){
                if(tokens[i]=="+"){
                    int top=st.top();
                    st.pop();
                    int newtop=st.top();
                    st.pop();
                    int ans=top+newtop;
                    st.push(ans);
                }
                else if(tokens[i]=="-"){
                    int top=st.top();
                    st.pop();
                    int newtop=st.top();
                    st.pop();
                    int ans=newtop-top;
                    st.push(ans);
                }
                else if(tokens[i]=="/"){
                    int top=st.top();
                    st.pop();
                    int newtop=st.top();
                    st.pop();
                    int ans=newtop/top;
                    st.push(ans);
                }
                else if(tokens[i]=="*"){
                    int top=st.top();
                    st.pop();
                    int newtop=st.top();
                    st.pop();
                    int ans=top*newtop;
                    st.push(ans);
                }
                else{
                    st.push(stoi(tokens[i]));
                }
            }
            return st.top();
        }
    };