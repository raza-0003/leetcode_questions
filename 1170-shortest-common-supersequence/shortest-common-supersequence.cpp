class Solution {
public:
    int f(int ind1,int ind2,string str1, string str2,vector<vector<int>>&dp){
        if(ind1==0 || ind2==0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(str1[ind1-1]==str2[ind2-1]){
            return  dp[ind1][ind2]=  1 + f(ind1-1,ind2-1,str1,str2,dp);
        }
        else{
            return  dp[ind1][ind2] = 0 + max(f(ind1-1,ind2,str1,str2,dp),f(ind1,ind2-1,str1,str2,dp));
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        f(n,m,str1,str2,dp);
        int len = dp[n][m];
        int i = n;
        int j = m;
        int index = len-1;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans += str2[j-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }
        // Adding the remaining characters from string1 and string 2
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};