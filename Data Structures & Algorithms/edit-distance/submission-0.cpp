#include<bits/stdc++.h>
class Solution {
public:
    int dp[105][105];
    int rec(int i,int j, const string& word1, const string& word2){
             int n= word1.size();
             int m = word2.size();
             if(i==n)
             return m-j;  //insert the extra characters of word 2
             if(j==m)
             return n-i;  //delete remaining characters of word 1

            if(dp[i][j]!=-1)
            return dp[i][j];
             int ans = 1e9;

             if(word1[i]==word2[j])
             ans = rec(i+1,j+1,word1,word2); //no operation needed
            else{
               // Option 1: Insert into word1 (match word2[j] and advance j)
               int insert_op = 1 + rec(i, j + 1,word1,word2);

               // Option 2: Delete from word1 (advance i)
               int delete_op = 1 + rec(i + 1, j,word1,word2);

               // Option 3: Replace word1[i] with word2[j] (advance both)
               int replace_op = 1 + rec(i + 1, j + 1,word1,word2);

               ans = min({insert_op, delete_op, replace_op});
            }
            return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,word1,word2);
    }
};
