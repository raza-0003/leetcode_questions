class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n= nums.size();
        int curr_sum = nums[0];
        int max_sum  = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr_sum += nums[i];
            }
            else{
                curr_sum = nums[i];
            }
            max_sum = max(max_sum,curr_sum);
        }
        return max_sum;
    }
};