#include <bits/stdc++.h>
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[s.size()] = true; //base case
        for(int i=s.size()-1; i>=0; i--){
            for(const auto& w : wordDict){
       //First condition to check if there are enough characters in the string and second is to check if starting from i to word length the string match completely or not
                if((i+w.size()) <= s.size() && s.substr(i,w.size())==w) {  
                    dp[i]=dp[i+w.size()];
                }
                if(dp[i])  //if dp[i] is true then we can jump to the next iteration and break the remaining iteration of the dictionary
                break;
            }
        }
    
    return dp[0];  //will return whatever is in dp[0] at the end true or false
    }
};
