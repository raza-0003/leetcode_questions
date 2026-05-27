class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mpp;
        vector<int>upp_ch(26,0);
        vector<int>low_ch(26,0);
        for(auto it:word){
            if(it>='a' && it<='z'){
                low_ch[it-'a']++;
            }
            else{
                upp_ch[it-'A']++;
            }

        }
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(upp_ch[i] && low_ch[i]){
                cnt++;
            }
        }
        return cnt;
    }
};