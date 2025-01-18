class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>prev(2,0),curr(2,0);
        for(int index=n-1;index>=0;index--){ 
            int profit = 0;
                curr[1] = max(-prices[index]-fee+prev[0],0 + prev[1]);
                curr[0] = max(prices[index]+prev[1],0+prev[0]);
                prev = curr;
        }
        return prev[1];
    }
};