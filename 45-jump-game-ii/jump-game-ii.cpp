class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1e9);
        dp[n-1] = 0;
        int minSteps = 1e9;
        for(int index=n-2;index>=0;index--){
             int minSteps = 1e9;
             for(int j=1;j<=nums[index] && index+j <n ;j++){ // try the all possible jumps
                if(dp[index + j] != 1e9){
                    minSteps = min(minSteps,1+ dp[index+j]);
                }
             }
             dp[index] = minSteps;

        }
        return dp[0];
        
    }
};