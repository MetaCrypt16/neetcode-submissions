#include <cstring>
#include <string>
class Solution {
public:
    long long dp[105];
    int rec(int level, const string& s){
         int n= s.length();
         if(level==n){
            return 1;
         }
         if(s[level]=='0')
         return 0;

        if(dp[level]!=-1)
        return dp[level];

        long long ans = 0;
        ans += rec(level+1,s);
        if(level+1 < n){
            int double_digit = (s[level]-'0')*10 + (s[level+1]-'0');
            if(double_digit >= 10 && double_digit <= 26)
            ans += rec(level+2,s);
        }
        return dp[level]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(0,s);
    }
};
