class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        string s2 = "";
        for(int i=1;i<=n;i++){
            s2 += "f";
        }
        for(int i=n-1;i>=0;i--){
            s2[n-i-1]=s[i];
        }
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1] == s2[ind2-1]){
                    curr[ind2] = 1 + prev[ind2-1];
                }
                else{
                    curr[ind2] = max(prev[ind2],curr[ind2-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};