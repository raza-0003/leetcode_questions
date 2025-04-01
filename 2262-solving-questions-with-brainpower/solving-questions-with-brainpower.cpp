class Solution {
public:
    long long maxi(vector<vector<int>>& questions,int ind,vector<long long>&dp){
        // writing down the base case
        if(ind >= questions.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        // not picking the element 
        long long  notPick = maxi(questions,ind+1,dp);
        long long pick = questions[ind][0] + maxi(questions,ind+questions[ind][1]+1,dp); 
        return dp[ind] = max(pick,notPick);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        long long maxSum = maxi(questions,0,dp);
        return maxSum;
        
    }
};