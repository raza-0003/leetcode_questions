class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int maxi = 0;
        for(auto it:mpp){
            if((it.second)%2 == 1){
                maxi++;
            }
        }
        if(k>s.length()) return false;
        return (k>=maxi);
    }
};