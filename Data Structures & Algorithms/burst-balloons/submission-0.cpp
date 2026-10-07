#include <bits/stdc++.h>
class Solution {
public:
    int dp[305][305]; //represents the maximum coins a person get from bursting baloon in the range open bracket i to j
    int rec(int l, int r, vector<int>& A){
        if(l+1 >= r) //no balloon in between to burst
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int max_value = 0;
        for(int mid = l+1;mid<r;mid++){
            max_value = max(max_value,rec(l,mid,A)+rec(mid,r,A)+A[l]*A[mid]*A[r]);
        }
        return dp[l][r]=max_value;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        vector<int>A(n+2,1); //append 2 more with value as 1 so that out of bonds is also managed
        for(int i=0;i<n;i++){
            A[i+1]=nums[i];
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,n+1,A);
    }
};
