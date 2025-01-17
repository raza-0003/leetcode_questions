class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(2,0),curr(2,0);
        ahead[0] = ahead[1] = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                long long profit = 0;
                if(buy){
                    profit  = max(-prices[index] + ahead[0],0 + ahead[1]);
                }
                else{
                    profit = max(prices[index] +ahead[1],0  + ahead[0]);
                }
                curr[buy] =profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};