#include <bits/stdc++.h>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i] represents the minimum coins needed for the amount i
        vector<int> dp(amount+1,amount+1);  //initialize the inital value to amount +1 value
        dp[0]=0;
        for(int i= 1; i<=amount;i++){
            for(int c: coins){
                if(i-c>=0){
                    dp[i]= min(dp[i],dp[i-c]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
