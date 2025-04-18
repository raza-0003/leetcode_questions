class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};