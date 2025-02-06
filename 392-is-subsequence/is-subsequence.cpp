class Solution {
public:
    bool f(int inds,int indt,string s, string t,vector<vector<int>> &dp){
        if(inds == s.size()){
            return  true;
        }
        if(indt == t.size()) return false;
        if(dp[inds][indt]!=-1) return dp[inds][indt];
        if(s[inds] == t[indt]){
            return dp[inds][indt] =  f(inds+1,indt+1,s,t,dp);
        }
        return dp[inds][indt] = f(inds,indt+1,s,t,dp);

    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        return f(0,0,s,t,dp);
    }
};