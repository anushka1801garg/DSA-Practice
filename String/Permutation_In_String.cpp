/*
Problem: Permutation in String
LeetCode: 567
Link: https://leetcode.com/problems/permutation-in-string/

Approach:
- Store the frequency of each character in `s1` using a hash map.
- Use a sliding window of size equal to the length of `s1` over `s2`.
- As the window expands, decrease the frequency of matching characters and keep track of how many distinct characters still need to be matched.
- Once the window reaches the required size, check whether all character frequencies have been matched.
- Before sliding the window forward, restore the frequency of the outgoing character if it exists in the hash map.
- Return `true` if any window is a permutation of `s1`; otherwise, return `false`.

Time Complexity: O(n + m)
Space Complexity: O(k)
*/

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int k=s1.length();
            unordered_map<char,int>mp;
            for(int i=0;i<s1.length();i++){
                mp[s1[i]]++;
            }
            int i=0,j=0;
            int count=mp.size();
            while(j<s2.length()){
                if(mp.find(s2[j])!=mp.end()){
                    mp[s2[j]]--;
                    if(mp[s2[j]]==0){
                        count--;
                    }
                }
                if(j-i+1<k){
                    j++;
                }
                else if(j-i+1==k){
                    if(count==0) return true;
                    else{
                        if(mp.find(s2[i]) != mp.end()){
    
                        if(mp[s2[i]] == 0)
                            count++;
    
                        mp[s2[i]]++;
                    }
                        i++;
                        j++;
                    }
                }
            }
            return false;
        }
    };