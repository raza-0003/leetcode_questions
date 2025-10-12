class Solution {
public:
    bool isBalanced(vector<int>&freq){
        int maxFreq = 0, minFreq = INT_MAX;
        for(auto it:freq){
            if(it > 0){
                maxFreq = max(maxFreq,it);
                minFreq = min(minFreq,it);
            }
        }
        return maxFreq == minFreq;
        
    }
    int longestBalanced(string s) {
        int longestSubstr = 0;
        if(s.size() == 1) return 1;
        int n = s.size();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(isBalanced(freq)){
                    longestSubstr = max(longestSubstr,j-i+1);
                }
            }
        }
        return longestSubstr;
    }
};