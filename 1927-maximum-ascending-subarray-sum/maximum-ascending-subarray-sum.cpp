class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
            int curr_sum = nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    curr_sum += nums[j];
                }
                else{
                    break;
                }
            }
            maxSum = max(maxSum,curr_sum);
        }
        return maxSum;
    }
};