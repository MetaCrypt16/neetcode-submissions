#include <cstring>
class Solution {
public:
    int dp[105]; //represents the min cost to reach this level
    int rec(int level, vector<int>& cost){
        int n= cost.size();
        if(level>=n){
            return 0;
        }
        if(dp[level]!=-1)
        return dp[level];

        int ans = 1e9;  //since min so store the largest number
        for(int i=1;i<=2;i++){
            ans = min(ans, cost[level]+rec(level+i, cost));
        }
        return dp[level] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(rec(0,cost),rec(1,cost));
    }
};