class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c, int n, int m) {
        if (dp[r][c] != -1)
            return dp[r][c];

        int res = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Only visit neighbors that are strictly valid
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] > matrix[r][c]) {
                res = max(res, 1 + dfs(matrix, nr, nc, n, m));
            }
        }

        return dp[r][c] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        int LIP = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                LIP = max(LIP, dfs(matrix, r, c, n, m));
            }
        }
        return LIP;
    }
};