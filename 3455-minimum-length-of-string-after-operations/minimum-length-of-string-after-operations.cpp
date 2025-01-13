class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int ans = 0;
        for(auto it:mpp){
            while(it.second>2){
                ans += 2;
                it.second -= 2;
            }
        }
        return n-ans;
    
        
    }
};