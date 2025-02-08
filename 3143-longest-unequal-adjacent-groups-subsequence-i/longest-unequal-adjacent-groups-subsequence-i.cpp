class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int flag = -1;
        for(int i=0;i<words.size();i++){
            if(groups[i] != flag){
                flag = groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};