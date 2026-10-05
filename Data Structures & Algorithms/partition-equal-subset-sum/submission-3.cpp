class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i=0;i<nums.size();i++){
             total_sum+= nums[i];
        }
        if(total_sum % 2 != 0){
            return false;
        }
        int target = total_sum/2;
        vector<bool> dp(target+1,false); //represents if this sum is possible or not
        dp[0]=true;  //sum 0 is always possible by not taking any no.
        for(int i= 0; i< nums.size();i++){
            for(int j=target; j>=nums[i];j--)   //will start from target from right to left and see what all targets can be formed 
            {
                dp[j]= dp[j] || dp[j-nums[i]];  //if the target j is possible via taking the present no. of skipping it
            }
        }
        return dp[target];
    }
};
