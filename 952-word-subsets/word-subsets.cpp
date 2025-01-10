class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // calculate the maximum frequency requred in words2
        vector<int>freq2(26,0);
        for(string word:words2){
            vector<int>tempfreq(26,0);
            for(char ch:word){
                tempfreq[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                freq2[i] = max(freq2[i],tempfreq[i]);

            }
        }
        // step2 check each word in word1
        vector<string>result;
        for(string word:words1){
            vector<int>freq1(26,0);
            for(char ch:word){
                freq1[ch-'a']++;
            }
            // check freq 1 satisfy the freq1
            bool isUniversal = true;
            for(int i=0;i<26;i++){
                if(freq1[i]<freq2[i]){
                    isUniversal = false;
                    break;
                }   
            }
            if(isUniversal){
                result.push_back(word);
            }
        }
        return result;
    }
};