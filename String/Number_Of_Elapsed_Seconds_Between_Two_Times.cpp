/*
Problem: Seconds Between Two Times
LeetCode: Weekly Contest Problem

Approach:
- Extract the hours, minutes, and seconds from both time strings using `substr()`.
- Convert each extracted part to an integer using `stoi()`.
- Convert both times into total seconds from midnight.
- Return the difference between the end time and the start time.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include<string>
using namespace std;

class Solution {
    public:
        int secondsBetweenTimes(string startTime, string endTime) {
            int sthour=stoi(startTime.substr(0,2));
            int stminute=stoi(startTime.substr(3,2));
            int stseconds=stoi(startTime.substr(6,2));
            int st=sthour*3600+stminute*60+stseconds;
    
            int enhour=stoi(endTime.substr(0,2));
            int enminute=stoi(endTime.substr(3,2));
            int enseconds=stoi(endTime.substr(6,2));
            int en=enhour*3600+enminute*60+enseconds;
    
            return en-st;
        }
    };