#include <bits/stdc++.h>
class Solution {
public:
    int dp[105][105];
    int rec(int r, int c){
        if(r < 0 || c< 0)
        return 0;
        if (r == 0 && c == 0) return 1;

        if(dp[r][c]!=-1)
        return dp[r][c];
         
        int ans = 0;
        if(r!=0)
        ans += rec(r-1,c);
        if(c!=0)
        ans+= rec(r,c-1);

        return dp[r][c]=ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(m-1,n-1);
    }
};
