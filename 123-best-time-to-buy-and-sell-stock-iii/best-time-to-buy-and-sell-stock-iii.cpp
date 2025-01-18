class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int index = n-1;index>=0;index--){
            for(int buy = 1;buy>=0;buy--){
                for(int trans=2;trans>0;trans--){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[index] + ahead[0][trans], 0 + ahead[1][trans]);
                    }
                    else{
                        profit = max(prices[index] + ahead[1][trans-1] , 0 + ahead[0][trans]);
                    }
                    curr[buy][trans] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};