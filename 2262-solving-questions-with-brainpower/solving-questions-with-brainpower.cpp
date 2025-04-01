class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long pick = questions[i][0];
            int nextInd = i + questions[i][1] + 1;
            if(nextInd<n){
                pick += dp[nextInd];
            }
            long long notPick = dp[i+1];
            dp[i] = max(pick,notPick);
        }
        return dp[0];
        
    }
};