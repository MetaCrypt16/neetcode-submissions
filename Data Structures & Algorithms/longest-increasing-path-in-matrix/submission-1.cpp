class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},
                                        {0,-1},{0,1}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int r, int c, int prevVal){
        int n = matrix.size(), m = matrix[0].size();
        if(r<0 || r>=n || c<0 || c>=m || matrix[r][c] <= prevVal)
        return 0;

        if(dp[r][c]!=-1)
        return dp[r][c];

        int res = 1;
        for(vector<int> d: directions){
            res = max(res,1+dfs(matrix,r+d[0],c+d[1],matrix[r][c]));
        }
        dp[r][c]=res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        int LIP = 0;
        for(int r=0;r<n;r++){
            for(int c= 0;c<m;c++){
                LIP = max(LIP,dfs(matrix,r,c,INT_MIN));
            }
        }
        return LIP;
        
    }
};
