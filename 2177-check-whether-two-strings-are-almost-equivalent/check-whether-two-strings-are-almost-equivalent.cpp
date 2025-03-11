class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size();
        unordered_map<char,int>freq1;
        for(auto it:word1){
            freq1[it]++;
        }
        unordered_map<char,int>freq2;
        for(auto it:word2){
            freq2[it]++;
        }
        bool ans = true;
        for(char ch='a';ch<='z';ch++){
            if(abs(freq1[ch]-freq2[ch]) > 3){
                ans=false;
                break;
            }
        }
        return ans;

    }
};