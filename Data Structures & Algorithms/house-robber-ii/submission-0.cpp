#include <cstring>
class Solution {
public:
    int dp[105];
    int rec(int level,int end,vector<int>& nums){
        if(level > end)
        return 0;
        if(dp[level]!=-1)
        return dp[level];

        int ans = -1e9;
        //Case 1: ignore the house
        ans = max(ans,rec(level+1,end,nums));

        //Case 2: Rob the current house so need to skip the consecutive house
        ans = max(ans,nums[level]+rec(level+2,end,nums));

        return dp[level]=ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];

        //Scenario 1 skip the last house means end till n-2
        memset(dp,-1,sizeof(dp));
        int case1 = rec(0,n-2,nums);
        //Scenario 2 skip the first house means end till n-1
        memset(dp,-1,sizeof(dp));
        int case2 = rec(1,n-1,nums);
        return max(case1,case2);

    }
};
