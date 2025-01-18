class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>prev(2,0),curr(2,0);
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy == 1){
                    profit = max(-prices[index]-fee+prev[0],0 + prev[1]);
                }
                if(buy == 0){
                    profit = max(prices[index]+prev[1],0+prev[0]);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};