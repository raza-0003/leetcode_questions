class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        string s2 = "";
        for(int i=1;i<=n;i++){
            s2 += "f";
        }
        for(int i=n-1;i>=0;i--){
            s2[n-i-1]=s[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=n;i++) dp[0][i] = 0;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1] == s2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n][n];
    }
};