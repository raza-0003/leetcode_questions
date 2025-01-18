class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>ahead(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--){
            for(int buy = 1;buy>=0;buy--){
                for(int cap = k;cap>0;cap--){
                    int profit = 0;
                    if(buy == 1){
                        profit = max(-prices[index] + ahead[0][cap],0 + ahead[1][cap]);
                    }
                    if(buy == 0){
                        profit = max(prices[index] + ahead[1][cap-1],0 + ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return  ahead[1][k];
    }
};