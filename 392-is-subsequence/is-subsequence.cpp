class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n>m) return false;
        if(n == m ) return s==t;
        int ls = 0;
        int tp = 0;
        while(ls < n && tp < m){
            if(s[ls] == t[tp]){
                ls++;
                tp++;
            }
            else{
                tp++;
            }
        }
        if(ls == n) return true;
        return false;


    }
};