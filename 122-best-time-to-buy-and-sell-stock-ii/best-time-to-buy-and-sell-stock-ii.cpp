class Solution {
public:
    int f(int index,int buy,vector<int>&prices,vector<vector<int>>dp){
        int profit = 0;
        if(index == prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            profit  = max(-prices[index] + f(index+1,0,prices,dp),0 + f(index+1,1,prices,dp));
        }
        else{
            profit = max(prices[index] +f(index+1,1,prices,dp),0 + f(index+1,0,prices,dp));
        }
        return dp[index][buy] =profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                long long profit = 0;
                if(buy){
                    profit  = max(-prices[index] + dp[index+1][0],0 + dp[index+1][1]);
                }
                else{
                    profit = max(prices[index] +dp[index+1][1],0  + dp[index+1][0]);
                }
                dp[index][buy] =profit;
            }
        }
        return dp[0][1];
    }
};