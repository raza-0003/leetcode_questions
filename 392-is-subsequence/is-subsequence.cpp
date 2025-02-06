class Solution {
public:
    bool f(int inds,int indt,string s, string t){
        bool ans = false;
        if(inds == s.size()){
            return  true;
        }
        if(indt >= t.size()) return false;
        if(s[inds] == t[indt]){
            ans =  f(inds+1,indt+1,s,t);
        }
        else{
            ans = f(inds,indt+1,s,t);
        }
        return ans;

    }
    bool isSubsequence(string s, string t) {
        return f(0,0,s,t);
    }
};