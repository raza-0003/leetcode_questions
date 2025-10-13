class Solution {
public:
    bool isAnagram(string s1,string s2){
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
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