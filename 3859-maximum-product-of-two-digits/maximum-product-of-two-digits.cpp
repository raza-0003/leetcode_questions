class Solution {
public:
    int maxProduct(int n) {
        int mul = 1;
        vector<int>ans;
        while(n){
            int rem = n % 10;
            ans.push_back(rem);
            n = n / 10;
        }
        sort(ans.begin(),ans.end());
        int m = ans.size();
        return ans[m-1] * ans[m-2];
    }
};