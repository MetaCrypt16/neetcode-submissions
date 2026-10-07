#include <bits/stdc++.h>
class Solution {
public:
    int dp[1005][1005];
    int rec(int i, int j, const string&s, const string& t){
        int n = s.length(), m = t.length();
        if(j==m)  //this should be checked first because if both reach the end simultaneously then 1 should be written
        return 1;
        if(i==n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans = rec(i+1,j,s,t);
        if(s[i]==t[j])
        ans += rec(i+1,j+1,s,t);

        return dp[i][j]=ans;
        
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t);
    }
};
