class Solution {
public:
    int f(int index,vector<int>& nums,int prevInd,vector<vector<int>>&dp){
        if(index < 0) return 0;
        if(dp[index][prevInd+1]!=-1) return dp[index][prevInd+1];
        int notTake = f(index-1,nums,prevInd,dp);
        int take = 0;
        if(prevInd == -1 || nums[prevInd] > nums[index]){
            take = 1 + f(index-1,nums,index,dp);
        }
        return dp[index][prevInd+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,nums,-1,dp);
    }
};