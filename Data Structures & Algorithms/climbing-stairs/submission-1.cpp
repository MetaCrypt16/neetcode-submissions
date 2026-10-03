#include <cstring>

class Solution {
public:
    int dp[50];
    int rec(int level,int n){
        if(level==n){
            return 1;
        }
        if(dp[level]!=-1)
        return dp[level];
        int ans = 0;
        for(int i=1;i<=2;i++){
            if(level+i <=n)
            ans += rec(level+i, n);
        }
        return dp[level]=ans;
    }
    int climbStairs(int n) {
       memset(dp,-1,sizeof(dp));
       return rec(0,n);
    }
};
