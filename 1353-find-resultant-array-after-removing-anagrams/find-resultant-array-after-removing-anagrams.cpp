class Solution {
public:
    bool isAnagram(string s1,string s2){
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        return freq1 == freq2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        int n = words.size();
        if(n == 1) return words;
        int left=0,right=1;
        while(right!=n){
            if(isAnagram(words[left],words[right])){
                right++;
            }
            else{
                ans.push_back(words[left]);
                left = right;
                right++;
            }
        }
        ans.push_back(words[left]);
        return ans;

    }
};