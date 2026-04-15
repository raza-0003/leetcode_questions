class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            vector<string>temp;
            temp.push_back(strs[i]);
            visited[i] = 1;
            vector<int>letters(26,0);
            for(auto ch:strs[i]){
                letters[ch-'a']++;
            }
            for(int j=i+1;j<n;j++){
                if(visited[j]) continue;
                if(strs[i].size() != strs[j].size()) continue;
                vector<int>freq(26,0);
                for(auto ch:strs[j]){
                    freq[ch-'a']++;
                }
                if(freq == letters){
                    temp.push_back(strs[j]);
                    visited[j] = 1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};