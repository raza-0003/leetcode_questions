class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy == 1){
                    profit = max(-prices[index]-fee+dp[index+1][0],0 + dp[index+1][1]);
                }
                if(buy == 0){
                    profit = max(prices[index]+dp[index+1][1],0+dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};