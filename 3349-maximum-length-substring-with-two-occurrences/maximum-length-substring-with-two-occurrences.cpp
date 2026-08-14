class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                char ch = s[j];
                if(freq[ch-'a'] < 2){
                    freq[ch-'a']++;
                    maxi = max(maxi,j-i+1);
                }
                else if(freq[ch-'a'] >= 2){
                    break;
                }
            }
        }
        return maxi;
    }
};