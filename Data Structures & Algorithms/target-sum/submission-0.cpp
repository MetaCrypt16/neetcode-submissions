#include<bits/stdc++.h>
class Solution {
public:
    //Max sum that reach is 20*1000=20000 but in c++ array indices cannot be negative so Need to add offset of 40000 since the range is [-20000,20000]
    int dp[25][40005];  //representing the no. of ways to reach the target j from level to n-1
    const int OFFSET = 20000; //offset to compensate the negative indices
    int rec(int level,int target,vector<int>& nums){
        if (level == nums.size()) {
            return target == 0 ? 1 : 0;  //cannot stop early even if the target is 0 as need to traverse the whole array
         }
        if (target < -20000 || target > 20000) return 0;
        if(dp[level][target+OFFSET]!=-1){
            return dp[level][target+OFFSET];
        }
        int ans = rec(level+1,target+nums[level],nums);   //Case 1 if substracting the current no..
        //Case 2 if adding the sum means the target value is decreased
        ans += rec(level+1,target-nums[level],nums);

        return dp[level][target+OFFSET] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);  
        if (abs(target) > totalSum) return 0;  //can avoid recursion if abs target is much greater than the total sum of numbers
        memset(dp,-1,sizeof(dp));
        return rec(0,target,nums);
    }
};
