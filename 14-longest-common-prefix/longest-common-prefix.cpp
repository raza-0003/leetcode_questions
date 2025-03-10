class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n<=0) return "";
        // alhabatically string ko sort akar diya
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];
        int i=0;
        // comparing first and the last element of the array of the string
        while(i<first.size() && i<last.size() && first[i] == last[i]){
            i++;
        }

        string ans="";
        for(int a=0;a<i;a++){
            ans += last[a];
        }
        return ans;
    }
};