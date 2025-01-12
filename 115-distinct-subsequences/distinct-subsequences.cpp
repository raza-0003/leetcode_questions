class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // create dp table
        vector<unsigned long long>dp(m+1,0);
        dp[0]=1;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=m;ind2>0;ind2--){
                if(s[ind1-1]== t[ind2-1]){
                    dp[ind2] += dp[ind2-1];
                    
                }
            }
        }
        return dp[m];
    }
};