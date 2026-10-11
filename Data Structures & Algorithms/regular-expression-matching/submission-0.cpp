#include <bits/stdc++.h>
class Solution {
public:
    int dp[25][25];

    int rec(int i, int j, const string& s, const string& p) {
        int m = s.length(), n = p.length();

        // Base case: pattern exhausted
        if (j == n) return i == m;

        // Return cached result
        if (dp[i][j] != -1) return dp[i][j];

        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

        // Case A: Next character is '*'
        if (j + 1 < n && p[j + 1] == '*') {
            // Option 1: skip token (j + 2)
            // Option 2: if matched, consume 1 char from s and stay at j
            return dp[i][j] = rec(i, j + 2, s, p) || 
                              (match && rec(i + 1, j, s, p));
        }

        // Case B: Next character is not '*'
        if (match) {
            return dp[i][j] = rec(i + 1, j + 1, s, p);
        }
        //Since all possible ways have failed so now it would be false
        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, s, p);
    }
};