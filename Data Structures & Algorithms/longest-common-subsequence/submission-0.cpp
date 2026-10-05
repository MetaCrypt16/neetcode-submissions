#include <bits/stdc++.h>
class Solution {
public:
    int dp[1005][1005];
    int rec(int i,int j,const string& text1, const string& text2){
        int n = text1.size();
        int m = text2.size();
        if(i>=n || j>=m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans =0;
        ans = max(ans,rec(i+1,j,text1,text2));
        ans = max(ans,rec(i,j+1,text1,text2));
        if(text1[i]==text2[j])
        ans = max(ans,1+rec(i+1,j+1,text1,text2));

        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,text1,text2);
    }
};
