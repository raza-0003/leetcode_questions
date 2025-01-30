class Solution {
public:
    int f(int index,vector<int>&dp){
        if(index<=1) return 1;
        if(dp[index]!=-1) return dp[index];
        int ans = 0;
        // think i as a root node
        for(int i=1;i<=index;i++){
            ans += f(i-1,dp) * f(index-i,dp);
        }
        return dp[index] = ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};