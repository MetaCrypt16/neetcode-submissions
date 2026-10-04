#include <cstring>
class Solution {
public:
    int dp[105]; //represents the max amount he can rob till ith house
    int rec(int level, vector<int>& nums){
        int n= nums.size();
        if(level>=n){
            return 0;
        }
        if(dp[level]!=-1)
        return dp[level];
        int ans = -1e9;
        //Case 1: Ignore the current house
        ans = max(ans,rec(level+1,nums));

        //case 2: Rob the current house means cannot go to the adjacent house
        ans = max(ans,nums[level]+rec(level+2,nums));

        return dp[level]=ans;
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
    }
};
