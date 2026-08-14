class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        vector<int>freq(26,0);
        int l = 0, r = 0;
        while(r < n){
            char ch = s[r];
            freq[ch-'a']++;
            while(freq[ch-'a'] > 2){
                freq[s[l] - 'a']--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};