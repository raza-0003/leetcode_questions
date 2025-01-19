class Solution {
public:
    int f(int index,int p_index,vector<int>&nums,vector<vector<int>>&dp){
        if(index == nums.size()) return 0;
        if(dp[index][p_index+1]!=-1) return dp[index][p_index+1];
        int notTake = 0 + f(index+1,p_index,nums,dp);
        int take = 0;
        if(p_index==-1 || nums[index]>nums[p_index]){
            take = 1 + f(index+1,index,nums,dp);
        }
        return dp[index][p_index+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp); 
    }
};