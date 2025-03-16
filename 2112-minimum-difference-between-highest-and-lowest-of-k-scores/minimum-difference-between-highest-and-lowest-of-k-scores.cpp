class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int i=k-1;i<n;i++){
            mini = min(mini,nums[i]-nums[i-k+1]);
        }
        return mini;
        
    }
};