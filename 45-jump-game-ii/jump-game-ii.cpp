class Solution {
public:
    int f(int index,vector<int>& nums,vector<int>&dp){
        if(index >= nums.size()-1) return 0;
        if(dp[index]!=-1) return dp[index];
        int minSteps = 1e9;
        for(int j=1;j<=nums[index];j++){ // try the all possible jumps
            int jump = f(index+j,nums,dp);
            if(jump != 1e9){
                minSteps = min(minSteps,1+jump);
            }

        }
        return dp[index] = minSteps;

    }
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,-1);
       return f(0,nums,dp);
        
    }
};