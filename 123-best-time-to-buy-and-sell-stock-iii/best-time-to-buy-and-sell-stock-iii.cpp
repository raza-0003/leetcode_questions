class Solution {
public:
    int f(int index,int buy,vector<int>&prices,int trans,vector<vector<vector<int>>>&dp){
        // lets talk about the base cases
        if(index == prices.size() || trans == 2) return 0;
        if(dp[index][buy][trans]!=-1) return dp[index][buy][trans];
        int profit = 0;
        if(buy){
            profit = max(-prices[index] + f(index+1,0,prices,trans,dp), 0 + f(index+1,1,prices,trans,dp));
        }
        else{
            profit = max(prices[index] + f(index+1,1,prices,trans+1,dp) , 0 + f(index+1,0,prices,trans,dp));
        }
        return dp[index][buy][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,prices,0,dp);
    }
};