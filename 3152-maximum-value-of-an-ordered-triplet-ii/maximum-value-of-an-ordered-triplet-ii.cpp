class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long max_val = 0;
        int maxi = nums[0];
        vector<int>max_suffix(n,0);
        max_suffix[n-1] = nums[n-1];
        // computing suffix max array
        for(int i=n-2;i>=0;i--){
            max_suffix[i] = max(max_suffix[i+1],nums[i]);
        }
        // computing maximum triplet value;
        for(int j=1;j<n-1;j++){
            max_val = max(max_val,(long long)(maxi-nums[j]) * max_suffix[j+1]);
            maxi = max(maxi,nums[j]);
        }
        return max_val;
    }
};