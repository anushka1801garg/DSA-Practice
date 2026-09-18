#include<vector>
#include<set>
using namespace std;

class Solution {
    public:
        vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
    
            set<int> temp(nums.begin(), nums.end());
    
            vector<vector<int>> ans;
    
            int start = -1;
    
            for(int i = lower; i <= upper; i++) {
    
                if(temp.find(i) == temp.end()) {
    
                    // Start a new missing range
                    if(start == -1) {
                        start = i;
                    }
                }
                else {
    
                    // A missing range has ended
                    if(start != -1) {
                        ans.push_back({start, i - 1});
                        start = -1;
                    }
                }
            }
    
            // If a missing range continues until upper
            if(start != -1) {
                ans.push_back({start, upper});
            }
    
            return ans;
        }
    };