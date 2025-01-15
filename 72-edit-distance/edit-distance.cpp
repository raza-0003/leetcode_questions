class Solution {
public:
    int f(int ind1,int ind2,string word1,string word2,vector<vector<int>>&dp){
            if(ind1<0) return ind2 + 1; // insert remaining character of word2
            if(ind2<0) return ind1 + 1; // delete remaining character of word1
            if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
            if(word1[ind1] == word2[ind2]){
                return dp[ind1][ind2] =  0 + f(ind1-1,ind2-1,word1,word2,dp);
            }
            return dp[ind1][ind2] =  1 + min({f(ind1-1,ind2,word1,word2,dp) // delete
                    ,f(ind1,ind2-1,word1,word2,dp)         // insert
                    ,f(ind1-1,ind2-1,word1,word2,dp)});    // replace
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n==0) return m;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};