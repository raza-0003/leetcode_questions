class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--){
            for(int buy = 1;buy>=0;buy--){
                for(int cap = k;cap>0;cap--){
                    int profit = 0;
                    if(buy == 1){
                        profit = max(-prices[index] + dp[index+1][0][cap],0 + dp[index+1][1][cap]);
                    }
                    if(buy == 0){
                        profit = max(prices[index] + dp[index+1][1][cap-1],0 + dp[index+1][0][cap]);
                    }
                    dp[index][buy][cap] = profit;
                }
            }
        }
        return  dp[0][1][k];
    }
};