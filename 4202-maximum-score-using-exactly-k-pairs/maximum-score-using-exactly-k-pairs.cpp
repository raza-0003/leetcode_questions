class Solution {
public:
    long long dp[101][101][101];
    long long INF = 1e18;
    long long REC(vector<int>& nums1, vector<int>& nums2,int n,int m,int k){
        if(k == 0){
            return 0;
        }
        if (k > min(n, m)) return -INF;
        if(n==0 || m == 0){
            return -INF;
        }
        if(dp[n][m][k] != -1){
            return dp[n][m][k];
        }
        long long take = 1LL*nums1[n-1]*nums2[m-1] + REC(nums1,nums2,n-1,m-1,k-1);
        long long notTake = max(REC(nums1,nums2,n-1,m,k),REC(nums1,nums2,n,m-1,k));
        return dp[n][m][k] = max(take,notTake);
        
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp, -1, sizeof(dp));
        if (k == 1) {
            long long ans = LLONG_MIN;
            for (int i = 0; i < nums1.size(); i++) {
                for (int j = 0; j < nums2.size(); j++) {
                    ans = max(ans, nums1[i] * 1LL * nums2[j]);
                }
            }
            return ans;
        }
        long long max_score = REC(nums1,nums2,n,m,k);
        return max_score;       
    }
};