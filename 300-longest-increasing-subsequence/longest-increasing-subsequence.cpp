class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i] > nums[prev]){
                    dp[i] = max(dp[i],dp[prev]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    
};