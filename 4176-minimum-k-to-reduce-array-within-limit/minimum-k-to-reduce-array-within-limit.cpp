class Solution {
public:
    long long min_steps(vector<int>& nums,int k){ 
        long long steps = 0;
        for(int idx=0;idx<nums.size();idx++){
            if(nums[idx] % k == 0){
                steps += nums[idx]/k;
            }
            else{
                steps += nums[idx] / k + 1;
            }
        }
        return steps;
        
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 1;
        int high = 200000;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long steps = min_steps(nums,mid);
            if(steps <= 1LL * mid * mid){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
            
        }
        return ans;
    }
};