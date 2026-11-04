class Solution {
public:
     int check(int mid, vector<int> &nums, int n){
        if(nums[mid] <= nums[n-1])
        return 1;
        else
        return 0;
     }
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int lo= 0;
        int hi = n-1;
        int ans =-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,nums,n)==1){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return nums[ans];
    }
};
