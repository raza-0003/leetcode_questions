class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prev1(2,0),prev2(2,0),curr(2,0);
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy==1){
                    profit = max(-prices[index] + prev1[0],0 + prev1[1]);
                }
                else{
                    profit = max(prices[index] + prev2[1],0 + prev1[0]);
                }
                curr[buy] = profit;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[1];
    }
};