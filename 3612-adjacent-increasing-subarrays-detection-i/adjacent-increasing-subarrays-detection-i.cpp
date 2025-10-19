class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prevRun = 0;
        int currRun = 1;
        int maxK = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                currRun++;
            }
            else{
                prevRun = currRun;
                currRun = 1;
            }
            maxK = max(maxK,currRun/2);
            maxK = max(maxK,min(prevRun,currRun));
            if(maxK == k) return true;
        }
        return false;
    }
};