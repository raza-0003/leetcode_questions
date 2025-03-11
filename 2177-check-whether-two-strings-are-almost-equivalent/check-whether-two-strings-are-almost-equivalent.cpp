class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>freq1(26,0),freq2(26,0);
        for(char ch:word1){
            freq1[ch-'a']++;
        }
        for(char ch:word2){
            freq2[ch-'a']++;
        }
        bool ans = true;
        for(char ch='a';ch<='z';ch++){
            if(abs(freq1[ch-'a']-freq2[ch-'a'])>3){
                ans = false;
                break;
            }
        }
        return ans;

    }
};