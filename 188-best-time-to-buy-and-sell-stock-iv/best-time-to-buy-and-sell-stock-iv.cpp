class Solution {
public:
    int f(int index,int buy,vector<int>prices,int cap,vector<vector<vector<int>>>&dp){
        if(index == prices.size() || cap == 0){
            return 0;
        }
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        int profit = 0;
        if(buy == 1){
            profit = max(-prices[index]+f(index+1,0,prices,cap,dp),0 + f(index+1,1,prices,cap,dp));
        }
        if(buy == 0){
            profit = max(prices[index] + f(index+1,1,prices,cap-1,dp),0 + f(index+1,0,prices,cap,dp));
        }
        return dp[index][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return  f(0,1,prices,k,dp);
    }
};