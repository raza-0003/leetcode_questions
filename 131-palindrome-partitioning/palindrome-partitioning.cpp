class Solution {
public:
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    void f(string s,int ind,vector<string>&path,vector<vector<string>>&res){
        if(ind == s.size()){
            res.push_back(path);
            return;
        } 
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(ind,i,s)){
                path.push_back(s.substr(ind,i-ind+1));
                f(s,i+1,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>res;
        vector<string>path;
        f(s,0,path,res);
        return res;
    }
};