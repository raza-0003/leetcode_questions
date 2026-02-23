class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt0 = 0;
        int cnt1 = 0;
        string ans;
        for(auto it:t){
            if(it=='1') cnt1++;
            else cnt0++;
        }
        for(auto ch:s){
            if(ch == '1'){
                if(cnt0 != 0){
                    ans += '1';
                    cnt0--;
                }
                else{
                    ans += '0';
                    cnt1--;
                }
            }
            else{
                if(cnt1 != 0){
                    ans += '1'; 
                    cnt1--;
                }
                else{
                    ans += '0';
                    cnt0--;
                }
            }
        }
        return ans;
    }
};