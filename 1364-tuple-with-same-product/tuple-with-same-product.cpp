class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<4) return 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product = nums[i] * nums[j];
                mpp[product]++;
            }
        }
        int ans = 0;
        for(auto it:mpp){
            int cnt = it.second;
            if(cnt > 1){
                ans += 4 * cnt * (cnt - 1);
            }
        }
        return ans;
    }
};