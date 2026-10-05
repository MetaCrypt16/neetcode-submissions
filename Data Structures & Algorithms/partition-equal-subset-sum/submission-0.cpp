#include <vector>
#include <numeric>
#include <cstring>

class Solution {
public:
    // dp[level][target]: 
    // nums.size() <= 100, max target = (100 * 50) / 2 = 2500
    int dp[105][2505];

    int rec(int level, int target, const std::vector<int>& nums) {
        // Base Case 1: Target reached
        if (target == 0) return 1;

        // Base Case 2: Out of elements
        if (level == nums.size()) return 0;

        // Return memoized result
        if (dp[level][target] != -1) return dp[level][target];

        // Choice 1: Skip the current element
        int ans = rec(level + 1, target, nums);

        // Choice 2: Include the current element (only if it fits)
        if (nums[level] <= target) {
            ans = ans || rec(level + 1, target - nums[level], nums);
        }

        return dp[level][target] = ans;
    }

    bool canPartition(std::vector<int>& nums) {
        int total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }

        // An odd total sum can never be split into two equal integer halves
        if (total_sum % 2 != 0) return false;

        int target = total_sum / 2;
        std::memset(dp, -1, sizeof(dp));

        return rec(0, target, nums) == 1;
    }
};