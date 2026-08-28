/*
Problem: Palindromic Binary Representation of String
LeetCode: Weekly Contest Problem

Approach:
- Convert each character of the string into its ASCII integer value.
- Convert each ASCII value into an 8-bit binary string using `tobinary()`.
- Append the binary representation of every character to form one complete binary string.
- Use two pointers, `i` and `j`, starting from both ends of the binary string.
- Compare the characters at both pointers.
- If any pair of characters is different, return `false`.
- If all characters match while moving toward the center, return `true`.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<string>
using namespace std;

string tobinary(int temp) {
    string bin = "";

    while(temp != 0) {
        bin = char((temp % 2) + '0') + bin;
        temp /= 2;
    }

    // Add leading zeroes until it becomes 8 bits
    while(bin.length() < 8) {
        bin = '0' + bin;
    }

    return bin;
}

class Solution {
public:
    bool isPalindromic(string s) {

        string ans = "";

        for(auto it : s) {
            int temp = (int)it;
            ans += tobinary(temp);
        }

        int i = 0;
        int j = ans.size() - 1;

        while(i < j) {
            if(ans[i] != ans[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};