/*
Problem: Valid Parentheses
LeetCode: 20
Link: https://leetcode.com/problems/valid-parentheses/

Approach:
- Use a stack to keep track of opening brackets.
- Traverse the string character by character.
- If the current character is an opening bracket, push it onto the stack.
- If it is a closing bracket, check whether the stack is empty or the top of the stack does not contain the corresponding opening bracket.
- If the brackets match, pop the opening bracket from the stack.
- After processing the entire string, the string is valid only if the stack is empty.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<stack>
#include<String>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char>st;
            for(int i=0;i<s.length();i++){
                if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                    st.push(s[i]);
                }
                else{
                    if(st.empty()){return false;}
    
                    if((s[i]==')' && st.top()=='(') || 
                    (s[i]=='}' && st.top()=='{') || 
                    (s[i]==']' && st.top()=='[')){
                        st.pop();
                    }
                    else{return false;}
                }
            }
            if(st.empty()){
                return true;
            }
            else{
                return false;
            }
        }
    };