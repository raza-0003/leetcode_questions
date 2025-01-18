class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index = n-1;index>=0;index--){
            for(int buy = 1;buy>=0;buy--){
                for(int trans=2;trans>0;trans--){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[index] + dp[index+1][0][trans], 0 + dp[index+1][1][trans]);
                    }
                    else{
                        profit = max(prices[index] + dp[index+1][1][trans-1] , 0 + dp[index+1][0][trans]);
                    }
                    dp[index][buy][trans] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};