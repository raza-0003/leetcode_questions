class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n<=0) return "";
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];
        int i=0;
        while(i<first.size() && i<last.size() && first[i] == last[i]){
            i++;
        }
        string ans="";
        for(int a=0;a<i;a++){
            ans += first[a];
        }
        return ans;
    }
};