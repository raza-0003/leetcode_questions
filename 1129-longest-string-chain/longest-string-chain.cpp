class Solution {
public:
    bool isPredecessor(const string& a, const string& b) {
    if (b.size() != a.size() + 1) return false;
    int i = 0, j = 0;
    bool skipped = false;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (skipped) return false;
            skipped = true;
            j++;
        }
    }
    return true;
}

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n==1) return 1;
        sort(words.begin(),words.end(),[](const string&a ,const string&b){
            return a.size()<b.size();
        });
        int maxi = 1;
        vector<int>dp(n,1);
        for(int index=1;index<n;index++){
            for(int prev=0;prev<index;prev++){
                if(dp[prev]+1>dp[index] && isPredecessor(words[prev],words[index])){
                    dp[index] = dp[prev]+1;
                }
            }
            maxi = max(maxi,dp[index]);
        }
        return maxi;  
    }
};