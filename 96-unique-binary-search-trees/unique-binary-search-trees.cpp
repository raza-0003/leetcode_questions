class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        int ans = 0;
        // think i as a root node
        for(int i=1;i<=n;i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }
        return ans;
    }
};