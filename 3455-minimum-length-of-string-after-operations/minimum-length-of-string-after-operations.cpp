class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            while(freq[i]>2){
                ans += 2;
                freq[i] -= 2;
            }
        }
        return n-ans;
    }
};