class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int fMax = INT_MIN;
        int sMax = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] > fMax){
                sMax = fMax;
                fMax =nums[i];
            }
            else if(nums[i] > sMax){
                sMax = nums[i];
            }
        }
        return (fMax - 1) * (sMax - 1);
    }
};