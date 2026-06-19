class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int st = 0;
        int n = gain.size();
        for(int i=0;i<n;i++){
            int nxt = gain[i] + st;
            ans = max(ans,nxt);
            st = nxt;
        }
        return ans;
    }
};