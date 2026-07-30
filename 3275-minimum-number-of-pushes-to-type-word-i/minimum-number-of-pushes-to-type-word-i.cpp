class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += ((i-1)/ 8) + 1;
        }
        return ans;
    }
};