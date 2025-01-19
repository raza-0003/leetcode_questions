class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--){
            for(int prevInd=index-1;prevInd>=-1;prevInd--){
                int notTake = dp[index+1][prevInd+1];
                int take = 0;
                if(prevInd ==-1 || nums[index] > nums[prevInd]){
                    take = 1 + dp[index+1][index+1];
                }
                dp[index][prevInd+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};