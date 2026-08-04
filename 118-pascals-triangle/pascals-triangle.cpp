class Solution {
public:
    int pascal(int i,int j,vector<vector<int>>&dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(j == 0 || j == i){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = pascal(i-1,j,dp) + pascal(i-1,j-1,dp);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<vector<int>>dp(numRows,vector<int>(numRows,-1));
        for(int i=0;i<numRows;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                int pasi = pascal(i,j,dp);
                temp.push_back(pasi);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};