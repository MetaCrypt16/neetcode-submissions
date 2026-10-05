#include <bits/stdc++.h>
class Solution {
public:
    int dp[1005];
    int rec(int level, vector<int>& nums){
        if(dp[level]!=-1)
        return dp[level];

        int ans = 1;
        for(int prev_taken = 0; prev_taken<level; prev_taken++){
            if(nums[prev_taken] < nums[level]){
                ans = max(ans, 1+rec(prev_taken,nums));
            }
        }
        return dp[level]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int best = 0;
        for(int i=0;i<nums.size();i++){
            best = max(best,rec(i,nums));
        }
        return best;
    }
};
