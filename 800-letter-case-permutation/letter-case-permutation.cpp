class Solution {
public:
    void solve(string inp,string otp,vector<string>&ans){
        if(inp.size() == 0){
            ans.push_back(otp);
            return;
        }
        char ch = inp[0];
        inp.erase(inp.begin() + 0);
        if(ch>=65 && ch <= 90){
            // its capital letter
            char newch = ch + 32;
            string otp1 = otp;
            otp1.push_back(ch);
            string otp2 = otp;
            otp2.push_back(newch);
            solve(inp,otp2,ans);
            solve(inp,otp1,ans);
        }
        else if(ch >= 97 && ch <= 122){
            char newch = ch - 32;
            string otp1 = otp;
            otp1.push_back(ch);
            string otp2 = otp;
            otp2.push_back(newch);
            solve(inp,otp2,ans);
            solve(inp,otp1,ans);
        }
        else{
            string otp1 = otp + ch;
            solve(inp,otp1,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string otp = "";
        string inp = s;
        vector<string>ans;
        solve(inp,otp,ans);
        return ans;
    }
};