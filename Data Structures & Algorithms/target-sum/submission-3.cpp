#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[level] maps: target -> number of ways
    unordered_map<int, int> dp[25];

    int rec(int level, int target, const vector<int>& nums) {
        if (level == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        // Check if (level, target) is already memoized
        if (dp[level].count(target)) {
            return dp[level][target];
        }

        int subtract_op = rec(level + 1, target + nums[level], nums);
        int add_op      = rec(level + 1, target - nums[level], nums);

        return dp[level][target] = subtract_op + add_op;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum) return 0;

        for (int i = 0; i < 25; ++i) dp[i].clear();

        return rec(0, target, nums);
    }
};