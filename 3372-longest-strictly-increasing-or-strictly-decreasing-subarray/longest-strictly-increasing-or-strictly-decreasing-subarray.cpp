class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int sinc = 1;
        int inc = 1;
        int sdec = 1;
        int dec = 1;
        // writing for strictly increasing case
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                inc++;
            }
            else{
                inc = 1;
            }
            sinc = max(inc,sinc);
        }
        // writing for strictly decreasing case
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                dec++;
            }
            else{
                dec = 1;
            }
            sdec = max(dec,sdec);
        }
        return max(sinc,sdec);

    }
};