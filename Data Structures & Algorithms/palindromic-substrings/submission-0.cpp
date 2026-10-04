#include <bits/stdc++.h>
class Solution {
public:
     int dp[1005][1005];
     int rec(int l, int r, const string& s){
        if(l>=r)
        return 1;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int ans = 0;
        if(s[l]==s[r] && rec(l+1,r-1,s))
        ans = 1;

        return dp[l][r]=ans;
     }
    int countSubstrings(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(rec(i,j,s))
                count++;        
            }
        }
        return count;
    }
};
