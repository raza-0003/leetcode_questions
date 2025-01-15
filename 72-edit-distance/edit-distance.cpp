class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    dp[ind1][ind2] =  0 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] =  1 + min({dp[ind1-1][ind2]// delete
                                        ,dp[ind1][ind2-1]         // insert
                                        ,dp[ind1-1][ind2-1]});    // replace
                }
            }
        }

        return dp[n][m];
    }
};