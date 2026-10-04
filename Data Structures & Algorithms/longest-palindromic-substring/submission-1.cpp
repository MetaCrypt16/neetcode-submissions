#include <cstring>
class Solution {
public:
    int dp1[1001][1001]; //stores if this is a plaindrome starting from l and ending at r
    int rec1(int l, int r,const string&s) //to check the palindromes
    {
        if(l>=r)
        return 1;
        if(dp1[l][r]!=-1)
        return dp1[l][r];

        int ans = 0;
        if(s[l]==s[r] && rec1(l+1,r-1,s)) //if l to r is a plaindrome then l+1 to r-1 should also be a palindrome
        ans = 1;
        return dp1[l][r]=ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        memset(dp1, -1, sizeof(dp1));

        int bestStart = 0;
        int maxLen = 1;

        // Iterate over all possible substrings
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (rec1(i, j, s)) {
                    int currentLen = j - i + 1;
                    if (currentLen > maxLen) {
                        maxLen = currentLen;
                        bestStart = i;
                    }
                }
            }
        }

        return s.substr(bestStart, maxLen);  //0 indexing represents the start of the substring and max length represents the no. of characters to copy
    }
};
