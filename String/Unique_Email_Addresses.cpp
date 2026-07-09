/*
Problem: Unique Email Addresses
LeetCode: 929
Link: https://leetcode.com/problems/unique-email-addresses/

Approach:
- Use a hash set to store the normalized email addresses.
- For each email:
  - Split it into the local name and the domain name.
  - Ignore everything after the first `'+'` in the local name.
  - Remove all `'.'` characters from the local name.
  - Combine the processed local name with the original domain name.
- Insert the normalized email into the hash set.
- Return the number of unique normalized email addresses.

Time Complexity: O(n × m)
Space Complexity: O(n × m)
*/

#include<vector>
#include<String>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            unordered_set<string>s;
            for(auto i:emails){
                int at=i.find('@');
                string local=i.substr(0,at);
                string domain=i.substr(at+1,i.size()-1);
                int plus=local.find('+');
                local=local.substr(0,plus);
                local.erase(remove(local.begin(), local.end(), '.'), local.end());
                string clean_email = local + "@" + domain;
                s.insert(clean_email);
            }
            return s.size();
        }
    };