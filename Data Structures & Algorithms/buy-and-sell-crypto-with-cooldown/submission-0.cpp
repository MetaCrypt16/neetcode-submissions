#include<bits/stdc++.h>
class Solution {
public:
    int dp[5005][2];   //represents for this maximum profit you can make from day i onwards, given your current ownership state j (means whether you have to buy = 1 or sell means buy = 0 because cannot do both)
    int rec(int i,int buy,vector<int>& prices){
        int n= prices.size();
        if(i>=n)  //if it passes the day number then 0
        return 0;
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy) //if we have to buy
        {
            //Case 1: we skip the day
            int skip = rec(i+1,1,prices);
            //Case 2: We have to buy the present
            int take = -prices[i] + rec(i+1,0,prices);
            return dp[i][buy]=max(skip,take);
        }
        else{
            //Case 1: we skip the day
            int hold = rec(i+1,0,prices);
            //Case 2: We have to sell the present
            int sell = prices[i]+rec(i+2,1,prices);
            return dp[i][buy]=max(sell,hold);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(0,1,prices);
    }
};
