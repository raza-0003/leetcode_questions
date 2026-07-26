class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int fMax = INT_MIN;
        int sMax = INT_MIN;
        int tMax = INT_MIN;
        int fMin = INT_MAX;
        int sMin = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > fMax){
                tMax = sMax;
                sMax = fMax;
                fMax = nums[i];
            }
            else if(nums[i] > sMax){
                tMax = sMax;
                sMax = nums[i];
            }
            else if(nums[i] > tMax){
                tMax = nums[i];
            }
            if(nums[i] < fMin){
                sMin = fMin;
                fMin = nums[i];
            }
            else if(nums[i] < sMin){
                sMin = nums[i];
            }
        }
        int a = fMax * sMax * tMax;
        int b = fMax * fMin * sMin;
        return max(a,b);

    }
};